//---------------------------------------------------------------------------

#ifndef ListH
#define ListH

template <typename T>
class List
{
public:

	int GetSize() { return Size; }

	void clear();
	//void push_front(T data);
	void push_back(T data);
//	void pop_front();
	void pop_back();

//	void insert(T data, int index);
//	void removeAt(int index);

	T & operator [] (const int index);
        T Peek(int index);

	List <T>();
	~List <T>();

private:

	template <typename K>
	class Node
	{
	public:
		Node (K data = K(), Node *pNext = nullptr, Node *pPrev = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
			this->pPrev = pPrev;

		}

		K data;

		Node *pNext;
		Node *pPrev;
	};

	Node <T> *head;
	Node <T> *tail;
	int Size;
};
//---------------------------------------------------------------------------
#endif
