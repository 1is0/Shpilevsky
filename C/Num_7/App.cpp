#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include "MainStructures.h"
#include "Files.h"
#include "Menu.h"

int main()
{
	List list;
	Init(&list);

	FILE* file;
	file = fopen("Data.bin", "rb+");

	GetData(&list, file);
	
	while (EntryMenu(&list));

	FromListToFile(&list,file);

	fclose(file);
	Clear(&list);
}