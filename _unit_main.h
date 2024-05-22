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
double lamda ;//Коэфицент гидравлического сопротивления в трубах
double lamdakp ;//Коэфицент гидравлического сопротивления в крольцевом пространстве скважины
double lamdakpu ;//Коэфицент гидравлического сопротивления в кольцевом пространстве УБТ
double Gmin ;//Минимальная осевая нагрузка на долото
double Gmax ;//Максимальная осевая нагрузка на долото
double Nmin ;//Минимальная осевая скорость вращения ротора
double Nmax ;//максимальная осевая скорость вращения ротора
double Pnd ;//Допустимая давление на насосе
double Pgr ;//Давление гидроразрыва пласта
double Np ;//Механическое мощность привода
double Nr ;//Гидравлическая мощность привода
double Dilta;
   double Nrom;
   double lambda;
   double lambdakpu;
   double lambdakp;
   double Nn;
   double lambdakp;
   double lambdakp;
   double lambdakp;

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
