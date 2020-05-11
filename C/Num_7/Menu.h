#pragma once
#include "MainStructures.h"
#include "Files.h"

void CheckBalance(ListItem* item);
void TransferMoney(List* list, ListItem* current);
int UserMenu(ListItem* item, List* list);
int EntryMenu(List* list);
