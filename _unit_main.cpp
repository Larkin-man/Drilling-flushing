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
//Блок переменных, используемых при нахождении максимума функции
double Y[Vars]; //Хранит промежутчные значения G и n
double NY[Vars]; //Значения соответствующих градиентов функции
double Ymin[Vars];
double Ymax[Vars];
//Блок переменных, используемых для хранения технологических констант, коэффицентов и значений других параметров
double Vm ;//Механическая скорость проходки
double k ;//Коэфицент пропорциональности
double G ;//Основная нагрузка на долото
double Go ;//Показатель, характеризующий прочность породы
double N ;//Скорость вращения ротора
double alfa ;//Показатель степени, зависящий от типа долота и качества
double T ;//Время работы долота
double b ;//Постояная опоры долота
double betta ;//показатель степени, зависящий от твердости породы и среды, в которой работает долото
double nu ;//Пластическая вязкость раствора
double gamma ;//Удельный вес бурового раствора
double tauo ;//Динамическое напряжение сдвига буровго раствора
double vkp ;//Средняя скорость течения бурового раствора в кольцевом пространстве скаважины
//double vkp ;//Критическая скорость движения раствора
double Q ;//Расход бурового раствора
double D ;//Диаметр скважины (долота)
double dn ;//Наружный диаметр бурильных труб
double dny ;//Наружный диаметр утяжеленных бурильных труб(УБТ)
double dd ;//внутрений диаметр труб
double dy ;//Внутрений диаметр УБТ
double ddo ;//Диаметр наименьшего проходного сечения в соеденении
double Lc ;//глубина скважины
double L ;//Длина бурильных труб
double ly ;//Длина УБТ
double lt ;//Длина одной трубы
double P ;//Давление бурового раствора в скважине
double Ppl ;//пластвое давление
double alfaob ;//Коэффицент обвязки
double mu ;//Коэфицент расхода бурового раствора
double f ;//Суммарная площадь сечения промывочных отверстий долота
double lambda ;//Коэфицент гидравлического сопротивления в трубах
double lambdakp ;//Коэфицент гидравлического сопротивления в крольцевом пространстве скважины
double lambdakpu ;//Коэфицент гидравлического сопротивления в кольцевом пространстве УБТ
double Gmin ;//Минимальная осевая нагрузка на долото
double Gmax ;//Максимальная осевая нагрузка на долото
double Nmin ;//Минимальная осевая скорость вращения ротора
double Nmax ;//максимальная осевая скорость вращения ротора
double Pnd ;//Допустимая давление на насосе
double Pgr ;//Давление гидроразрыва пласта
double Np ;//Механическое мощность привода
double Nr ;//Гидравлическая мощность привода

   double Nrom;
   double Nn;

__fastcall TForm4::TForm4(TComponent* Owner)	: TForm(Owner)
{
	Nrom = 0;
   Nn = 0;
   Vm = 1;//Механическая скорость проходки
k = 1;//Коэфицент пропорциональности
G = 1;//Основная нагрузка на долото
Go = 1;//Показатель, характеризующий прочность породы
N = 1;//Скорость вращения ротора
alfa = 1;//Показатель степени, зависящий от типа долота и качества
T = 1;//Время работы долота
b = 1;//Постояная опоры долота
betta = 1;//показатель степени, зависящий от твердости породы и среды, в которой работает долото
nu = 1;//Пластическая вязкость раствора
gamma = 1;//Удельный вес бурового раствора
tauo = 1;//Динамическое напряжение сдвига буровго раствора
vkp = 1;//Средняя скорость течения бурового раствора в кольцевом пространстве скаважины
//vkp = 1;//Критическая скорость движения раствора
Q = 1;//Расход бурового раствора
D = 2;//Диаметр скважины (долота)
dn = 1;//Наружный диаметр бурильных труб
dny = 1;//Наружный диаметр утяжеленных бурильных труб(УБТ)
dd = 1;//внутрений диаметр труб
dy = 1;//Внутрений диаметр УБТ
ddo = 1;//Диаметр наименьшего проходного сечения в соеденении
Lc = 1;//глубина скважины
L = 1;//Длина бурильных труб
ly = 1;//Длина УБТ
lt = 1;//Длина одной трубы
P = 1;//Давление бурового раствора в скважине
Ppl = 1;//пластвое давление
alfaob = 1;//Коэффицент обвязки
mu = 1;//Коэфицент расхода бурового раствора
f = 1;//Суммарная площадь сечения промывочных отверстий долота
lambda = 1;//Коэфицент гидравлического сопротивления в трубах
lambdakp = 1;//Коэфицент гидравлического сопротивления в крольцевом пространстве скважины
lambdakpu = 1;//Коэфицент гидравлического сопротивления в кольцевом пространстве УБТ
Gmin = 1;//Минимальная осевая нагрузка на долото
Gmax = 1;//Максимальная осевая нагрузка на долото
Nmin = 1;//Минимальная осевая скорость вращения ротора
Nmax = 1;//максимальная осевая скорость вращения ротора
Pnd = 1;//Допустимая давление на насосе
Pgr = 1;//Давление гидроразрыва пласта
Np = 1;//Механическое мощность привода
Nr = 1;//Гидравлическая мощность привода
}

//=================Целевая функция=====================

double Func()
{
return (k*(Y[0]-Go)*pow(Y[1],alfa));
}
 	//============Шапки таблиц с параметрами===============
//---------------------------------------------------------------------------
void __fastcall TForm4::FormCreate(TObject *Sender)
{

Cnst->Cells[0][0]="Go";
Cnst->Cells[1][0]="Gmin, T";
Cnst->Cells[2][0]="Gmax, T";
Cnst->Cells[3][0]="n min, об/мин";
Cnst->Cells[4][0]="n max, об/мин";
Cnst->Cells[5][0]="D, м";
Cnst->Cells[6][0]="d, м";
Cnst->Cells[7][0]="dн, м";
Cnst->Cells[8][0]="dну, м";
Cnst->Cells[9][0]="dy, м";
Cnst->Cells[10][0]="do, м";
Cnst->Cells[11][0]="Lc, м";
Cnst->Cells[12][0]="L, м";
Cnst->Cells[13][0]="ly, м";
Cnst->Cells[14][0]="lt, м";
Cnst->Cells[15][0]="Рпл, Н/м*м";
Cnst->Cells[16][0]="f, м*м";
Cnst->Cells[17][0]="b";
Cnst->Cells[18][0]="Рнд, Н/м*м";
Cnst->Cells[19][0]="Рнд, Н/м*м";
Cnst->Cells[20][0]="Nп, кВт";
Cnst->Cells[21][0]="Np, кВт";
Cnst->Cells[22][0]="gamma, Н/м*м*м";
Kfc->Cells[0][0]="k";
Kfc->Cells[1][0]="alpha";
Kfc->Cells[2][0]="betta";
Kfc->Cells[3][0]="mu";
Kfc->Cells[4][0]="lambda";
Kfc->Cells[5][0]="lambda кп";
Kfc->Cells[6][0]="lambda кпу";
Kfc->Cells[7][0]="alpha об";
Cnt->Cells[0][0]="G, T";
Cnt->Cells[1][0]="n, об/мин";
Cnt->Cells[2][0]="Vm, м/ч";
Cnt->Cells[3][0]="P, Па";
Cnt->Cells[4][0]="Q, л/с";
Cnt->Cells[5][0]="T, час";
Cnt->Cells[6][0]="nu, Н/м*м";
Cnt->Cells[7][0]="tau о, Па*с";
Cnt->Cells[8][0]="Vкп, м/с";

//=====автоматическое внесение значений в таблицу======

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
//====Процедура поиска локального экстремума===========

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

   //=====Проверка: минимум < максимум====================

   if(Ymin[i]>=Ymax[i])
   {
   	MessageDlg("Минимум должен быть меньше максимума!",mtWarning,TMsgDlgButtons()<<mbOK,0);
   	break;
   }

   //===Проверка: минимум < начальное значение < максимум=

   	if((Y[i]<Ymin[i])||(Y[i]>Ymax[i]))
   	{
   		MessageDlg("Начальное значение должны быть в заданном интервале!",mtWarning,TMsgDlgButtons()<<mbOK,0);
   		break;
   	}
   }
Stoplt=false;

do
{
N=N+1; //количество шагов/прохождений цикла
for(int i=0;i<Vars;i++)
{
if ((Y[i]<Ymin[i])||(Y[i]>Ymax[i]))break;
Num=Y[i];
Y[i]=Y[i]+Delta;
NY[i]=Func();
Y[i]=Num;
NY[i]=(NY[i]-Func())/Delta; //Градиент функции
}

//=================Норма градиента=====================

Norm=0;
for (int i=0;i<Vars;i++)
Norm=Norm+pow(NY[i],2);
Norm=sqrt(Nrom); //Норма градиента

//===========Корректировка значения градиента==========

for (z=0;z<Vars;z++)
{
if (Norm>0)
NY[z]=Y[z]=NY[z]/Norm*H; //Изменение значения градиента функции
else // С учетом градиента
NY[z]=Y[z]; //Градиент функции = значения функции

//====Проверка, не влодит ои значение градиента из интервала (Ymin[i];Ymax[z])====

if(NY[z]>Ymax[z])
NY[z]=Ymax[z];
else
if(NY[z]<Ymin[z])NY[z]=Ymin[z];
}
Num=0;

//====Расчет Num = |NY[1]-Y[1]|+|NY[2]-Y[2]| для проверки условия====

for (x=0;x<Vars;x++)
{
Num=Num+abs(NY[x]-Y[x]);
Y[x]=NY[x];
if(x==1)
G=int((Y[x]*1000000000.0+0.5)/1000000000.0); //Значение G
else
Np=(Y[x]=1000000000.0+0.5)/1000000000.0; //Значение n
}

//========Проверка соблюдения ограничений========

if((k*G*Nr)>Np)
{
Stoplt=true; //Завершение выполнения процедуры
FindLocalExtremum();
Vm=(Func()*1000000000.0+0.5)/1000000000.0; //значение Vm
Num=0;
}
}
while((Norm<=Eps)||(Num!=0)||(Stoplt!=true));
}

//---------------------------------------------------------------------------
//=========Обработчик кнопки "рассчитать"==========
void __fastcall TForm4::BitBtn1Click(TObject *Sender)
{
   double P1,P2,P3,P4;
   //=============Очистить таблицу====================
   for(int i=0; i<=8; i++)
   Cnt->Cells[i][1]="";

   //====Считывание введенных параметров (констант и коэфицентов)====

   Gmin=StrToFloat(Cnst->Cells[1][1]);
   Nmin=StrToFloat(Cnst->Cells[3][1]);
   Ymin[0]=Gmin;
   Gmax=StrToFloat(Cnst->Cells[2][1]);
   Ymax[0]=Gmax;
   Ymin[1]=Nmin;
   Nmax=StrToFloat(Cnst->Cells[4][1]);
   Ymax[1]=Nmax;
   Y[0]=Ymin[0]+1.0;
   Y[1]=Ymin[1]+1.0; //Начальные значения G и n
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
   FindLocalExtremum(); //Вызов вроцедуры FindLocalExtremum()
   if ((Y[0]>Ymin[0]+1.0) &&(Y[1]>Ymin[1]+1.0))
   {

   //======Расчет показателей бурения=============

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

   //========Проверка соблюдения ограничений==========

   if ((P + gamma*Lc) <= Pnd )
   if ((P + gamma*Lc) <= Pgr )
   if ((k* P* Q)<=Nr)
   if (((Kgam* (Ppl+15000)/Lc) <= gamma) && (gamma <= (Kgam*(Ppl+25000)/Lc) ) )
   if ((Kqd* Q/ (pow(D,2)-pow(dn,2)) ) >= 0.4 )
   {

   //=======Вывод значений показатеоей процесса бурения=========

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

