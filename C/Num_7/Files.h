#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "MainStructures.h"
#include <conio.h>

int FileSize(FILE* f);
void PrintFile(FILE* f);
void GetData(List* list, FILE* file);
void FromListToFile(List* list, FILE* file);
void ReadHistory(ListItem* item);
