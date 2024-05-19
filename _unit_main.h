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
	TButton *Button1;
	TImage *Image1;
private:	// User declarations
public:		// User declarations
	__fastcall TForm4(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm4 *Form4;
//---------------------------------------------------------------------------
#endif
