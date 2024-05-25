//---------------------------------------------------------------------------

#ifndef _unit_mainH
#define _unit_mainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <pngimage.hpp>
#include <Buttons.hpp>
#include <Menus.hpp>

//---------------------------------------------------------------------------
class TForm4 : public TForm
{
__published:	// IDE-managed Components
	TStringGrid *Cnst;
	TLabel *Label1;
	TStringGrid *Kfc;
	TStringGrid *Cnt;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TImage *Image1;
	TBitBtn *BitBtn1;
	TEdit *debug;
	TButton *Button1;
	TPopupMenu *PopupMenu1;
	TMenuItem *N1;
	TMenuItem *N2;
	TMenuItem *N3;
	TMenuItem *N4;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall BitBtn1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm4(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm4 *Form4;
//---------------------------------------------------------------------------
#endif
