//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "_unit_main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm4 *Form4;
//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
	: TForm(Owner)
{
 	//============����� ������ � �����������===============

Cnst->Cells[0][0]="Go";
Cnst->Cells[1][0]="Gmin, T";
Cnst->Cells[2][0]="Gmax, T";
Cnst->Cells[3][0]="n min, ��/���";
Cnst->Cells[4][0]="n max, ��/���";
Cnst->Cells[5][0]="D, �";
Cnst->Cells[6][0]="d, �";
Cnst->Cells[7][0]="d�, �";
Cnst->Cells[8][0]="d��, �";
Cnst->Cells[9][0]="dy, �";
Cnst->Cells[10][0]="do, �";
Cnst->Cells[11][0]="Lc, �";
Cnst->Cells[12][0]="L, �";
Cnst->Cells[13][0]="ly, �";
Cnst->Cells[14][0]="lt, �";
Cnst->Cells[15][0]="���, �/�*�";
Cnst->Cells[16][0]="f, �*�";
Cnst->Cells[17][0]="b";
Cnst->Cells[18][0]="���, �/�*�";
Cnst->Cells[19][0]="���, �/�*�";
Cnst->Cells[20][0]="N�, ���";
Cnst->Cells[21][0]="Np, ���";
Cnst->Cells[22][0]="gamma, �/�*�*�";
Kfc->Cells[0][0]="k";
Kfc->Cells[1][0]="alpha";
Kfc->Cells[2][0]="betta";
Kfc->Cells[3][0]="mu";
Kfc->Cells[4][0]="lambda";
Kfc->Cells[5][0]="lambda ��";
Kfc->Cells[6][0]="lambda ���";
Kfc->Cells[7][0]="alpha ��";
Cnt->Cells[0][0]="G, T";
Cnt->Cells[1][0]="n, ��/���";
Cnt->Cells[2][0]="Vm, �/�";
Cnt->Cells[3][0]="P, ��";
Cnt->Cells[4][0]="Q, �/�";
Cnt->Cells[5][0]="T, ���";
Cnt->Cells[6][0]="nu, �/�*�";
Cnt->Cells[7][0]="tau �, ��*�";
Cnt->Cells[8][0]="V��, �/�";

//=====�������������� �������� �������� � �������======

Cnst->Cells[0][1]=FloatToStr(2);
Cnst->Cells[1][1]=FloatToStr(0);
Cnst->Cells[2][1]=FloatToStr(20);
Cnst->Cells[3][1]=FloatToStr(0);
Cnst->Cells[4][1]=FloatToStr(200);
Cnst->Cells[5][1]=FloatToStr(0.295) ;
Cnst->Cells[6][1]=FloatToStr(0.265);
Cnst->Cells[7][1]=FloatToStr(0.168);
Cnst->Cells[8][1]=FloatToStr(0.203) ;
Cnst->Cells[9][1]=FloatToStr(0.195) ;
Cnst->Cells[10][1]=FloatToStr(0.127);
Cnst->Cells[11][1]=FloatToStr(1000) ;
Cnst->Cells[12][1]=FloatToStr(1000);
Cnst->Cells[13][1]=FloatToStr(100) ;
Cnst->Cells[14][1]=FloatToStr(900)  ;
Cnst->Cells[15][1]=FloatToStr(9000000) ;
Cnst->Cells[16][1]=FloatToStr(0.017)  ;
Cnst->Cells[17][1]=FloatToStr(0.2)  ;
Cnst->Cells[18][1]=FloatToStr(14000000)  ;
Cnst->Cells[19][1]=FloatToStr(15000000) ;
Cnst->Cells[20][1]=FloatToStr(1000) ;
Cnst->Cells[21][1]=FloatToStr(3000) ;
Cnst->Cells[22][1]=FloatToStr(11379.6) ;
Kfc->Cells[0][1]=FloatToStr(1.2) ;
Kfc->Cells[1][1]=FloatToStr(0.2) ;
Kfc->Cells[2][1]=FloatToStr(0.8)  ;
Kfc->Cells[3][1]=FloatToStr(0.64) ;
Kfc->Cells[4][1]=FloatToStr(0.02)  ;
Kfc->Cells[5][1]=FloatToStr(0.025)  ;
Kfc->Cells[6][1]=FloatToStr(0.034)  ;
Kfc->Cells[7][1]=FloatToStr(0.00137)  ;
}
//---------------------------------------------------------------------------
