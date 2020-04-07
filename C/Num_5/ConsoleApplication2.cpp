#include <stdlib.h>
#include <stdio.h>

int check()
{
	int a;
	while (!scanf("%d", &a) || a <= 0)
	{

		printf("Incorrect input, repeat: ");
		rewind(stdin);
	}

	return a;
}

struct Order
{
	int number;
	char mark; //'A', 'D'
	char data;
};

void ShowOrder(Order);

void GetInfo(Order*);

//////////////////////////////////////////////

struct QueueItem
{
	char c;
	QueueItem* next;
};

//////////////////////////////////////////////

struct Queue
{

	QueueItem* first;
	QueueItem* last;
};

void Create(Queue* q)
{
	q->first = new QueueItem;
	q->first->next = nullptr;
	q->last = q->first;

}

Queue CreateQueue()
{
	Queue Q;
	Create(&Q);

	int n;
	printf("\nAmount of elements in queue: ");
	n = check();
	for (int i = 0; i < n; i++)
	{
		Add(&Q);
	}

	return Q;
}


char GetTop(Queue* q)
{
	return q->first->next->c;
}

void DeleteItem(Queue* q)
{
	QueueItem* temp = q->first;
	q->first = q->first->next;
	free(temp);
}


void Add(Queue* q)
{
	char c;
	printf("Value  = ");
	scanf("%c", &c);
	scanf("%c", &c);
	q->last -> next = new QueueItem;
	q->last = q->last->next;
	q->last->c = c;
	q->last->next = nullptr;
}

void AddChar(Queue* q, char c)
{

	q->last->next = new QueueItem;
	q->last = q->last->next;
	q->last->c = c;
	q->last->next = nullptr;
}

//////////////////////////////////////////////

struct ListItem
{
	ListItem* prev;
	ListItem* next;

	Order data;
};

struct List
{
	ListItem* start;
	ListItem* end;
};

void Init(List* list);
void Add(List* lit, Order info);
void PrintList(List* list);
void ChangeQueue(List*, Queue*);

int main()
{
	int n;
	printf("Enter amount of queues: ");
	n = check();
	
	Queue* Q = (Queue*)malloc(n*sizeof(Queue));

	List L;
	Order info;

	Init(&L);

	for (int i = 0; i < n; i++)
	{
		Q[i] = CreateQueue();
		info.number = i;
		GetInfo(&info);
		Add(&L, info);
	}

	ChangeQueue(&L, Q);

	PrintList(&L);

	for (int i = 0; i < n; i++)
	{
		printf("%c",GetTop(&Q[i]));
	}

	free(Q);
}

void ChangeQueue(List* list, Queue* queue)
{
	ListItem* li = list->start;
	int i = 0;
	while (li)
	{
		if (li->data.mark == 'A')
		{
			AddChar(&queue[i], li->data.data);
		}

		else
		{
			DeleteItem(&queue[i]);
		}
		i++;
		li = li->next;
	}
}

void GetInfo(Order* info)
{
	printf("Enter mark(A - add, D - del): ");
	char c;
	scanf("%c", &c);
	scanf("%c", &c);

	while (c != 'A' && c != 'D')
	{
		rewind(stdin);
		printf("Incorrect input, repeat: ");
		scanf("%c", &c);
	}

	char symb = '\0';
	if (c == 'A')
	{
		printf("Enter element: ");
	    scanf("%c", &symb);
		scanf("%c", &symb);
	}

	info->data = symb;
	info->mark = c;
}

void Init(List* list)
{
	list->start = nullptr;
	list->end = nullptr;
}

void  Add(List* list, Order info)
{
	struct ListItem* temp = (ListItem*)malloc(sizeof(ListItem));

	temp->next = nullptr;
	temp->prev = list->end;
	temp->data = info;

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

void ShowOrder(Order info)
{
	printf("Data - %c, Mark - %c, Number - %d\n", info.data, info.mark, info.number);
}

void PrintList(List* list)
{

	ListItem* li = list->start;
	while (li)
	{
		ShowOrder(li->data);
		li = li->next;
	}
}