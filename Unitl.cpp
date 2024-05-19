=====================================================================
======расчет коэфициентов модели методом наименьших квадратов========
=====================================================================

//-----------------------------------------------------------------------
#include <vel.h>
#include <math.h>
#pragma hdrstop
#include "Unitl.h"
//-----------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
const double
First_Massiv[9][4]={{1,0.0000000001 ,0.0000000001,36},{6.1,58,28,74}, {12.65,116,30,148}, {17.55,146,36,222}, {19.75,152,42,296}, {20.95,156,45,370}, {21.6,158,46,444}, {21.9,161,46,518},{22.7,164,48,592}};
int i,j,k,Size_Of_Table,l;
double Experience_Data[9][4];
double Massiv_Ln[9][4];
double Massiv_Of_Factors[4][5];
double Massiv_Of Gause[4][5];
double K,a,b,m,A1,A,Sum1,Sum;
double Massiv_Score[200][4];
double round(double m)
{
int h;
h=m*1000;
m=h;
m=m/1000;
return m;
}
//-------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner): TForm(Owner)
{
}

//-------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
for (i=0;i<=8;i++)
{
for (j=0;j<=3;j++) '
{
StringGrid1->Celis[j][i+1]=FloatToStr(First_Massiv[i][j]);//Заполняем таблицу исходными данными, которые занесены в массив-константу
}
}
StringGridl->Cells[0][0]="Qм, м/ч";
StringGridi->Cells[1][0]="G, кH";
StringGrid1->Cells[2][0]="n, об/м";
StringGridl->Cells[3][0]="Nд, кВт";
StringGrid6->Cells[0][0]="Qм, м/ч";
StringGrid6->Cells{1][0]="G, кH";
StringGrid6->Cells{2][0]="n, об/м";
StringGrid6->Cells[3][0]="Nд, кВт";
StringGrid4->Cells[0][0]="Qм, м/ч";
StringGrid4->Cells[1][0]="G, кH";
StringGrid4->Cells[2][0]="n, об/м«";
StringGrid4->Cells[3][0]="Nд, кВт";
StringGrid2->Cells[0][0]="Ln Qм, м/ч";
StringGrid2->Cells[1][0]="Ln G, кН";
StringGrid2->Cells[2][0]="Ln n, об/м";
StringGrid2->Cells[3][0]="Ln Nд, кВт";
StringGrid3->Cells[0][0]="Коэф. при K";
StringGrid3->Cells[1][0]="Коэф. при b";
StringGrid3->Cells[2][0]="Коэф. при a";
StringGrid3->Cells[3][0]="Коэф. при m";
StringGrid3->Cells[4][0]="Св. член";
StringGrid5->Cells[0][0]="Коэф. при K";
StringGrid5->Cells[1][0]="Коэф. при b”;
StringGrid5->Cells[2][0]="Коэф. при a";
StringGrid5->Cells[3][0]="Коэф. при m";
StringGrid5->Cells[4][0]="Св. член";
}

//---------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
for(i=0;i<=8;i++)
{
for(j=0;j<=3;j++)
{
Experience_Data[i][j]=StrToFloat(StringGridl->Cells[j][i+1]);//Заполняем массив-переменную данными с первой таблицы, для выполнения с ними расчетов
}
}
//---------------------метод наименьших квадратов------------------
for(i=0;i<=8;i++)
{
for(j=0;j<=3;j++)
{
Massiv_Ln[i][j]=log(Experience_Data[i][j]);//логарифмируем данные полученные с приборов для дальнейших вычислений
}
}
for(i=0;i<=3;i++)
{
for(j=0;j<=4j++)
{
Massiv_Of_Factors[i][j]=0;//обнуляем массив коэффициентов
}
}
for(i=0;i<=8;i++)
{
Massiv_Of_Factors[0][0]=Massiv_Of_Factors[0][0]+1;
Massiv_Of_Factors[0][1]=Massiv_Of_Factors[0][1]+1*Massiv_Ln[iJ[1];//считаем
Massiv_Of_Factors[0][2]=Massiv_Of_Factors[0][2]+1*Massiv_Ln[i][2];//коэфиценты
Massiv_Of_Factors[0][3]=Massiv_Of_Factors[0][3]+1*Massiv_Ln[i][3];//для первого
Massiv_Of_Factors[0][4]=Massiv_Of_ Factors[0][4]+1*Massiv_Ln[i][0];//уравнения
}
for(i=0;i<=8;i++)
{
Massiv_Of_Factors[1][0]=Massiv_Of_Factors[1][0]+Massiv_Ln[i][1];
Mas-
siv_Of_Factors[1][1]=Massiv_Of_Factors[1][1]+Massiv_Ln[i][1]*Massiv_Ln[i][1];//считаем
Mas-
siv_Of_Factors[1][2]=Massiv_Of_Factors[1][2]+Massiv_Ln[i][1]*Massiv_Ln[i][2];//коэффциенты
Mas-
siv_Of_Factors[1][3]=Massiv_Of_Factors[1][3]+Massiv_Ln[i][1]*Massiv_Ln[i][3];//для второго
Mas-
siv_Of_Factors[1][4]=Massiv_Of_Factors[1][4]+Massiv_Ln[i][1]*Massiv_Ln[i][0];//уравнения
}
for(i=0;i<=8;i+)
{
Massiv_Of_Factors[2][0]=Massiv_Of_Factors[2][0]+Massiv_Ln[i][2];
Mas-
siv_Of_Factors[2][1]=Massiv_Of_Factors[2][1]+Massiv_Ln[i][2]*Massiv_Ln[i][1];//считаем
Mas-
siv_Of_Factors[2][2]=Massiv_Of_Factors[2][2]+Massiv_Ln[i][2]*Massiv_Ln[i][2];//коэффциенты
Massiv_Of_Factors[2][3]=Massiv_Of_Factors[2][3]+Massiv_Ln[i][2]*
Massiv_Ln[i][3];//для третьего
Massiv_Of_Factors[2][4]=Massiv_Of_Factors[2][4]+Massiv_Ln[i][2]*
Massiv_Ln[i][0];//уравлнения
}
for(i=0;i<=8;i++)
{
Massiv_Of_Factors[3][0]=Massiv_Of_Factors[3][0]+Massiv_Ln[i][3];
Massiv_Of_Factors[3][1]=Massiv_Of_Factors[3][1]+Massiv_Ln[i][3]*
Massiv_Ln[i][1];//считаем
Massiv_Of_Factors[3][2]=Massiv_Of_Factors[3][2]+Massiv_Ln[i][3]*
Massiv_Ln[i][2];//коэффициенты
Massiv_Of_Factors[3][3]=Massiv_Of_Factors[3][3]+Massiv_Ln[i][3]*
Massiv_Ln[i][3];//для четвертого
Massiv_Of_Factors[3][4]=Massiv_Of_Factors[3][4]+Massiv_Ln[i][3]*
Massiv_Ln[i][0];//уравнения
StringGrid2->Cells[j][i+1]=FloatToStr(Massiv_Ln[i][j]);//вывод на экран
}
}
for (i=0;i<=3;i++)
{
for (j=0;j<=4;j++)
{
StringGrid3->Cells[j][i+1]=FloatToStr(Massiv_Of_Factors[i][j]);//вывод на экран массива из коэфициентов
}
}
//---------------метод гауса-------------
for (k=0;k<=3;k++)
{
for(i=k;i<=3;i++)//приравнивая k=i мы тем самым сужаем исследуюмую область матрицы
{
if(i==k)
{
for(j=k:j<=4;j++)
{
Massiv_Of_Gause[i][j]=Massiv_Of_Factors[i][j]/Massiv_Of Factors[i][i];
//Делим все коэфициенты первого уравнения на первый коэффициент и считаем новые значения матрицы
}
}
else
{
for (j=k;j<=4;j++)
{
Massiv_Of_Gause[i][j]=Massiv_Of_Factors[i][j]-
Massiv_Of_Factors[i][k]*Massiv_Of_Gause[k][j];//считаем коэффициенты остальнвх уравлений
}
}
for (i=0;i<=3;i++)
{
for (j=0;j<=4;j++)
{
Massiv_Of_Factors[i][j]-Massiv_Of_Gause[i][j];//присваиваем матрицу гауса коэфициентов
}
}
}
for (i=0;i<=3;i++)
{
for (j=0;j<=4;j++)
{
StringGrid->Cells[j][i+1]=FloatToStr(Massiv_Of_Factors[i][j]);//вывод на экран управления гауса
}
}
m=Massiv_Of_Gause[3][4];//коэфициент m
a=Massiv_Of_Gause[2][4]-m*Massiv_Of_Gause[2][3];//коэфициент b
b=Massiv_Of_Gause[1][4]-
(m*Massiv_Of_Gause[1][3]+a*Massiv_Of_Gause[1][2];//коэфициент a
K=exp(Massiv_Of_Gause[0][4]-
(m*Massiv_Of_Gause[0][3]+a*Massiv_Of_Gause[0][2]+b*Massiv_Of_Gause[0][1]));
//
for (i=0;i<=8;i++)
{
StringGrid4->Cells[0][i+1]=FloatToStr(K*pow(Experience_Data[i][1],b)*
pow(Experience_Data[i][2],a)*pow(Experience_Data[i][3],m));//вывод на экран массива Ufecf*/
StringGrid4->Cells[1][i+1]-FloatToStr(Experience_Data[i][1]);//выводим
StringGrid4->Cells{2][i+1]=FloatToStr(Experience_Data[i][2]);//сравнительную
StringGrid4->Celis[3][i+1]=FloatToStr(Experience_Data[i][3]);//таблицу
}
Sum=0;
Sum1=0;
for (i=1;i<=9;i++)
{
Al=StrToFloat(StringGrid1->Cells[O][i]);//вычисляем
A=StrToFloat(StringGrid4->Cells[0][i]);//среднее
Sum=sqrt((Al-A)*(Al-A))/Al*100+Sum; //значние
Sum1=sqrt((Al-A)*(Al-A))+Sum1;
}
Edit1->Text=FloatToStr(round(K));//вывод
Edit2->Text=FloatToStr(round(b));
Edit3->Text=FloatToSir(round(a));
Edit4->Text=FloatToStr(round(m));//значений
Edit5->Text=FloatToStr(round(Sum1/9));
Edit6->Text=FloatToStr(round(Sum/9));
Edit7->Text=FloatToStr(round(100-Sum/9));
Label6->Caption="Vм(K,b,a,m)="+FloatToStr(round(K))+"*G^"+
FloatToStr(round(b))+"*n^("+FloatToStr(round(a))+")*Nд^"+
FloatToStr(round(m));//выводим уравнение
}

//--------------------------------------------------------------
void__fastcall TForm1::StringGrid6DbIClick(TObject *Sender)
{
Size_Of_Table=StringGrid6->RowCount-1;//определяем номер строки в таблице
if (StringGrid6->Cells[1][Size_Of Table]!="")//если три столбца непустые
{
if (StringGrid6->Cells[2][Size_Of_Table]!="")
{
if (StringGrid6->Cells[3][Size_Of_Table]!="")
{
l++;//счтчик стобы добавлять в строку в таблицу
for (j=l;j<=3;j++)
{
Massiv_Score[l][j]=StrToFloat(StringGrid6->Cells[j][l]),//считываем введенные данные
}
for (i=l;i<=1;i++)
{
Massiv_Score[i][0]=K*pow(Massiv_Score[i][l],b)*
pow(Massiv_Score[i][2],a)*pow(Massiv_Score[i][3],m);//вычисляем значение уравнения и заносим его в массив
}
for (i=l;i<=1;i++)
{
for (j=0;j<=3;j++)
{
StringGrid6->Cells[j][i]=FloatToStr(Massiv_Score[i][j]);//вывод на экран всего массива
}
}
StringGrid6->RowCount=StringGrid6->RowCount+1; //увеличиваем количество строк таблицы на одну
StringGrid6->Height=StringGrid6->Height+StringGrid6->DefaultRowHeight;//увеличиваем высоту таблицы
}
}
}
}

//--------------------------------------------------------------
void_fastcall TForm1::ComboBox1Change(TObject *Sender)
{
if (ComboBox1->ItemIndex==0)
{
Image1->Show();
Image2->Hide();
Image3->Hide();
}
if (ComboBox1->temIndex==1)
{
Image2->Show();
Image1->Hide();
Image3->Hide();
}
if (ComboBox1->ItemIndex==2)
{
Image3->Show();
Image2->Hide();
Imagel->Hide();
}
}

//-----------------------------------------------------------
void__fastcall TForm1::Button2Click(TObject *Sender)
{
Chart1->Series[0]->Clear();
Chart1->Series[1]->Clear();
for (j=1;j<=9;j++)
{
Chart1->Series[0]->AddXY(j,StrToFloat(StringGrid1->Cells[0][j]));
Chart1->Series[1]->AddXY(j,StrToFloat(StringGrid4->Cells[0][j]));
}
}
//---------------------------------------------------------------

