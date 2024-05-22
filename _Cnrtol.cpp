//---------------------------------------------------------------------------

#include <vcl.h>
#include <math.h>
#include <mmsystem.h>
#pragma hdrstop

#include "_Cnrtol.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TF1 *F1;
int I, lo, i;
AnsiString txt;
//---------------------------------------------------------------------------
__fastcall TF1::TF1(TComponent* Owner)	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
