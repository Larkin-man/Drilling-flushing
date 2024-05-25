//---------------------------------------------------------------------------

#include <vcl.h>
#include <math.h>
#pragma hdrstop

#include "_unit_main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm4 *Form4;
//---------------------------------------------------------------------------
const int Vars=2;
const double Kgam=1.262;
const double Kqd=9.5;
//���� ����������, ������������ ��� ���������� ��������� �������
double Y[Vars]; //������ ������������ �������� G � n
double NY[Vars]; //�������� ��������������� ���������� �������
double Ymin[Vars];
double Ymax[Vars];
//���� ����������, ������������ ��� �������� ��������������� ��������, ������������ � �������� ������ ����������
double Vm ;//������������ �������� ��������
double k ;//��������� ������������������
double G ;//�������� �������� �� ������
double Go ;//����������, ��������������� ��������� ������
double N ;//�������� �������� ������
double alfa ;//���������� �������, ��������� �� ���� ������ � ��������
double T ;//����� ������ ������
double b ;//��������� ����� ������
double betta ;//���������� �������, ��������� �� ��������� ������ � �����, � ������� �������� ������
double nu ;//������������ �������� ��������
double gamma ;//�������� ��� �������� ��������
double tauo ;//������������ ���������� ������ ������� ��������
double vkp ;//������� �������� ������� �������� �������� � ��������� ������������ ���������
//double vkp ;//����������� �������� �������� ��������
double Q ;//������ �������� ��������
double D ;//������� �������� (������)
double dn ;//�������� ������� ��������� ����
double dny ;//�������� ������� ����������� ��������� ����(���)
double dd ;//��������� ������� ����
double dy ;//��������� ������� ���
double ddo ;//������� ����������� ���������� ������� � ����������
double Lc ;//������� ��������
double L ;//����� ��������� ����
double ly ;//����� ���
double lt ;//����� ����� �����
double P ;//�������� �������� �������� � ��������
double Ppl ;//�������� ��������
double alfaob ;//���������� �������
double mu ;//��������� ������� �������� ��������
double f ;//��������� ������� ������� ����������� ��������� ������
double lambda ;//��������� ��������������� ������������� � ������
double lambdakp ;//��������� ��������������� ������������� � ���������� ������������ ��������
double lambdakpu ;//��������� ��������������� ������������� � ��������� ������������ ���
double Gmin ;//����������� ������ �������� �� ������
double Gmax ;//������������ ������ �������� �� ������
double Nmin ;//����������� ������ �������� �������� ������
double Nmax ;//������������ ������ �������� �������� ������
double Pnd ;//���������� �������� �� ������
double Pgr ;//�������� ������������ ������
double Np ;//������������ �������� �������
double Nr ;//�������������� �������� �������

   double Nrom;
   double Nn;

__fastcall TForm4::TForm4(TComponent* Owner)	: TForm(Owner)
{
	Nrom = 0;
   Nn = 0;
   Vm = 1;//������������ �������� ��������
k = 1;//��������� ������������������
G = 1;//�������� �������� �� ������
Go = 1;//����������, ��������������� ��������� ������
N = 1;//�������� �������� ������
alfa = 1;//���������� �������, ��������� �� ���� ������ � ��������
T = 1;//����� ������ ������
b = 1;//��������� ����� ������
betta = 1;//���������� �������, ��������� �� ��������� ������ � �����, � ������� �������� ������
nu = 1;//������������ �������� ��������
gamma = 1;//�������� ��� �������� ��������
tauo = 1;//������������ ���������� ������ ������� ��������
vkp = 1;//������� �������� ������� �������� �������� � ��������� ������������ ���������
//vkp = 1;//����������� �������� �������� ��������
Q = 1;//������ �������� ��������
D = 2;//������� �������� (������)
dn = 1;//�������� ������� ��������� ����
dny = 1;//�������� ������� ����������� ��������� ����(���)
dd = 1;//��������� ������� ����
dy = 1;//��������� ������� ���
ddo = 1;//������� ����������� ���������� ������� � ����������
Lc = 1;//������� ��������
L = 1;//����� ��������� ����
ly = 1;//����� ���
lt = 1;//����� ����� �����
P = 1;//�������� �������� �������� � ��������
Ppl = 1;//�������� ��������
alfaob = 1;//���������� �������
mu = 1;//��������� ������� �������� ��������
f = 1;//��������� ������� ������� ����������� ��������� ������
lambda = 1;//��������� ��������������� ������������� � ������
lambdakp = 1;//��������� ��������������� ������������� � ���������� ������������ ��������
lambdakpu = 1;//��������� ��������������� ������������� � ��������� ������������ ���
Gmin = 1;//����������� ������ �������� �� ������
Gmax = 1;//������������ ������ �������� �� ������
Nmin = 1;//����������� ������ �������� �������� ������
Nmax = 1;//������������ ������ �������� �������� ������
Pnd = 1;//���������� �������� �� ������
Pgr = 1;//�������� ������������ ������
Np = 1;//������������ �������� �������
Nr = 1;//�������������� �������� �������
}

//=================������� �������=====================

double Func()
{
return (k*(Y[0]-Go)*pow(Y[1],alfa));
}
 	//============����� ������ � �����������===============
//---------------------------------------------------------------------------
void __fastcall TForm4::FormCreate(TObject *Sender)
{

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
//====��������� ������ ���������� ����������===========

void FindLocalExtremum()
{
const double Eps=0.01;
const double H=0.01;
const double Delta=0.000001;
double N=0;
int i,j,z,x;
bool Stoplt;
double Norm, Num;
   for (int i=0; i<Vars; i++)
   {

   //=====��������: ������� < ��������====================

   if(Ymin[i]>=Ymax[i])
   {
   	MessageDlg("������� ������ ���� ������ ���������!",mtWarning,TMsgDlgButtons()<<mbOK,0);
   	break;
   }

   //===��������: ������� < ��������� �������� < ��������=

   	if((Y[i]<Ymin[i])||(Y[i]>Ymax[i]))
   	{
   		MessageDlg("��������� �������� ������ ���� � �������� ���������!",mtWarning,TMsgDlgButtons()<<mbOK,0);
   		break;
   	}
   }
Stoplt=false;

do
{
N=N+1; //���������� �����/����������� �����
for(int i=0;i<Vars;i++)
{
if ((Y[i]<Ymin[i])||(Y[i]>Ymax[i]))break;
Num=Y[i];
Y[i]=Y[i]+Delta;
NY[i]=Func();
Y[i]=Num;
NY[i]=(NY[i]-Func())/Delta; //�������� �������
}

//=================����� ���������=====================

Norm=0;
for (int i=0;i<Vars;i++)
Norm=Norm+pow(NY[i],2);
Norm=sqrt(Nrom); //����� ���������

//===========������������� �������� ���������==========

for (z=0;z<Vars;z++)
{
if (Norm>0)
NY[z]=Y[z]=NY[z]/Norm*H; //��������� �������� ��������� �������
else // � ������ ���������
NY[z]=Y[z]; //�������� ������� = �������� �������

//====��������, �� ������ �� �������� ��������� �� ��������� (Ymin[i];Ymax[z])====

if(NY[z]>Ymax[z])
NY[z]=Ymax[z];
else
if(NY[z]<Ymin[z])NY[z]=Ymin[z];
}
Num=0;

//====������ Num = |NY[1]-Y[1]|+|NY[2]-Y[2]| ��� �������� �������====

for (x=0;x<Vars;x++)
{
Num=Num+abs(NY[x]-Y[x]);
Y[x]=NY[x];
if(x==1)
G=int((Y[x]*1000000000.0+0.5)/1000000000.0); //�������� G
else
Np=(Y[x]=1000000000.0+0.5)/1000000000.0; //�������� n
}

//========�������� ���������� �����������========

if((k*G*Nr)>Np)
{
Stoplt=true; //���������� ���������� ���������
FindLocalExtremum();
Vm=(Func()*1000000000.0+0.5)/1000000000.0; //�������� Vm
Num=0;
}
}
while((Norm<=Eps)||(Num!=0)||(Stoplt!=true));
}

//---------------------------------------------------------------------------
//=========���������� ������ "����������"==========
void __fastcall TForm4::BitBtn1Click(TObject *Sender)
{
   double P1,P2,P3,P4;
   //=============�������� �������====================
   for(int i=0; i<=8; i++)
   Cnt->Cells[i][1]="";

   //====���������� ��������� ���������� (�������� � �����������)====

   Gmin=StrToFloat(Cnst->Cells[1][1]);
   Nmin=StrToFloat(Cnst->Cells[3][1]);
   Ymin[0]=Gmin;
   Gmax=StrToFloat(Cnst->Cells[2][1]);
   Ymax[0]=Gmax;
   Ymin[1]=Nmin;
   Nmax=StrToFloat(Cnst->Cells[4][1]);
   Ymax[1]=Nmax;
   Y[0]=Ymin[0]+1.0;
   Y[1]=Ymin[1]+1.0; //��������� �������� G � n
   Go=StrToFloat(Cnst->Cells[0][1]);
   alfa=StrToFloat(Kfc->Cells[1][1]);
   b=StrToFloat(Cnst->Cells[17][1]);
   D=StrToFloat(Cnst->Cells[5][1]);
   alfaob=StrToFloat(Kfc->Cells[7][1]);
   gamma=StrToFloat(Cnst->Cells[22][1]);
   lambda=StrToFloat(Kfc->Cells[4][1]);
   L=StrToFloat(Cnst->Cells[12][1]);
   dy=StrToFloat(Cnst->Cells[9][1]);
   lambdakpu=StrToFloat(Kfc->Cells[6][1]);
   dn=StrToFloat(Cnst->Cells[7][1]);
   ddo=StrToFloat(Cnst->Cells[10][1]);
   Np=StrToFloat(Cnst->Cells[20][1]);
   Nr=StrToFloat(Cnst->Cells[21][1]);
   k=StrToFloat(Kfc->Cells[0][1]);
   betta=StrToFloat(Kfc->Cells[2][1]);
   dd=StrToFloat(Cnst->Cells[6][1]);
   mu=StrToFloat(Kfc->Cells[3][1]);
   f=StrToFloat(Cnst->Cells[16][1]);
   lt=StrToFloat(Cnst->Cells[14][1]);
   ly=StrToFloat(Cnst->Cells[13][1]);
   lambdakp=StrToFloat(Kfc->Cells[5][1]);
   Lc=StrToFloat(Cnst->Cells[11][1]);
   dny=StrToFloat(Cnst->Cells[8][1]);
   Pnd=StrToFloat(Cnst->Cells[18][1]);
   Ppl=StrToFloat(Cnst->Cells[15][1]);
   Pgr=StrToFloat(Cnst->Cells[19][1]);
   FindLocalExtremum(); //����� ��������� FindLocalExtremum()
   if ((Y[0]>Ymin[0]+1.0) &&(Y[1]>Ymin[1]+1.0))
   {

   //======������ ����������� �������=============

   T=b/(Nn*pow(G,betta));
   nu = 0.33 * gamma - 0.22;
   tauo = 85 * gamma - 70;
   vkp = 0.25 * sqrt(tauo/gamma);
   Q=0.0785 * (pow(D,2) - pow(dd,2)) * vkp;
   P1 =alfaob + 0.51 / pow(mu*f,2) + 82.6*lambdakp;
   P2 = 82.6*lambda * (L/pow(dd,5)+ly/pow(dy, 5));
   P3 = lambdakpu* ly / (pow((pow(D,2)- pow(dny,2)),3)*pow(pow(D,2)+pow(dny,2),2));
   P4 = 1.67* pow(pow(dd/ddo,2)-1,2) * L/ (lt*pow(dd,4));
   P = gamma * pow(Q,2) * (P1 + P2 + P3 + P4);

   //========�������� ���������� �����������==========

   if ((P + gamma*Lc) <= Pnd )
   if ((P + gamma*Lc) <= Pgr )
   if ((k* P* Q)<=Nr)
   if (((Kgam* (Ppl+15000)/Lc) <= gamma) && (gamma <= (Kgam*(Ppl+25000)/Lc) ) )
   if ((Kqd* Q/ (pow(D,2)-pow(dn,2)) ) >= 0.4 )
   {

   //=======����� �������� ����������� �������� �������=========

   Cnt->Cells[3][1]= FloatToStrF(P, ffGeneral,9,5);
   Cnt->Cells[4][1]= FloatToStrF(Q, ffGeneral,5,5);
   Cnt->Cells[5][1]= FloatToStrF(T, ffGeneral,5,5);
   Cnt->Cells[6][1]= FloatToStrF(nu, ffGeneral,9,5);
   Cnt->Cells[7][1]= FloatToStrF(tauo, ffGeneral,9,5);
   Cnt->Cells[8][1]= FloatToStrF(vkp, ffGeneral,8,5);
   }
   Cnt->Cells[0][1]= FloatToStr(G);
   Cnt->Cells[1][1]= FloatToStrF(Nn, ffGeneral,8,5);
   Cnt->Cells[2][1]= FloatToStrF(Vm,ffGeneral,8,5);
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm4::N1Click(TObject *Sender)
{
	Form4->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm4::N2Click(TObject *Sender)
{
 	F1->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm4::N3Click(TObject *Sender)
{
	Form1->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm4::N4Click(TObject *Sender)
{
	Form2->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Button1Click(TObject *Sender)
{
	F1->Show();
}
//---------------------------------------------------------------------------

