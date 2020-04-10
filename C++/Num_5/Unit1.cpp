//---------------------------------------------------------------------------
#include "stdlib.h"
#include "time.h"
#include <vcl.h>
#pragma hdrstop
#include"List.cpp"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

List <int> numbers;
int current =0;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	srand(time(NULL));

	numbers.push_back(rand()%100);

	Gauge1->Progress = (1./numbers.GetSize())*100;
	Value->Caption = IntToStr(numbers[0]);
	Label3->Caption = IntToStr(1);

	ListBox1->Items->Add(IntToStr(numbers.GetSize()) + ": " + numbers.Peek(numbers.GetSize()-1));
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
        numbers.clear();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
	current++;
	if(current>=numbers.GetSize())
	{
            current = 0;
	}
	ShowOnForm();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
	current--;
	if(current<0)
	{
            current = numbers.GetSize() - 1;
	}
	ShowOnForm();
}

void TForm1::ShowOnForm()
{

      Gauge1->Progress = (float(current +1) /numbers.GetSize())*100;
	Value->Caption = IntToStr(numbers[current]);
	Label3->Caption = IntToStr(current+1);
}
//---------------------------------------------------------------------------