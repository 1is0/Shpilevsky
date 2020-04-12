//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "BTree.h"
BTree* tree;
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	tree = new BTree();
        StringGrid1->Cells[0][0] = "�������";
	StringGrid1->Cells[1][0] = "�������� �����";

	Button2->Enabled = false;
	Button3->Enabled = false;
	Button4->Enabled = false;
	Button5->Enabled = false;
	Button6->Enabled = false;
	Button7->Enabled = false;
        Button8->Enabled = false;

}

void TurnOn()
{
	Form1->Button2->Enabled = true;
	Form1->Button3->Enabled = true;
	Form1->Button4->Enabled = true;
	Form1->Button5->Enabled = true;
	Form1->Button6->Enabled = true;
	Form1->Button7->Enabled = true;
       Form1->Button8->Enabled = true;
}
//---------------------------------------------------------------------------
void Clear()
{
    Form1->Edit1->Text = "";
    Form1->Edit2->Text = "";
}

bool IsRepeat(int num)
{
	for(int i = 1 ; i < Form1->StringGrid1->RowCount; i++)
	{
		if(num == Form1->StringGrid1->Cells[1][i].ToInt()) return false;
	}
	return true;
}

void __fastcall TForm1::Button1Click(TObject *Sender)
{

	Memo1->Clear();
	 int place;
         AnsiString str;
	if(Edit1->Text!="")
	 str = Edit1->Text;

	if(Edit2->Text!="")
	place = StrToInt(Edit2->Text);


	if(IsRepeat(place)&& Edit1->Text!=""  && Edit2->Text!="" && StrToInt(Edit2->Text)>=1 && StrToInt(Edit2->Text)<=1000)
	{


	StringGrid1->RowCount++;
	StringGrid1->Cells[0][StringGrid1->RowCount - 1] = str;
	StringGrid1->Cells[1][StringGrid1->RowCount - 1] = place;
	tree->insert(place, str);
	tree->inorder_print(Memo1);
	tree->ShowTree(Form1->TreeView1);
                TurnOn();
	}

	else
	{
	    ShowMessage("�������� �������� �� ����");
	}


	Clear();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
	tree->destroy_tree();
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Button2Click(TObject *Sender)
{
	tree->Balance();

	tree->ShowTree(TreeView1);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{

	if(Edit2->Text!="")
	{
	int key = StrToInt(Edit2->Text);

	tree->search(key, Memo1);
	}

	else
	{
	    ShowMessage("������� ����(�������� �����)");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
	Memo1->Clear();
	tree->preorder_print(Memo1);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
	Memo1->Clear();
	tree->postorder_print(Memo1);
}


//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{
	Memo1->Clear();
	tree->inorder_print(Memo1);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject *Sender)
{

	if(Edit2->Text!="")
	{
		int key = StrToInt(Edit2->Text);

		if(!IsRepeat(key))
		{

		tree->DeleteNode(key);

		for(int i = 1, j = 1; i < StringGrid1->RowCount; i++)
		{
			if(StringGrid1->Cells[1][i] != key)
			{
				StringGrid1->Cells[0][j] = StringGrid1->Cells[0][i];
				StringGrid1->Cells[1][j] = StringGrid1->Cells[1][i];
				j++;
			}
		}
		StringGrid1->RowCount--;
                Clear();

                tree->ShowTree(TreeView1);
		}

		else
		{
                    ShowMessage("����� � ����� ������� ���");
                }
	}

	else
	{
	  ShowMessage("������� ����(�������� �����)");
	}

        Memo1->Clear();
}



//---------------------------------------------------------------------------

void __fastcall TForm1::Button8Click(TObject *Sender)
{
	int amount = 0;
	tree->RightWingSize(amount);

        ShowMessage("����������: " + IntToStr(amount));
}
//---------------------------------------------------------------------------

