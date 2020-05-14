﻿//---------------------------------------------------------------------------

#pragma hdrstop

#include "BTree.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

BTree::BTree()
{
    root = NULL;
}

BTree::~BTree()
{
    DestroyTree();
}

void BTree::DestroyTree(Node* leaf)
{
	if(leaf)
	{
	    DestroyTree(leaf->left);
	    DestroyTree(leaf->right);
	    delete leaf;
        }
}

void BTree::Insert(int num, AnsiString surname, Node* leaf)
{
	if(num<leaf->place)
	{
	    if(leaf->left)
	    {
		Insert(num,surname,leaf->left);
	    }

	    else
	    {
		leaf->left = new Node;
		leaf->left->place = num;
		leaf->left->surname = surname;
		leaf->left->left = NULL;
		leaf->left->right = NULL;
	    }
	}

	else
	{
	    if(leaf->right)
	    {
		Insert(num,surname,leaf->right);
	    }

	    else
	    {
                leaf->right = new Node;

		leaf->right->place = num;
		leaf->right->surname = surname;
		leaf->right->right = NULL;
		leaf->right->left = NULL;
            }
        }
}

void BTree::Insert(int key, AnsiString str)
{
    if(root)
    {
	Insert(key, str, root);
    }

    else
    {
		root = new Node;
		root->place = key;
		root->surname = str;
		root->left = NULL;
		root->right = NULL;
    }
}

Node* BTree::Search(int key,Node *leaf)
{
    if(leaf)
    {
	if(key == leaf->place)
	{
	    return leaf;
	}

	if(key<leaf->place)
	{
	    return Search(key, leaf->left);
	}

	else
	{
	    return Search(key, leaf->right);
	}
    }

    else
    {
	return NULL;
    }
}

Node* BTree::Search(int key, TMemo* Memo)
{
	Node *temp = Search(key, root);
    if(temp)
    {
       Memo->Clear();
       Memo->Lines->Add("Êëþ÷: " + IntToStr(key));
       Memo->Lines->Add("Ôàìèëèÿ: " + temp->surname);
    }

    else
    {
          Memo->Clear();
       Memo->Lines->Add("Ïî çàäàííîìó êëþ÷ó íè÷åãî íå íàéäåíî");
    }
}

void BTree::DestroyTree()
{
    DestroyTree(root);
}

void BTree::InorderPrint(TMemo* Memo)
{
    InorderPrint(Memo, root);
    Memo->Lines->Add("\n");
}

void BTree::InorderPrint(TMemo* Memo, Node* leaf)
{
    if(leaf)
    {
	InorderPrint(Memo, leaf->left);
	Memo->Lines->Add(IntToStr(leaf->place) + " - " + leaf->surname + ",");
	InorderPrint(Memo,leaf->right);
    }
}

void BTree::PostorderPrint(TMemo* Memo)
{
    PostorderPrint(Memo, root);
    Memo->Lines->Add("\n");
}

void BTree::PostorderPrint(TMemo* Memo, Node* leaf)
{
    if(leaf)
    {
	PostorderPrint(Memo, leaf->left);
	PostorderPrint(Memo, leaf->right);
	Memo->Lines->Add(IntToStr(leaf->place) + " - " + leaf->surname + ",");
    }
}

void BTree::PreorderPrint(TMemo* Memo)
{
    PreorderPrint(Memo, root);
    Memo->Lines->Add("\n");
}

void BTree::PreorderPrint(TMemo* Memo, Node* leaf)
{
    if(leaf)
    {
	Memo->Lines->Add(IntToStr(leaf->place) + " - " + leaf->surname + ",");
	PreorderPrint(Memo, leaf->left);
	PreorderPrint(Memo, leaf->right);
    }
}

void BTree :: PrintTree(Node* temp, TTreeView *TreeView, int &index)
{
	int i = index;

	if(temp->left)
	{
		TreeView->Items->AddChild(TreeView->Items->Item[i], temp->left->surname);
		PrintTree(temp->left, TreeView, ++index);
	}

	if(temp->right)
	{
		TreeView->Items->AddChild(TreeView->Items->Item[i], temp->right->surname);
		PrintTree(temp->right, TreeView, ++index);
	}
}

void BTree :: ShowTree(TTreeView *TreeView)
{
	int index = 0;

	TreeView->Items->Clear();

	if(root)
	{
		TreeView->Items->Add(NULL, root->surname);
		PrintTree(root, TreeView, index);
	}
}

void BTree :: Balance()
{
	int amount = 0;

	Size(root,amount);

	int* arr = new int[amount];

	AnsiString* str = new AnsiString[amount];

	int size = 0;

	ToArray(root, arr, str, size);
	DestroyTree(root);

	root = MakeTree(arr, str, 0, size);
}

void BTree :: ToArray(Node *p, int* arr, AnsiString* str, int &index)
{
	if(p->left) ToArray(p->left, arr, str, index);
	str[index] = p->surname;
	arr[index] = p->place;
	index++;
	if(p->right) ToArray(p->right, arr, str, index);
}

Node* BTree :: MakeTree(int *arr, AnsiString *str, int first, int last)
{
	if(!last)
	{
	     return nullptr;
	}
	Node *node = new Node;

	node->surname = str[first + last / 2];
	node->place = arr[first + last / 2];

	int lastl = last / 2;
	int lastr = last - lastl - 1;

	node->left = MakeTree(arr, str, first, lastl);
	node->right = MakeTree(arr, str, first + lastl + 1, lastr);

	return node;
}

void BTree::Size(Node* p,int &amount)
{
    if(p)
    {
	if(p->left)
	{
	    Size(p->left,amount);
	    amount++;
	}

	if(p->right)
	{
            Size(p->right,amount);
	    amount++;
        }
    }

    if(amount)
	++amount;


    else
    {
	amount = 0;
    }
}

void BTree :: DeleteNode(int num)
{
	Node *del, *prevdel, *node, *prevnode;
	del = root;
	prevdel = nullptr;

	while(del->place != num)
	{
		prevdel = del;

		if(num < del->place)
		{
		    del = del->left;
		}

		else
		{
		     del = del->right;
		}
	}


	if(!del)
	{
	    return;
	}

	if(!del->right)
	{
	    node = del->left;
	}

	else if(!del->left)
	{
	    node = del->right;
	}

	else
	{
		prevnode = del;
		node = del->left;

		while(node->right)
		{
			prevnode = node;
			node = node->right;
		}

		if(prevnode == del)
		{
		     node->right = del->right;
		}

		else
		{
			node->right = del->right;
			prevnode->right = node->left;
			node->left = prevnode;
		}
	}

	if(!prevdel)
	{
	    root = prevdel = node;
	}

	else if(del->place < prevdel->place)
	{
	     prevdel->left = node;
	}

	else
	{
	     prevdel->right = node;
	}
	delete del;
}

void BTree::LeftWingSize(int &amount)
{

	LeftWingSize(root->left,amount);
}

void BTree::LeftWingSize(Node* p,int &amount)
{

    if(p)
    {
	if(p->left)
	{
	    LeftWingSize(p->left,amount);
	    amount++;
	}

	if(p->right)
	{
	    LeftWingSize(p->right, amount);
	    amount++;
        }
    }



    else
    {
	amount = 0;
    }
}
