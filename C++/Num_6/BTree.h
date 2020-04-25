//---------------------------------------------------------------------------

#ifndef BTreeH
#define BTreeH
//---------------------------------------------------------------------------
#endif

class Node
{
public:
      Node* left;
      Node* right;
      AnsiString surname;
      int place;
};

class BTree
{
public:
	BTree();
	~BTree();

	void Insert(int num, AnsiString Surname);

	Node* Search(int key,TMemo*);

	void DestroyTree();

	void InorderPrint(TMemo*);
	void PostorderPrint(TMemo*);
	void PreorderPrint(TMemo*);

	void PrintTree(Node* temp, TTreeView *TreeView, int &index);
	void ShowTree(TTreeView *TreeView);

	void Balance();
	void DeleteNode(int num);

	void LeftWingSize(int &amount);


private:
	void DestroyTree(Node *leaf);
	void Insert(int key,AnsiString Surname, Node *leaf);
	Node *Search(int key,Node *leaf);
	void InorderPrint(TMemo*, Node *leaf);
	void PostorderPrint(TMemo*,Node *leaf);
	void PreorderPrint(TMemo*,Node *leaf);
	void ToArray(Node*, int*, AnsiString*, int&);
	Node* MakeTree(int*, AnsiString*, int, int);
	void Size(Node*,int &amount);
	void LeftWingSize(Node* p,int &amount);


	Node* root;
};
