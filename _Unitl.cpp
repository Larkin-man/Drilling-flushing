//---------------------------------------------------------------------------

#include <vcl.h>
#include <math.h>
#pragma hdrstop

#include "_Unitl.h"
#include "_Unit1.h"
#include "_Cnrtol.h"
#include "_unit_main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
//=======������ ����������� �������� � ��������======

double Pspo; //zanenne p cknaxnne mpi CIIO;
extern double Pgr; //xapaenme rugpopaspsina actos;
double Vt; //ckopocts xpwxenns tpy6 mpx CTO;
double a; //yckopenue apmoxenna KooHHDI Tpy6;
double Gk; //sec na Kpioxe;
double Gx; //max - MaKcuMasibHo onyer. Bec Ha KpIoKe.

extern double b ;//��������� ����� ������
extern double betta ;//���������� �������, ��������� �� ��������� ������ � �����, � ������� �������� ������
extern double nu ;//������������ �������� ��������
extern double gamma ;//�������� ��� �������� ��������
extern double tauo ;//������������ ���������� ������ ������� ��������
extern double vkp ;//������� �������� ������� �������� �������� � ��������� ������������ ���������
//double vkp ;//����������� �������� �������� ��������
extern double Q ;//������ �������� ��������
extern double D ;//������� �������� (������)
extern double dn ;//�������� ������� ��������� ����
extern double dny ;//�������� ������� ����������� ��������� ����(���)
extern double dd ;//��������� ������� ����
extern double dy ;//��������� ������� ���
extern double ddo ;//������� ����������� ���������� ������� � ����������
extern double Lc ;//������� ��������
extern double L ;//����� ��������� ����
extern double ly ;//����� ���
extern double lt ;//����� ����� �����

extern double Criteria();

double FindSpuskDodem()
{
Pspo = 8,75 * 0.01 * ((Vt * dny)/pow(D-dn, 2) * pow((dn/(D-dn)),1.5));
Pspo = Pspo && (4*(tauo*L/Criteria()*(D-dn)+0.025) +a * (ly*dn)/D-dn)+ Lc;
////������-��������� �������� ������������� �������� �������� "������� ��������� ����� ��� �� ����",
////������� ����� �������������� ���������� ��� ������� � ������ �������� "������� ��������� 1 ����� ��������"
Pspo=Lc*(1/Lc+1/dn);
return Pspo;
}

void __fastcall TForm2::Button1Click(TObject *Sender)
{
//	Pspo;// = LabeledEdit1 //zanenne p cknaxnne mpi CIIO;
// Pgr; //xapaenme rugpopaspsina actos;
// Vt; //ckopocts xpwxenns tpy6 mpx CTO;
// a; //yckopenue apmoxenna KooHHDI Tpy6;
// Gk; //sec na Kpioxe;
// Gx; //max - MaKcuMasibHo onyer. Bec Ha KpIoKe.
   Pgr = LabeledEdit2->Text.ToDouble();
Vt = LabeledEdit3->Text.ToDouble();
a = LabeledEdit4->Text.ToDouble();
Gk = LabeledEdit6->Text.ToDouble();
Gx = LabeledEdit5->Text.ToDouble();
   LabeledEdit1->Text = FloatToStr(FindSpuskDodem());
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button2Click(TObject *Sender)
{
	Form4->Show();
   Form2->Close();
}
//---------------------------------------------------------------------------

