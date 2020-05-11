#include "MainStructures.h"

void Init(List* lst)
{
	lst->start = NULL;
	lst->end = NULL;
}

int RepeatCheck(char login[20], List* list)
{
	ListItem* temp = list->start;
	while (temp)
	{
		if (strcmp(login, temp->client.Login))
		{
			temp = temp->next;
		}
		else
		{
			return 0;
		}
	}

	return 1;
}

void Add(List* list, Client a)
{
	if (RepeatCheck(a.Login, list))
	{
		ListItem* temp = (ListItem*)malloc(sizeof(ListItem));
		temp->next = NULL;
		temp->prev = list->end;
		temp->client = a;

		if (!list->start)
		{
			list->start = temp;
		}
		else
		{
			list->end->next = temp;
		}

		list->end = temp;
	}

	else
	{
		puts("This login is already taken.");
	}
}

void Clear(List* list)
{
	ListItem* li = list->start;
	ListItem* temp;
	while (li)
	{
		temp = li;
		li = li->next;
		free(temp);
	}

	list->start = NULL;
	list->end = NULL;
}

Client CreateAcc()
{
	char password[15];
	char login[20];

	puts("Enter login: ");
	gets_s(login);
	if (!strcmp(login,""))
	{
		gets_s(login);
	}

	puts("Enter new password");
	gets_s(password);

	Client client;

	memcpy(client.Login, login, 20);
	memcpy(client.Password, password, 15);
	client.Money = 100;

	return client;
}

void PrintList(List* list)
{
	ListItem* temp = list->start;
	while (temp)
	{
		printf("User: %s\n", temp->client.Login);
		printf("Money: %d\n", temp->client.Money);
		temp = temp->next;
	}
}

ListItem* FindUser(List* list)
{
	puts("Enter login: ");
	char login[20];
	gets_s(login);
	if (!strcmp(login, ""))
	{
		gets_s(login);
	}
	
	puts("Enter password: ");
	char password[15];
	gets_s(password);
	if (!strcmp(password, ""))
	{
		gets_s(password);
	}

	ListItem* temp = list->start;
	while ((strcmp(login, temp->client.Login)!=0 || strcmp(password, temp->client.Password)!=0) && temp)
	{
		temp = temp->next;
		if (!temp)
		{
			break;
		}
	}

	if (temp)
	{
		return temp;
	}
	else
	{
		return NULL;
	}
}