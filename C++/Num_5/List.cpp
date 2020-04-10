//---------------------------------------------------------------------------

#pragma hdrstop

#include "List.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

template <typename T>
List<T>::List()
{
	Size = 0;
	head = nullptr;
        tail = nullptr;

}

template <typename T> List <T>::~List()
{
	clear();
}

template<typename T>
void List<T>::clear()
{
	while (Size)
	{
		pop_back();
	}
}

/*template <typename T>
void List <T>::push_front(T data)
{
	if (Size > 1)
	{
		Node <T> *temp = head;
		head = new Node <T>(data, head,nullptr);
		temp->pPrev = head;
	}
	else if (Size == 1)
	{
		head = new Node <T>(data, head,nullptr);
		tail->pPrev = this->head;
	}
	else
	{
		head = tail = new Node <T>(data, head, tail);
	}
	Size++;
}
      */
template <typename T>
void List <T>::push_back(T data)
{
	if (Size > 1)
	{
		Node <T> *temp = tail;
		tail = new Node <T>(data, head, tail);
		temp->pNext = tail;
	}
	else if (Size == 1)
	{
		tail = new Node <T>(data, head, tail);
		head->pNext = this->tail;
	}
	else
	{
		head = tail = new Node <T>(data, head, tail);
	}

	Size++;
}
 /*
template <typename T>
void List <T>::pop_front()
{
	if (Size > 1)
	{
		Node <T> *temp = head;
		head = head->pNext;
		delete temp;
	}
	else if (Size == 1)
	{
		Node <T> *temp = head;
		tail = head = head->pNext;
		delete temp;
	}

	Size--;
}     */

template <typename T>
void List <T>::pop_back()
{
	if (Size > 1)
	{
		Node <T> *temp = tail;
		tail = tail->pPrev;
		delete temp;
	}
	else if (Size == 1)
	{
		Node <T> *temp = tail;
		tail = head = tail->pPrev;
		delete temp;
	}

	Size--;
}

/*template <typename T>
void List <T>::insert(T data, int index)
{
	if (index == 0) push_front(data);

	else if (index == Size || index > Size) push_back(data); // if index > size. then push_back()

	else if (index <= Size / 2)
	{
		Node<T> *previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}

		Node<T> *newNode = new Node<T>(data, previous->pNext, previous);

		previous->pNext = newNode;
		Node<T> *next = newNode->pNext;
		next->pPrev = newNode;

		Size++;
	}

	else if (index > Size / 2)
	{
		Node<T> *next = this->tail;
		for (int i = Size - 1; index < i; i--)
		{
			next = next->pPrev;
		}

		Node<T> *newNode = new Node<T>(data, next, next->pPrev);

		next->pPrev = newNode;
		Node<T> *previous = newNode->pPrev;
		previous->pNext = newNode;

		Size++;
	}
}

template <typename T>
void List <T>::removeAt(int index)
{
	if (index == 0) pop_front();

	else if (index == Size || index > Size) pop_back();


	else if (index <= Size / 2)
	{
		Node<T> *previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}

		Node<T> *toDelete = previous->pNext;
		previous->pNext = toDelete->pNext;
		Node<T> *next = toDelete->pNext;
		delete toDelete;
		next->pPrev = previous;

		Size--;
	}

	else if (index > Size / 2)
	{
		Node<T> *next = this->tail;
		for (int i = Size - 1; index < i; i--)
		{
			next = next->pPrev;
		}

		Node<T> *toDelete = next->pPrev;
		next->pPrev = toDelete->pPrev;
		Node<T> *previous = toDelete->pPrev;
		delete toDelete;
		previous->pNext = next;

		Size--;
	}
}             */

template <typename T>
T & List <T>::operator[] (const int index)
{
       /*	if (index <= Size / 2)
	{*/
		int counter = 0;
		Node <T> *current = this->head;

		while (current != nullptr)
		{
			if (counter == index)
			return current->data;

			current = current->pNext;
			counter++;
		}
	//}


       /*	else
	{
		int counter = Size - 1;
		Node <T> *current = this->tail;

		while (current != nullptr)
		{
			if (counter == index) return current->data;
			current = current->pPrev;
			counter--;
		}
	}*/
}

template <typename T>
T List<T>::Peek(int index)
{

		int counter = 0;
		Node <T> *current = this->head;

		while (current != nullptr)
		{
			if (counter == index)
			return current->data;

			current = current->pNext;
			counter++;
		}
		/*while (current != nullptr)
		{
			if (counter == index)
			return current->data;

			current = current->pNext;
			counter++;
		}  */
}