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

	void insert(int num, AnsiString Surname);

	Node* search(int key,TMemo*);

	void destroy_tree();

	void inorder_print(TMemo*);
	void postorder_print(TMemo*);
	void preorder_print(TMemo*);

	void PrintTree(Node* temp, TTreeView *TreeView, int &index);
	void ShowTree(TTreeView *TreeView);

	void Balance();
	void DeleteNode(int num);

	void RightWingSize(int &amount);


private:
	void destroy_tree(Node *leaf);
	void insert(int key,AnsiString Surname, Node *leaf);
	Node *search(int key,Node *leaf);
	void inorder_print(TMemo*, Node *leaf);
	void postorder_print(TMemo*,Node *leaf);
	void preorder_print(TMemo*,Node *leaf);
	void ToArray(Node*, int*, AnsiString*, int&);
	Node* MakeTree(int*, AnsiString*, int, int);
	void size(Node*,int &amount);
        void RightWingSize(Node* p,int &amount);


	Node* root;
};
