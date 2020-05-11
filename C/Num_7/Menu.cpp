//-----------menu--------------
#include "Menu.h"
void CheckBalance(ListItem* item)
{
	printf("%d$ on your account", item->client.Money);
	puts("Enter sth to continue...");
	char ch = _getch();
}

void TransferMoney(List* list, ListItem* current)
{
	puts("Enter users login: ");
	char login[20];
	gets_s(login);

	ListItem* temp = list->start;
	while (strcmp(temp->client.Login, login))
	{
		temp = temp->next;
		if (!temp)
		{
			break;
		}
	}

	if (temp)
	{
		puts("Enter amount of money you'd like to transfer: ");
		int money;
		scanf("%d", &money);
		if (money > current->client.Money)
		{
			puts("Insufficient funds");
			puts("Press sth to continue...");
			char ch = _getch();
		}

		else
		{
			temp->client.Money += money;
			current->client.Money -= money;

			char* CurFileName = (char*)calloc((strlen(current->client.Login) + 12), sizeof(char));
			char* AdrFileName = (char*)calloc((strlen(temp->client.Login) + 12), sizeof(char));

			char* Message1 = (char*)calloc(strlen(temp->client.Login) + 25, sizeof(char));
			strcat(Message1, "-");
			strcat(Message1, " Transferred ");
			char buffer[5];
			strcat(Message1, _itoa(money, buffer, 10));
			strcat(Message1, "$ to ");
			strcat(Message1, temp->client.Login);

			char* Message2 = (char*)calloc(strlen(current->client.Login) + 20, sizeof(char));
			strcat(Message2, "-");
			strcat(Message2, " Got ");
			char buf[5];
			strcat(Message2, _itoa(money, buf, 10));
			strcat(Message2, "$ from ");
			strcat(Message2, current->client.Login);

			strcat(CurFileName, current->client.Login);
			strcat(CurFileName, "History.bin\0");

			strcat(AdrFileName, temp->client.Login);
			strcat(AdrFileName, "History.bin\0");

			FILE* CurFile = fopen(CurFileName, "ab");
			FILE* AdrFile = fopen(AdrFileName, "ab");

			for (int i = 0; i < strlen(Message1); i++)
			{
				fwrite(&Message1[i], sizeof(char), 1, CurFile);
			}
			for (int i = 0; i < strlen(Message2); i++)
			{
				fwrite(&Message2[i], sizeof(char), 1, AdrFile);
			}


			fclose(CurFile);
			free(CurFileName);
			free(AdrFileName);
			free(Message1);
			free(Message2);
			fclose(AdrFile);
		}
	}
	else
	{
		puts("No such users");
		puts("\nPress sth to continue...");
		char ch = _getch();
	}

}

int UserMenu(ListItem* item, List* list)
{
	system("cls");

	puts("1 - Check balance");
	puts("2 - Check history");
	puts("3 - Transfer money");
	puts("4 - Exit");
	char sel = _getch();
	switch (sel)
	{
	case '1':
		CheckBalance(item);
		break;
	case '2':
		ReadHistory(item);
		break;
	case '3': TransferMoney(list, item);
		break;
	case '4':
		puts("Are you sure you want to go out? (y/n)");
		if (_getch() == 'y' || _getch() == 'Y')
		{
			return 0;
		}
		else
		{
			break;
		}
		break;
	}

	return 1;
}

int EntryMenu(List* list)
{
	if (list->start)
	{
		puts("1 - Log into existing account");
		puts("2 - Create new account");
		puts("\nPress sth to exit...");
		ListItem* temp;
		char ch = _getch();
		switch (ch)
		{
		case '1':
			temp = FindUser(list);
			if (temp)
			{
				while (UserMenu(temp, list));
			}
			else
			{
				puts("Wrong login or password");
			}
			break;
		case '2':
			Client cl = CreateAcc();
			Add(list, cl);
			break;
		case '3':
			PrintList(list);
			break;

		default:
			return 0;
			break;
		}
	}
	else
	{
		puts("Please create account");
		Client cl = CreateAcc();
		Add(list, cl);
	}

	puts("Press sth to continue...");
	char ch = _getch();
	system("cls");
	return 1;
}