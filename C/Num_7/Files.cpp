#include "Files.h"

int FileSize(FILE* f)
{
	int count = 0;
	char tmp;
	fseek(f, SEEK_SET, 0);
	while (!feof(f))
	{
		fread(&tmp, sizeof(char), 1, f);
		count++;
	}
	return count - 1;
}

void PrintFile(FILE* f)
{
	fseek(f, SEEK_SET, 0);
	for (int i = 0; !feof(f); i++)
	{
		Client x;
		if (!fread(&x, sizeof(x), 1, f))
		{
			break;
		}

		printf("%d\n", x.Money);
		puts("--------------");
	}
}

void GetData(List* list, FILE* file)
{
	fseek(file, SEEK_SET, 0);
	for (int i = 0; !feof(file); i++)
	{
		Client temp;
		if (!fread(&temp, sizeof(Client), 1, file))
		{
			break;
		}
		Add(list, temp);
	}

}

void FromListToFile(List* list, FILE* file)
{
	fclose(file);

	file = fopen("Data.bin", "wb");
	fclose(file);
	
	file = fopen("Data.bin", "ab+");
	fseek(file, SEEK_SET, 0);

	ListItem* temp = list->start;
	while (temp)
	{
		Client cl = temp->client;
		fwrite(&cl, sizeof(Client), 1, file);
		temp = temp->next;
	}

	fclose(file);
}

void ReadHistory(ListItem* current)
{
	char* CurFileName = (char*)calloc((strlen(current->client.Login) + 12),sizeof(char));

	strcat(CurFileName, current->client.Login);
	strcat(CurFileName, "History.bin\0");

	FILE* CurFile = fopen(CurFileName, "rb");
	if (!CurFile)
	{
		puts("No transfers have been made.");
		puts("\nEnter sth to continue...");
		char c = _getch();
		return;
	}

	fseek(CurFile, SEEK_SET, 0);
	for (int i = 0; !feof(CurFile); i++)
	{
		char c;
		if (!fread(&c, sizeof(char), 1, CurFile))
		{
			break;
		}
		if (c == '-')
		{
			printf("\n");
		}
		
		printf("%c", c);
		
	}

	fclose(CurFile);
	free(CurFileName);
	puts("\nEnter sth to continue...");
	char c = _getch();
}