//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "_Unit1.h"
#include "_Unitl.h"
#include "_Cnrtol.h"
#include "_unit_main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	Form4->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
	F1->Show();
}
//---------------------------------------------------------------------------

