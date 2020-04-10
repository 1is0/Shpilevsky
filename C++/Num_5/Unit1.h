//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Samples.Gauges.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TGauge *Gauge1;
	TButton *Button1;
	TLabel *Value;
	TLabel *Label2;
	TButton *Button3;
	TButton *Button4;
	TListBox *ListBox1;
	TLabel *Label1;
	TLabel *Label3;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        void ShowOnForm();
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif