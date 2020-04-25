//---------------------------------------------------------------------------

#pragma hdrstop


#include "HashMap.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)


int HashMap::hashCode(int key)
{
	return key%capacity;
}

void HashMap::insertNode(int key, AnsiString surname)
{
    int index = hashCode(key);

    if(!arr[index])
    {
	arr[index] = new HashNode(key, surname);
    }

    else
    {
	HashNode* temp = arr[index];

	while(temp->pNext)
	{
	    temp = temp->pNext;
	}

	temp->pNext = new HashNode(key,surname);
	arr[index]->count++;
    }


}

void HashMap::display(TMemo* Memo)
{
    for (int i = 0; i < capacity; i++)
    {
	if(arr[i])
	{
	    AnsiString str = IntToStr(i);
	    str+="-->" + arr[i]->info;
	    if(arr[i]->pNext != NULL)
	    {
		HashNode *temp = arr[i]->pNext;
		while(temp)
		{
		str+="-->" + temp->info;
		temp = temp->pNext;
		}
	    }
	    Memo->Lines->Add(str);
	}
    }
}

int HashMap::pop_key()
{
	int Key = 0;
	int max=0;

	for (int i = 0; i<capacity; i++)
	{
	   if(arr[i] && max<arr[i]->count)
	   {
	      max= arr[i]->count;
	      Key = i;
	   }
	}

        return Key;
}

void HashMap::search(TMemo* Memo, int key)
{
	int index = hashCode(key);

	if(!arr[index])
	{
	    Memo->Lines->Add("�� ������� ����� ������ �� ����� �����");
	    return;
	}

	if(arr[index]->key == key)
	{
	   AnsiString mes = IntToStr(index);
	   mes+="-->" + arr[index]->info;
	   if(arr[index]->pNext)
	   {
	       HashNode* temp = arr[index]->pNext;
	       while(temp)
	       {
		   mes+="-->" + temp->info;
		   temp = temp->pNext;
	       }
	   }

           Memo->Lines->Add(mes);
	}
}

void HashMap::Delete(int key)
{
    int index = hashCode(key);

    HashNode* temp = arr[index];
    HashNode* buf = temp;

     if(temp)
     {
	 if(temp->key==key)
	 {
	     if(!temp->pNext)
	     {
		 arr[index] = temp->pNext;
	     }


	     else
	     {

		while(temp->pNext->pNext)
		{

		    temp = temp->pNext;
		}

		temp->pNext = nullptr;
		/*delete arr[index];
                arr[index] = buf;*/
	     }

	 }
     }

     else
     {
         ShowMessage("�������� ����");
     }
}
