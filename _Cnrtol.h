//---------------------------------------------------------------------------

#ifndef _CnrtolH
#define _CnrtolH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
#include "_Unit1.h"
#include "_Unitl.h"
#include "_Cnrtol.h"
#include "_unit_main.h"
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TF1 : public TForm
{
__published:	// IDE-managed Components
	TScrollBox *ScrollBox1;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TPanel *Panel1;
	TLabel *Label8;
	TLabel *Label9;
	TLabel *Label10;
	TLabel *Label11;
	TLabel *Label12;
	TLabel *Label13;
	TLabel *Label14;
	TLabeledEdit *eMt;
	TLabel *Label15;
	TLabeledEdit *eMd;
	TLabeledEdit *eGkml;
	TLabeledEdit *eGkmk;
	TLabeledEdit *eAr;
	TLabeledEdit *eTvr;
	TLabeledEdit *eTvrd;
	TLabeledEdit *eTbd;
	TLabel *Label16;
	TEdit *eM;
	TEdit *eGk;
	TEdit *eGkt;
	TEdit *eTpr;
	TEdit *eTprd;
	TEdit *eTb;
	TEdit *eK1;
	TEdit *eDn;
	TEdit *eDt;
	TEdit *eL;
	TEdit *eLÒ;
	TEdit *ePÒ;
	TEdit *eK2;
	TEdit *eVdr;
	TEdit *e5;
	TGroupBox *GroupBox1;
	TRichEdit *Msg;
	TPanel *Panel2;
	TEdit *ePspo;
	TEdit *ePgr;
	TEdit *ePobd;
	TEdit *eQk;
	TEdit *egamma;
	TEdit *eD;
	TEdit *eTp;
	TLabel *Label17;
	TLabel *Label18;
	TLabel *Label20;
	TLabel *Label21;
	TLabel *Label22;
	TLabel *Label23;
	TLabel *Label24;
	TButton *Button1;
	void __fastcall ePspoExit(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall eMExit(TObject *Sender);
	void __fastcall eGkExit(TObject *Sender);
	void __fastcall eGktExit(TObject *Sender);
	void __fastcall eTvrExit(TObject *Sender);
	void __fastcall eTprExit(TObject *Sender);
	void __fastcall eTbExit(TObject *Sender);
	void __fastcall Panel1Exit(TObject *Sender);
	void __fastcall eLÒExit(TObject *Sender);
	void __fastcall Panel2Exit(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TF1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TF1 *F1;
//---------------------------------------------------------------------------
#endif
