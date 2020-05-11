#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Client
{
	char Login[20];
	char Password[15];
	int Money;
};

struct ListItem
{
	Client client;
	ListItem* next;
	ListItem* prev;
};

struct List
{
	ListItem* start;
	ListItem* end;
};



void Init(List* list);
void Add(List* list, Client a);
void Clear(List* list);
Client CreateAcc();
void PrintList(List* list);
ListItem* FindUser(List* list);
