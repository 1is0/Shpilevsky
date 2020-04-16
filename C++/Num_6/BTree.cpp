//---------------------------------------------------------------------------

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
    destroy_tree();
}

void BTree::destroy_tree(Node* leaf)
{
	if(leaf)
	{
	    destroy_tree(leaf->left);
	    destroy_tree(leaf->right);
	    delete leaf;
        }
}

void BTree::insert(int num, AnsiString surname, Node* leaf)
{
	if(num<leaf->place)
	{
	    if(leaf->left)
	    {
		insert(num,surname,leaf->left);
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
		insert(num,surname,leaf->right);
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

void BTree::insert(int key, AnsiString str)
{
    if(root)
    {
	insert(key, str, root);
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

Node* BTree::search(int key,Node *leaf)
{
    if(leaf)
    {
	if(key == leaf->place)
	{
	    return leaf;
	}

	if(key<leaf->place)
	{
	    return search(key, leaf->left);
	}

	else
	{
	    return search(key, leaf->right);
	}
    }

    else
    {
	return NULL;
    }
}

Node* BTree::search(int key, TMemo* Memo)
{
	Node *temp = search(key, root);
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

void BTree::destroy_tree()
{
    destroy_tree(root);
}

void BTree::inorder_print(TMemo* Memo)
{
    inorder_print(Memo, root);
    Memo->Lines->Add("\n");
}

void BTree::inorder_print(TMemo* Memo, Node* leaf)
{
    if(leaf)
    {
	inorder_print(Memo, leaf->left);
	Memo->Lines->Add(IntToStr(leaf->place) + " - " + leaf->surname + ",");
	inorder_print(Memo,leaf->right);
    }
}

void BTree::postorder_print(TMemo* Memo)
{
    postorder_print(Memo, root);
    Memo->Lines->Add("\n");
}

void BTree::postorder_print(TMemo* Memo, Node* leaf)
{
    if(leaf)
    {
	inorder_print(Memo, leaf->left);
	inorder_print(Memo, leaf->right);
	Memo->Lines->Add(IntToStr(leaf->place) + " - " + leaf->surname + ",");
    }
}

void BTree::preorder_print(TMemo* Memo)
{
    preorder_print(Memo, root);
    Memo->Lines->Add("\n");
}

void BTree::preorder_print(TMemo* Memo, Node* leaf)
{
    if(leaf)
    {
	Memo->Lines->Add(IntToStr(leaf->place) + " - " + leaf->surname + ",");
	inorder_print(Memo, leaf->left);
	inorder_print(Memo, leaf->right);
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

	size(root,amount);

	int* arr = new int[amount];
	AnsiString* str = new AnsiString[amount];
	int size = 0;
	ToArray(root, arr, str, size);
	destroy_tree(root);
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
	if(!last) return nullptr;
	Node *node = new Node;
	node->surname = str[first + last / 2];
	node->place = arr[first + last / 2];
	int lastl = last / 2;
	int lastr = last - lastl - 1;
	node->left = MakeTree(arr, str, first, lastl);
	node->right = MakeTree(arr, str, first + lastl + 1, lastr);
	return node;
}

void BTree::size(Node* p,int &amount)
{
    if(p)
    {
	if(p->left)
	{
	    size(p->left,amount);
	    amount++;
	}

	if(p->right)
	{
            size(p->right,amount);
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

void BTree::RightWingSize(int &amount)
{

	RightWingSize(root,amount);
}

void BTree::RightWingSize(Node* p,int &amount)
{

    if(p)
    {
	if(p->right)
	{
	    RightWingSize(p->right,amount);
	    amount++;
	}
    }



    else
    {
	amount = 0;
    }
}
