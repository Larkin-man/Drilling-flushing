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
//=========��������� ������ ������ ���������=========

void WriteTxt(AnsiString text, TColor a)
{
I=text.Length(); //����� ���������
F1->Msg->Lines->Add(text); //����� ���������
F1->Msg->SelStart=lo;
F1->Msg->SelLength=1; //��������� ������ ���������� ���������
F1->Msg->SelAttributes->Color= a; //���� ������
lo= lo +1+2;
}

//-----------------------------------------------------
void __fastcall TF1::FormCreate(TObject*Sender)
{
lo=0;
}

//--------�������� � (�������� ������-------------
void __fastcall TF1::eMExit(TObject *Sender)
{
float M, Mt, Md, perc, na;
M=StrToFloat(eM->Text); //���������� �������� ����������
Mt= StrToFloat(eMt->Text);
Md= StrToFloat(eMd->Text);
if (Mt<Md)
{
perc=100*M/Mt; //���������� ����������� � � ��
if (perc>=90)
{
if (perc<95)
{
txt=FloatToStrF(perc, ffGeneral,4,2);
txt="�������� ������ ���������� "+txt+"% �� ����������� �� ����������� ����";
WriteTxt(txt, clLime); //����� ��������� ������ ����� ���������
}
else
{
na=(perc-94)*Mt/100; //���������� ��� ���������� ���������
txt=FloatToStrF(na,ffGeneral,4,2);
txt="�������� ������ ������ ����������� �� "+txt+"�*�";
WriteTxt(txt,clRed); //����� ��������� ������ ������ ���������
sndPlaySound("Error.WAV", SND_ASYNC); //�������� ������
}
}
}
else
{
perc= 100*M/Md; //���������� ����������� � � ��
if (perc>=90)
{
if (perc<95)
{
txt= FloatToStrF (perc, ffGeneral, 4,2);
txt= "�������� ������ ���������� "+txt+"% �� ����������� �� ��������� ������";
WriteTxt(txt, clLime);  //����� ��������� ������ ������ ���������
}
else
{
na=(perc-94)*Md/100; //���������� ��� ���������� ���������
txt=FloatToStrF(na, ffGeneral, 4,2);
txt="�������� ������ ������ ����������� �� "+txt+" H*M.";
WriteTxt(txt, clRed); //����� ��������� ������ ������ ���������
sndPlaySound("Error.WAV", SND_ASYNC); //�������� ������
}
}
}
}

//-----------------------------------------------------
void __fastcall TF1::eGkExit(TObject*Sender)
{
float Gk, Gkmk, Gkml, perc, na;
Gk=StrToFloat(eGk->Text); //���������� �������� ����������
Gkml=StrToFloat(eGkml->Text);
Gkmk=StrToFloat(eGkmk->Text);
if (Gkml<Gkmk)
{
perc=100*Gk/Gkml;  //���������� ����������� Gk � Gk��
if (perc>=90)
{
if (perc<95)
{
txt=FloatToStrF(perc,ffGeneral,4,2);
txt="��� �� ����� ���������� "+txt+"% �� ����������� �� ��������� ������.";
WriteTxt(txt,clLime); //����� ��������� ������ ������ ���������
}
else
{
na=(perc-94)*Gkml/100; //���������� ��� ���������� ���������
txt=FloatToStrF(na,ffGeneral,4,2);
txt="��� �� ����� ������ ����������� �� "+txt+" ����.";
WriteTxt(txt,clRed); //����� ��������� ������ ������ ���������
sndPlaySound("Error.WAV",SND_ASYNC); //�������� ������
}
}
}
else
{
perc=100*Gk/Gkmk; //���������� ����������� Gk � Gkmk
if (perc>=90)
{
if (perc<95)
{
txt=FloatToStrF (perc,ffGeneral,4,2);
txt="��� �� ����� ���������� "+txt+"% �� ����������� �� ��������� ������.";
WriteTxt(txt,clLime); //����� ��������� ������ ������ ���������
}
else
{
na=(perc-94)*Gkmk/100;  //���������� ��� ��������� ���������
txt=FloatToStrF(na,ffGeneral,4,2);
txt="��� �� ����� ������ ����������� �� "+txt+" ����.";
WriteTxt(txt,clRed); //����� ��������� ������ ������ ���������
sndPlaySound("Error.WAV",SND_ASYNC); //�������� ������
}
}
}
}

//-----------------------------------------------------
void __fastcall TF1::eGktExit(TObject *Sender)
{
float before,Gki,ti,Sum,Ar,perc;
AnsiString all, temp;
int i,j, n, beg;
all= eGkt->Text;
Ar= StrToFloat(eAr->Text); //���������� �������� ����������
n= all.Length();
temp="";
beg=1;
Gki=0;
ti=0;
before=0;
for(i=1;i<=n;i++) //��������� �������� �� ������� ���� Sum+Gki*ti'
{
if((all[i]=='+')&&(i>1))
{
for(j=1;j<=(i-1);j++)
temp=temp + all[j];
before=StrToFloat(temp); //���������� �� ������� �������� Sum
temp="";
beg=i+1;
}
else
if (all[i]=='*')
{
for (j=beg; j<=(i-1); j++)
temp= temp + all[j];
Gki= StrToFloat(temp); //���������� �� ������� �������� Gki
temp="";
for (j=i+1;j<=n;j++)
temp= temp + all[j];
ti=StrToFloat(temp); //���������� �� ������� �������� ti
}
}
if ((Gki==0) && (ti==0) && (before==0))
Sum= StrToFloat(eGkt->Text); //���� ������ ������� ������� ���� �����
else
Sum= before + Gki * ti; //����� ���������� �� �������
if (Ar>=Sum)
{
perc= 100*Sum/Ar; //���������� ����������� Sum � Ar
if (perc>=90)
{
if (perc<95)
{
txt= FloatToStrF((Ar-Sum), ffGeneral,4,2);
txt= "������ �������� ������ ������������ "+txt+" �����-�����.";
WriteTxt(txt,clLime); //����� ��������� ������ ������ ���������
}
else
{
txt= FloatToStrF((Ar-Sum),ffGeneral,4,2);
txt= "������ �������� ������ ������������ ����� "+txt+" �����-�����.";
WriteTxt(txt, clRed); //����� ��������� ������ ������ ���������
sndPlaySound("Error.WAV", SND_ASYNC); //�������� ������
}
}
}
else if (Ar<Sum)
{
txt= FloatToStrF((Sum-Ar),ffGeneral,4,2);
txt="������ �������� ������ �������� �� "+txt+" �����-�����.";
WriteTxt(txt,clRed); //����� ��������� ������ ������ ���������
sndPlaySound("Error.WAV",SND_ASYNC);//�������� ������
}
}

//-----------------------------------------------------
void __fastcall TF1::eTvrExit(TObject*Sender)
{
float Tvr, Tvrd, perc;
Tvr= StrToFloat(eTvr->Text); //���������� �������� ����������
Tvrd= StrToFloat(eTvrd->Text);
if (Tvr<=Tvrd)
{
perc= 100*Tvr/Tvrd; //���������� ����������� Tvr � Tvrd
if (perc>=90)
if (perc<95)
{
txt= FloatToStrF((Tvrd-Tvr),ffGeneral,4,2);
txt= "���������� ����� ��� �������� ������� �������� ����� "+txt+" ���.";
WriteTxt(txt, clLime); //����� ��������� ������ ������ ���������
}
else
{
txt= FloatToStrF ((Tvrd-Tvr), ffGeneral,4,2);
txt= "���������� ����� ��� �������� ������� �������� ����� "+txt+" ���.";
WriteTxt(txt,clRed); //����� ��������� ������ ������ ���������
sndPlaySound("Error.WAV",SND_ASYNC); //�������� ������
}
}
else if (Tvr>Tvrd)
{
txt=FloatToStrF((Tvr-Tvrd),ffGeneral,4,2);
txt="���������� ����� ��� �������� ������� ��������� �� "+txt+" ���.";
WriteTxt(txt,clRed); //����� ��������� ������ ������ ���������
sndPlaySound("Error.WAV",SND_ASYNC); //�������� ������
}
//}
else if (Tvr>Tvrd)
{
txt=FloatToStrF((Tvr-Tvrd),ffGeneral,4,2);
txt="���������� ����� ��� �������� ������� ��������� �� "+txt+" ���.";
WriteTxt(txt,clRed); //����� ��������� ������ ������ ���������
//sndplaySound("Error.WAV",SND_ASYNC); //�������� ������
}
}

//-----------------------------------------------------
void __fastcall TF1::eTprExit(TObject*Sender)
{
float Tpr, Tprd, pere;
Tpr= StrToFloat(eTpr->Text); //���������� �������� ����������
Tprd= StrToFloat(eTprd->Text);
if (Tpr<=Tprd)
{
pere= 100*Tpr/Tprd; //���������� ����������� Tpr � Tprd
if (pere>=90)
if (pere<95)
{
txt=FloatToStrF((Tprd-Tpr),ffGeneral,4,2);
txt="���������� ����� ��� �������� �������� �������� ����� "+txt+" ���.";
WriteTxt(txt, clLime); //����� ��������� ������ ������ ���������
}
else
{
txt= FloatToStrF((Tprd-Tpr),ffGeneral,4,2);
txt="���������� ����� ��� �������� �������� �������� ����� "+txt+" ���.";
WriteTxt(txt,clRed); //����� ��������� ������ ������ ���������
sndPlaySound("Error.WAV", SND_ASYNC); //�������� ������
}
}
else if (Tpr>Tprd)
{
txt= FloatToStrF((Tpr-Tprd),ffGeneral,4,2);
txt= "���������� ����� ��� �������� �������� ��������� �� "+txt+" ���.";
WriteTxt(txt,clRed);  //����� ��������� ������ ������ ���������
sndPlaySound("Error.WAV", SND_ASYNC); //�������� ������
}
}

//-----------------------------------------------------
void __fastcall TF1::eTbExit(TObject*Sender)
{
float Tb, Tbd, perc;
Tb= StrToFloat(eTb->Text); //���������� ������ ���������� Tbd
StrToFloat(eTbd->Text);
if (Tb<=Tbd)
{
perc= 100*Tb/Tbd; //���������� ����������� Tb � Tbd
if (perc>=90)
if (perc<95)
{
txt= FloatToStrF((Tbd-Tb),ffGeneral,4,2);
txt= "��������������� ��� ������� �������� ����� "+txt+" ���.";
WriteTxt(txt, clLime); //����� ��������� ������ ������ ���������
}
else
{
txt=FloatToStrF((Tbd-Tb),ffGeneral,4,2);
txt="���������� ����� ��� ������� �������� ����� "+txt+" ���.";
WriteTxt(txt,clLime); //����� ��������� ������ ������ ���������
}
else
{
txt=FloatToStrF((Tbd-Tb),ffGeneral,4,2);
txt="���������� ����� ��� ������� �������� ����� "+txt+" ���.";
WriteTxt(txt, clRed); //����� ��������� ������ ������ ���������
sndPlaySound("Error. WAV", SND_ASYNC); //�������� ������
}
}
else if (Tb>Tbd)
{
txt= FloatToStrF((Tb-Tbd),ffGeneral,4,2);
txt= "���������� ����� ��� ������� ���������� �� "+txt+" ���.";
WriteTxt(txt, clRed); //����� ��������� ������ ������ ���������
sndPlaySound("Error.WAV", SND_ASYNC); //�������� ������
}
}

//-----------------------------------------------------
void _fastcall TF1::Panel1Exit(TObject*Sender)
{
float k1, dn, dt, L, Vdr, Vk, perc, na;
k1= StrToFloat(eK1->Text); //���������� �������� ����������
dn= StrToFloat(eDn->Text);
dt= StrToFloat(eDt->Text);
L= StrToFloat(eL->Text);
Vdr= StrToFloat(eVdr->Text);
Vk=k1*(pow(dn,2)-pow(dt,2))*L; //���������� ������ ������� VK
if (Vk<=Vdr)
{
perc= 100*Vk/Vdr; //���������� ����������� VK � Vdr
if (perc>=90)
if (perc<95)
{
txt= FloatToStrF (perc,ffGeneral,4,2);
txt="��������� ������ � �������� "+txt+" � ��������.";
WriteTxt(txt,clLime); //����� ��������� ������ ������ ���������
}
else
{
na=(perc-94)*Vdr/100; //���������� ��� ���������� ���������
txt= FloatToStrF(na,ffGeneral,4,2);
txt="��������� ������ � �������� "+txt+" � ��������. �������� ����������!";
WriteTxt(txt,clRed); //����� ��������� ������ ������ ���������
sndPlaySound("Error.WAV",SND_ASYNC); //�������� ������
}
}
}

//-----------------------------------------------------
void __fastcall TF1::Panel2Exit(TObject *Sender)
{
float Pc, P1, Pobd, k2, Qk, gamma, D, dt, dn, tp, perc, na, L;
Pc=StrToFloat(eP�->Text); //���������� �������� ����������
Pobd= StrToFloat(ePobd->Text);
k2= StrToFloat(eK2->Text);
Qk= StrToFloat(eQk->Text);
gamma= StrToFloat(egamma->Text);
D= StrToFloat(eD->Text);
tp= StrToFloat(eTp->Text);
dt= StrToFloat(eDt->Text);
dn= StrToFloat(eDn->Text);
L= StrToFloat(eL->Text);
if (D!=dn) //���� ��� ������, ��������� �������� �1
P1= Pc+ k2*Qk*gamma*L/(tp*(pow(D,2)-pow(dn,2))) +k2*Qk*gamma*L/pow(dt,2);
else
MessageDlg("D ������ ���� ������ ��� ����� dn!", mtError,
TMsgDlgButtons()<<mbOK,0); //����� ��������� �� ������ � ������
if (P1<Pobd)
{
perc= 100*P1/Pobd; //���������� ����������� �1 � Pobd
if (perc>=90)
if (perc<95)
{
txt= FloatToStrF(perc,ffGeneral,4,2);
txt= "���������� �������� � ������� ���������� "+txt+"% �� �����������.";
WriteTxt(txt, clLime); //����� ��������� ������ ������ ���������
}
else
{
na= (perc-94)*Pobd/100;  //���������� �1 ��� ���������� ���������
txt= FloatToStrF(na,ffGeneral,4,2);
txt= "���������� �������� � ������� ��������� �� "+txt+" H*�2.";
WriteTxt(txt, clRed); //����� ��������� ������ ������ ���������
sndPlaySound("Error.WAV",SND_ASYNC); //�������� ������
}
}
}

//-----------------------------------------------------
void __fastcall TF1::ePspoExit(TObject *Sender)
{
float Pspo, Pgr, perc, na;
Pspo= StrToFloat(ePspo->Text); //���������� �������� ����������
Pgr= StrToFloat(ePgr->Text);
if (Pspo<perc)
{
perc= 100*Pspo/Pgr; //���������� ����������� Pspo � Pgr
if (perc>=90)
if (perc<95)
{
txt= FloatToStrF (perc,ffGeneral,4,2);
txt= "�������� �� ����� ��� ������ ���������� "+txt+"% �� �����������.";
WriteTxt(txt, clLime); //����� ��������� ������ ������ ���������
}
else
{
na= (perc-94)*Pgr/100; //���������� ��� ���������� ���������
txt= FloatToStrF(na,ffGeneral,4,2);
txt= "���������� �������� �� ����� ��� ������ �������� �� "+txt+" H*2. �������� ����������� ������!";
WriteTxt(txt, clRed); //����� ��������� ������ ������ ���������
sndPlaySound("Error.WAV", SND_ASYNC); //�������� ������
}
}
}
//-----------------------------------------------------
extern double L;
extern double Lc;//
float ch, na;//, d5;
void __fastcall TF1::eL�Exit(TObject *Sender)
{

L= StrToFloat(eL->Text); //���������� �������� ����������
Lc= StrToFloat(eL�->Text);
//d5= StrToFloat(e5->Text);
ch= Lc - L; //���������� ������� L� � L
if (ch<=10)
if (ch<=5)
{
txt= FloatToStrF(ch,ffGeneral,4,2);
txt= "�� ����� �������� "+txt+" �.";
WriteTxt(txt,clRed); //����� ��������� ������ ������ ���������
sndPlaySound("Error.WAV",SND_ASYNC); //�������� ������
}
else
{
txt=FloatToStrF(ch,ffGeneral,4,2);
txt="�� ����� �������� "+txt+" �.";
WriteTxt(txt, clLime); //����� ��������� ������ ������ ���������
}
}
//---------------------------------------------------------------------------

void __fastcall TF1::Button1Click(TObject *Sender)
{
	Form4->Show();
   F1->Close();
}
//---------------------------------------------------------------------------

