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
//=========Процедура вывода нового сообщения=========

void WriteTxt(AnsiString text, TColor a)
{
I=text.Length(); //Длина сообщения
F1->Msg->Lines->Add(text); //Вывод сообщения
F1->Msg->SelStart=lo;
F1->Msg->SelLength=1; //Выделение текста последнего сообщения
F1->Msg->SelAttributes->Color= a; //Цвет шрифта
lo= lo +1+2;
}

//-----------------------------------------------------
void __fastcall TF1::FormCreate(TObject*Sender)
{
lo=0;
}

//--------проверка М (крутящий момент-------------
void __fastcall TF1::eMExit(TObject *Sender)
{
float M, Mt, Md, perc, na;
M=StrToFloat(eM->Text); //Считывание значений параметров
Mt= StrToFloat(eMt->Text);
Md= StrToFloat(eMd->Text);
if (Mt<Md)
{
perc=100*M/Mt; //Процентное соотношение М и Мт
if (perc>=90)
{
if (perc<95)
{
txt=FloatToStrF(perc, ffGeneral,4,2);
txt="Крутящий момент составляет "+txt+"% от допустимого по скручиванию труб";
WriteTxt(txt, clLime); //Вызов процедуры вывода новго сообщения
}
else
{
na=(perc-94)*Mt/100; //Превышение над допустимым значением
txt=FloatToStrF(na,ffGeneral,4,2);
txt="Крутящий момент больше допустимого на "+txt+"Н*м";
WriteTxt(txt,clRed); //Вызов процедуры вывода нового сообщения
sndPlaySound("Error.WAV", SND_ASYNC); //звуковой сигнал
}
}
}
else
{
perc= 100*M/Md; //процентное соотношение М и Мд
if (perc>=90)
{
if (perc<95)
{
txt= FloatToStrF (perc, ffGeneral, 4,2);
txt= "Крутящий момент составляет "+txt+"% от допустимого по прочности долота";
WriteTxt(txt, clLime);  //Вызов процедуры вывода нового сообщения
}
else
{
na=(perc-94)*Md/100; //Превышение над допустимым значением
txt=FloatToStrF(na, ffGeneral, 4,2);
txt="Крутящий момент больше допустимого на "+txt+" H*M.";
WriteTxt(txt, clRed); //Вызов процедуры вывода нового сообщения
sndPlaySound("Error.WAV", SND_ASYNC); //звуковой сигнал
}
}
}
}

//-----------------------------------------------------
void __fastcall TF1::eGkExit(TObject*Sender)
{
float Gk, Gkmk, Gkml, perc, na;
Gk=StrToFloat(eGk->Text); //Считывание значений параметров
Gkml=StrToFloat(eGkml->Text);
Gkmk=StrToFloat(eGkmk->Text);
if (Gkml<Gkmk)
{
perc=100*Gk/Gkml;  //Процентное соотношение Gk м Gkмл
if (perc>=90)
{
if (perc<95)
{
txt=FloatToStrF(perc,ffGeneral,4,2);
txt="Вес на крюке составляет "+txt+"% от допустимого по прочности лебёдки.";
WriteTxt(txt,clLime); //Вызов процедуры вывода нового сообщения
}
else
{
na=(perc-94)*Gkml/100; //Превышение над допустимым значением
txt=FloatToStrF(na,ffGeneral,4,2);
txt="Вес на крюке больше допустимого на "+txt+" тонн.";
WriteTxt(txt,clRed); //Вызов процедуры вывода нового сообщения
sndPlaySound("Error.WAV",SND_ASYNC); //Звуковой сигнал
}
}
}
else
{
perc=100*Gk/Gkmk; //процентное соотношение Gk и Gkmk
if (perc>=90)
{
if (perc<95)
{
txt=FloatToStrF (perc,ffGeneral,4,2);
txt="Вес на крюке составляет "+txt+"% от допустимого по прочности каната.";
WriteTxt(txt,clLime); //Вызов процедуры вывода нового сообщения
}
else
{
na=(perc-94)*Gkmk/100;  //Первышение над допустиыи значением
txt=FloatToStrF(na,ffGeneral,4,2);
txt="Вес на крюке больше допустимого на "+txt+" тонн.";
WriteTxt(txt,clRed); //Вызов процедуры вывода нового сообщения
sndPlaySound("Error.WAV",SND_ASYNC); //Звуковой сигнал
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
Ar= StrToFloat(eAr->Text); //Считывание значений параметров
n= all.Length();
temp="";
beg=1;
Gki=0;
ti=0;
before=0;
for(i=1;i<=n;i++) //Выявление значений из формулы вида Sum+Gki*ti'
{
if((all[i]=='+')&&(i>1))
{
for(j=1;j<=(i-1);j++)
temp=temp + all[j];
before=StrToFloat(temp); //Извлечение из формулы значений Sum
temp="";
beg=i+1;
}
else
if (all[i]=='*')
{
for (j=beg; j<=(i-1); j++)
temp= temp + all[j];
Gki= StrToFloat(temp); //Извлечение из формулы значений Gki
temp="";
for (j=i+1;j<=n;j++)
temp= temp + all[j];
ti=StrToFloat(temp); //Извлечение из формулы значения ti
}
}
if ((Gki==0) && (ti==0) && (before==0))
Sum= StrToFloat(eGkt->Text); //Если вместо формулы введено одно число
else
Sum= before + Gki * ti; //иначе вычисление по формуле
if (Ar>=Sum)
{
perc= 100*Sum/Ar; //процентное соотношение Sum и Ar
if (perc>=90)
{
if (perc<95)
{
txt= FloatToStrF((Ar-Sum), ffGeneral,4,2);
txt= "Ресурс талевого каната выработается "+txt+" тонно-часов.";
WriteTxt(txt,clLime); //Вызов процедуры вывода нового сообщения
}
else
{
txt= FloatToStrF((Ar-Sum),ffGeneral,4,2);
txt= "Ресурс талевого каната выработается через "+txt+" тонно-часов.";
WriteTxt(txt, clRed); //Вызов процедуры вывода нового сообщения
sndPlaySound("Error.WAV", SND_ASYNC); //Звуковой сигнал
}
}
}
else if (Ar<Sum)
{
txt= FloatToStrF((Sum-Ar),ffGeneral,4,2);
txt="Ресурс талевого каната превышен на "+txt+" тонно-часов.";
WriteTxt(txt,clRed); //Вызов процедуры вывода нового сообщения
sndPlaySound("Error.WAV",SND_ASYNC);//звуковой сигнал
}
}

//-----------------------------------------------------
void __fastcall TF1::eTvrExit(TObject*Sender)
{
float Tvr, Tvrd, perc;
Tvr= StrToFloat(eTvr->Text); //Считывание значений параметров
Tvrd= StrToFloat(eTvrd->Text);
if (Tvr<=Tvrd)
{
perc= 100*Tvr/Tvrd; //процентное соотношение Tvr и Tvrd
if (perc>=90)
if (perc<95)
{
txt= FloatToStrF((Tvrd-Tvr),ffGeneral,4,2);
txt= "Допустимое время без вращения колонны истекает через "+txt+" мин.";
WriteTxt(txt, clLime); //Вызов процедуры вывода нового сообщения
}
else
{
txt= FloatToStrF ((Tvrd-Tvr), ffGeneral,4,2);
txt= "Допустимое время без вращения колонны истекает через "+txt+" мин.";
WriteTxt(txt,clRed); //Вызов процедуры вывода нового сообщения
sndPlaySound("Error.WAV",SND_ASYNC); //Звуковой сигнал
}
}
else if (Tvr>Tvrd)
{
txt=FloatToStrF((Tvr-Tvrd),ffGeneral,4,2);
txt="Допустимое время без вращения колонны превышает на "+txt+" мин.";
WriteTxt(txt,clRed); //Вызов процедуры вывода нового сообщения
sndPlaySound("Error.WAV",SND_ASYNC); //Звуковой сигнал
}
//}
else if (Tvr>Tvrd)
{
txt=FloatToStrF((Tvr-Tvrd),ffGeneral,4,2);
txt="Допустимое время без вращения колонны превышено на "+txt+" мин.";
WriteTxt(txt,clRed); //Вызов процедуры вывода нового сообщения
//sndplaySound("Error.WAV",SND_ASYNC); //Звукрвой сигнал
}
}

//-----------------------------------------------------
void __fastcall TF1::eTprExit(TObject*Sender)
{
float Tpr, Tprd, pere;
Tpr= StrToFloat(eTpr->Text); //Считывание значений параметров
Tprd= StrToFloat(eTprd->Text);
if (Tpr<=Tprd)
{
pere= 100*Tpr/Tprd; //процентное соотношение Tpr и Tprd
if (pere>=90)
if (pere<95)
{
txt=FloatToStrF((Tprd-Tpr),ffGeneral,4,2);
txt="Допустимое время без промывки скважины истекает через "+txt+" мин.";
WriteTxt(txt, clLime); //Вызов процедуры вывода нового сообщения
}
else
{
txt= FloatToStrF((Tprd-Tpr),ffGeneral,4,2);
txt="Допустимое время без промывки скважины истекает через "+txt+" мин.";
WriteTxt(txt,clRed); //Вызов процедуры вывода нового сообщения
sndPlaySound("Error.WAV", SND_ASYNC); //звуковой сигнал
}
}
else if (Tpr>Tprd)
{
txt= FloatToStrF((Tpr-Tprd),ffGeneral,4,2);
txt= "Допустимое время без промывки скважины превышено на "+txt+" мин.";
WriteTxt(txt,clRed);  //Вызов процедуры вывода нового сообщения
sndPlaySound("Error.WAV", SND_ASYNC); //звуковой сигнал
}
}

//-----------------------------------------------------
void __fastcall TF1::eTbExit(TObject*Sender)
{
float Tb, Tbd, perc;
Tb= StrToFloat(eTb->Text); //Считывание знаний параметров Tbd
StrToFloat(eTbd->Text);
if (Tb<=Tbd)
{
perc= 100*Tb/Tbd; //процентное соотношение Tb и Tbd
if (perc>=90)
if (perc<95)
{
txt= FloatToStrF((Tbd-Tb),ffGeneral,4,2);
txt= "допустимоевремя без бурения истекает через "+txt+" мин.";
WriteTxt(txt, clLime); //вызов процедуры вывода нового сообщения
}
else
{
txt=FloatToStrF((Tbd-Tb),ffGeneral,4,2);
txt="Допустимое время без бурения истекает через "+txt+" мин.";
WriteTxt(txt,clLime); //вызов процедуры вывода нового сообщения
}
else
{
txt=FloatToStrF((Tbd-Tb),ffGeneral,4,2);
txt="Допустимое время без бурения истекает через "+txt+" мин.";
WriteTxt(txt, clRed); //Вызов процедура вывода нового сообщения
sndPlaySound("Error. WAV", SND_ASYNC); //звуковой сигнал
}
}
else if (Tb>Tbd)
{
txt= FloatToStrF((Tb-Tbd),ffGeneral,4,2);
txt= "Допустимое время без бурения превышенно на "+txt+" мин.";
WriteTxt(txt, clRed); //вызов процедуры вывода нового сообщения
sndPlaySound("Error.WAV", SND_ASYNC); //звуковой сигнал
}
}

//-----------------------------------------------------
void _fastcall TF1::Panel1Exit(TObject*Sender)
{
float k1, dn, dt, L, Vdr, Vk, perc, na;
k1= StrToFloat(eK1->Text); //Считывание значений параметров
dn= StrToFloat(eDn->Text);
dt= StrToFloat(eDt->Text);
L= StrToFloat(eL->Text);
Vdr= StrToFloat(eVdr->Text);
Vk=k1*(pow(dn,2)-pow(dt,2))*L; //Вычисление объема колонны VK
if (Vk<=Vdr)
{
perc= 100*Vk/Vdr; //процентное соотношение VK и Vdr
if (perc>=90)
if (perc<95)
{
txt= FloatToStrF (perc,ffGeneral,4,2);
txt="Требуется долить в скважину "+txt+" л раствора.";
WriteTxt(txt,clLime); //вызов процедуры вывода нового сообщения
}
else
{
na=(perc-94)*Vdr/100; //первышения над допустимым значением
txt= FloatToStrF(na,ffGeneral,4,2);
txt="Требуется долить в скважину "+txt+" л раствора. Возможно проявления!";
WriteTxt(txt,clRed); //Вызов процедуры вывода нового сообщения
sndPlaySound("Error.WAV",SND_ASYNC); //звуковой сигнал
}
}
}

//-----------------------------------------------------
void __fastcall TF1::Panel2Exit(TObject *Sender)
{
float Pc, P1, Pobd, k2, Qk, gamma, D, dt, dn, tp, perc, na, L;
Pc=StrToFloat(ePс->Text); //Считывание значений параметров
Pobd= StrToFloat(ePobd->Text);
k2= StrToFloat(eK2->Text);
Qk= StrToFloat(eQk->Text);
gamma= StrToFloat(egamma->Text);
D= StrToFloat(eD->Text);
tp= StrToFloat(eTp->Text);
dt= StrToFloat(eDt->Text);
dn= StrToFloat(eDn->Text);
L= StrToFloat(eL->Text);
if (D!=dn) //Если нет ошибки, вычиление давление Р1
P1= Pc+ k2*Qk*gamma*L/(tp*(pow(D,2)-pow(dn,2))) +k2*Qk*gamma*L/pow(dt,2);
else
MessageDlg("D должно быть больше или равно dn!", mtError,
TMsgDlgButtons()<<mbOK,0); //иначе сообщение об ошибке в данных
if (P1<Pobd)
{
perc= 100*P1/Pobd; //процентное соотношение Р1 и Pobd
if (perc>=90)
if (perc<95)
{
txt= FloatToStrF(perc,ffGeneral,4,2);
txt= "Допустимое давление в обвязке составляет "+txt+"% от допустимого.";
WriteTxt(txt, clLime); //Вызов процедуры вывода нового сообщения
}
else
{
na= (perc-94)*Pobd/100;  //Превышение Р1 над допустимым значением
txt= FloatToStrF(na,ffGeneral,4,2);
txt= "Допустимое давление в обвязке превышено на "+txt+" H*м2.";
WriteTxt(txt, clRed); //вызов процедуры вывода нового сообщения
sndPlaySound("Error.WAV",SND_ASYNC); //Звуковой сигнал
}
}
}

//-----------------------------------------------------
void __fastcall TF1::ePspoExit(TObject *Sender)
{
float Pspo, Pgr, perc, na;
Pspo= StrToFloat(ePspo->Text); //Считывание значений параметров
Pgr= StrToFloat(ePgr->Text);
if (Pspo<perc)
{
perc= 100*Pspo/Pgr; //процентное соотношение Pspo и Pgr
if (perc>=90)
if (perc<95)
{
txt= FloatToStrF (perc,ffGeneral,4,2);
txt= "давление на пласт при спуске составляет "+txt+"% от допустимого.";
WriteTxt(txt, clLime); //вызов процедуры вывода нового сообщения
}
else
{
na= (perc-94)*Pgr/100; //превышение над допустимым значением
txt= FloatToStrF(na,ffGeneral,4,2);
txt= "допустимое давление на пласт при спуске превышен на "+txt+" H*2. Возможен гидроразрыв пласта!";
WriteTxt(txt, clRed); //вызов процедуры вывода нового сообщения
sndPlaySound("Error.WAV", SND_ASYNC); //звуковой сигнал
}
}
}
//-----------------------------------------------------
extern double L;
extern double Lc;//
float ch, na;//, d5;
void __fastcall TF1::eLсExit(TObject *Sender)
{

L= StrToFloat(eL->Text); //считывания значений параметров
Lc= StrToFloat(eLс->Text);
//d5= StrToFloat(e5->Text);
ch= Lc - L; //вычисление разницы Lс и L
if (ch<=10)
if (ch<=5)
{
txt= FloatToStrF(ch,ffGeneral,4,2);
txt= "до забоя осталось "+txt+" м.";
WriteTxt(txt,clRed); //вызов процедуры вывода нового сообщения
sndPlaySound("Error.WAV",SND_ASYNC); //звуковой сигнал
}
else
{
txt=FloatToStrF(ch,ffGeneral,4,2);
txt="до забоя осталось "+txt+" м.";
WriteTxt(txt, clLime); //вызов процедуры вывода нового сообщения
}
}
//---------------------------------------------------------------------------

void __fastcall TF1::Button1Click(TObject *Sender)
{
	Form4->Show();
   F1->Close();
}
//---------------------------------------------------------------------------

