//---------------------------------------------------------------------------

#ifndef HashMapH
#define HashMapH
//---------------------------------------------------------------------------
#endif


class HashNode
{
public:
	AnsiString info;
	int key;
	int count;
	HashNode* pNext;

	HashNode(int key,AnsiString value)
	{
	  this->info = value;
	  this->key = key;
	  pNext = nullptr;
	   count = 1;
	}
};


class HashMap
{
      HashNode **arr;
      int capacity;

public:

	HashMap()
	{
	   capacity = 11;
	   arr = new HashNode*[capacity];
	   for (int i=0; i<capacity; i++)
	   {
	      arr[i] = NULL;
	   }
	}

	int hashCode(int Key);
	void insertNode(int key, AnsiString value);
	void display(TMemo*);
	int pop_key();
	void search(TMemo*, int key);
        void Delete(int key);
};