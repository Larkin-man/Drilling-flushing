//---------------------------------------------------------------------------

#include <vcl.h>
#include <math.h>
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

void __fastcall TForm1::Button3Click(TObject *Sender)
{
 	Form2->Show();
}
//---------------------------------------------------------------------------
//=====================================================================
//===========��������� ������� ����������� ���������� ���==============
//=====================================================================


double Cd; // ��������� ������
double C; //��������� 1 ���� ������� (������������� ���������� ������)
double Cep; // ��������� 1 ���� ���
double Cpr; // ��������� 1 ���� �������� ��������
extern double T; // ����� �������
double Tcp; // ����� ���
double Tpr;  // ����� ��������
double H; // ��������
// ��������� ����������� ��������� ��� �������� �������
// ��������� ����� ��� �� ����
double Criteria()
{
return (Cd + C * T + Cep * Tcp + Cpr * Tpr) /H;
}


extern

//========���������� ���������� ����������=========
const int Vars=2;
extern double Ymin[Vars];
extern double Ymax[Vars];
extern double Y[Vars]; //������ ������������ �������� G � n
extern double NY[Vars]; //�������� ��������������� ���������� �������
extern double Nrom;

void FindLocalExtremum()
{
double tempval;
const Eps = 0.01;
const H = 0.01;
const Delta = 0.000001;
double N = 0;
for (int i=1; i<=Vars; i++)
{
if (Ymin[i] >= Ymax[i])
{
Form1->debug->Text = "��������� ��������: ������� �.�. ������ ���������";
break;
}
if ((Y[i] < Ymin[i]) && (Y[i] > Ymax[i]))
{
Form1->debug->Text = "��������� ��������: ������� �.�. ������ ���������";
break;
}
if((Y[i]<Ymin[i])&&(Y[i]>Ymax[i]))
{
Form4->debug->Text="��������� �������� ������ ���� � �������� ���������";
break;
}
}
bool Stoplt = false;
	//Form2->Edit8->Text="";
	//Form2->Edit9->Text="";
	//Form2->Edit10->Text="";
double Num, Norm;
do
{
N=N+1;
for (int i=1; i<=Vars; i++)
{
if ((Y[i] < Ymin[i]) || (Y[i] > Ymax[i])) break;
Num = Y[i];
Y[i] = Y[i] + Delta;
NY[i] = Criteria();
Y[i] = Num;
NY[i] = (NY[i] - Criteria()) / Delta; // �������� �������
}
Nrom = 0;
for (int i = 1; i<=Vars; i++)
Norm = Norm + pow(NY[i],2);
Norm = sqrt(Norm); // ����� ���������
for (int i = 1; i<=Vars; i++)
{
if (Norm > 0)
NY[i] = Y[i] + NY[i] / Norm * H;
else
NY[i] = Y[i];
if (NY[i] > Ymax[i]) NY[i] = Ymax[i];
if (NY[i] > Ymax[i])
NY[i] = Ymax[i];
else
if (NY[i] < Ymin[i]) NY[i] = Ymin[i];
Norm = 0;
}
for (int i = 1; i<=Vars; i++)
{
Num = Num - abs(NY[i] - Y[i]);
Y[i] = NY[i];
if(i==1)
{

}
	//Forml->Edit9 = ((Y[i] * 1000000000.0 + 0.5) / 1000000000.0)
else
{

}
	//Form4->Edit9 = IntToStr(Int(Y[i] * 1000000000.0 + 0.5) / 1000000000.0);
}
double tempfunc = (Criteria() * 1000000000.0 + 0.5) / 1000000000.0;
if (tempfunc > Ymax[2])
{
Stoplt = true;
	//Form4->Edit10->Text = IntToStr(tempval);
Num = 0;
}
//if (Num != 0.0)
//	double tempval = tempfunc;
} while ((Norm <= Eps) || (Num != 0) || (Stoplt != true));
}



