//---------------------------------------------------------------------------

#ifndef _Unit1H
#define _Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include "_Unit1.h"
#include "_Unitl.h"
#include "_Cnrtol.h"
#include "_unit_main.h"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TLabeledEdit *LabeledEdit1;
	TLabeledEdit *LabeledEdit2;
	TLabeledEdit *LabeledEdit3;
	TLabeledEdit *LabeledEdit4;
	TLabeledEdit *LabeledEdit5;
	TLabeledEdit *LabeledEdit6;
	TLabeledEdit *LabeledEdit7;
	TLabeledEdit *LabeledEdit8;
	TLabeledEdit *LabeledEdit9;
	TButton *Button1;
	TButton *Button2;
	TButton *Button3;
	TEdit *debug;
	TButton *Button4;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
