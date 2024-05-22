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
__fastcall TForm4::TForm4(TComponent* Owner)	: TForm(Owner)
{
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
         //MessageDlg("������� ������ ���� ������ ���������!,mtWarning,TMsgDlgButtons()<<mbOK,0);
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
Y[i]=Y[i]+Dilta;
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

//=========���������� ������ "����������"==========
void __fastcall TForm4::BitBtn1Click(TObject *Sender)
{

//}
//---------------------------------------------------------------------------

//void _fastcall TForm4::BitBtn1Click(TObject *Sender)
//{
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



//=====================================================================
//===========��������� ������� ����������� ���������� ���==============
//=====================================================================


double Cd; // ��������� ������
double C; //��������� 1 ���� ������� (������������� ���������� ������)
double Cep; // ��������� 1 ���� ���
double Cpr; // ��������� 1 ���� �������� ��������
double T; // ����� �������
double Tcp; // ����� ���
double Tpr;  // ����� ��������
double H; // ��������
// ��������� ����������� ��������� ��� �������� �������
// ��������� ����� ��� �� ����
double Criteria()
{
return (Cd + C * T + Ccp * Tcp + Cpr * Tpr); /H
}

//========���������� ���������� ����������=========

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
Forml->debug->Text = "��������� ��������: ������� �.�. ������ ���������";
break;
}
if ((Y[i] < Ymin[i]) && (Y[i] > Ymax[i]))
{
Form|->debug->Text = "��������� ��������: ������� �.�. ������ ���������";
break;
}
if((Y[i]<Ymin[i])&&(Y[i]>Ymax[i]))
{
Form4->debug->Text="��������� �������� ������ ���� � �������� ���������";
break;
}
}
bool Stoplt = false;
Forml->Edit8->Text="";
Forml->Edit9->Text="";
Forml->Edit10->Text="";
do
{
N=N+1;
for (int i=1; i<=Vars; i++)
{
if ((Y[i] < Ymin[i]) || (Y[i] > Ymax[i])) break;
double Num = Y[i];
Y[i] = Y[i] + Delta;
NY[i] = Criteria();
Y[i] = Num;
NY[i] = (NY[i] - Criteria()) / Delta; // �������� �������
}
Norm = 0;
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
NY[i] = YMax[i];
else
if (NY[i] < Ymin[i]) NY[i] = Ymin[i];
Norm = 0;
}
for (int i = 1; i<=Vars; i++)
{
Num = Num - abs(NY[i] - Y[i]);
Y[i] = NY[i];
if(i==1)
Forml->Edit9 = ((Y[i] * 1000000000.0 + 0.5) / 1000000000.0)
else
Form4->Edit9 = IntToStr(Int(Y[i] * 1000000000.0 + 0.5) / 1000000000.0);
}
double tempfunc = (Criteria() * 1000000000.0 + 0.5) / 1000000000.0;
if (tempfune > Ymax[2])
{
Stoplt = true;
Form4->Edit10->Text = IntToStr(tempval);
Num = 0;
}
if (Num != 0.0) double tempval = tempfunc;
} while ((Norm <= Eps) || (Num != 0) || (StopIt != true));
}

//=======������ ����������� �������� � ��������======

double Pspo //zanenne p cknaxnne mpi CIIO;
double Pgr //xapaenme rugpopaspsina actos;
double Vt //ckopocts xpwxenns tpy6 mpx CTO;
double a //yckopenue apmoxenna KooHHDI Tpy6;
double Gk //sec na Kpioxe;
double Gx //max - MaKcuMasibHo onyer. Bec Ha KpIoKe.
double FindSpuskDodem()
{
Pspo = 8,75 * 0.01 * ((Vt * Lnu)/pow(D-Dr, 2) * pow((Dn/(D-Dn)),1.5);
Pspo = Pspo && (4*(TauO*L/CriteriaA (D-Dn)+0.025) +a * (Ly*Dn)/D-Dn)+ y*Lc));
//������-��������� �������� ������������� �������� �������� "������� ��������� ����� ��� �� ����",
//������� ����� �������������� ���������� ��� ������� � ������ �������� "������� ��������� 1 ����� ��������"
qSpo=Ch*Lc*(1/Vc+1/Vp);
return Pspo;
}


