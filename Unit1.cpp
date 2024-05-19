=====================================================================
========================расчет функции в=f(s)========================
=====================================================================

//-----------------------------------------------------
#include <vel.h>
#include <math.h>
#pragma hdrstop
#include "Unit1.h"
//-----------------------------------------------------
pragma package(smart_init)
pragma resource "*.dfim"
TForm1 *Form1;
const double
First_Massiv[27][2]={{0.14,2},{0.2,3},{0.235,4}, {0.28,5},{0.3,6},{0.33,7},(0.35,8},{0.39,9},{0.4,10}, {0.51,20}, {0.59,30}, {0.62,40}, {0.66,50}, {0.7,60}, {0.71,70},{0.73,80},{0.74,90},{0.75, 100}, {0.81,200}, {0.84,300}, {0.86,400}, {0.88,500}, {0.89,600}, {0.9,700}. {0.9,800}, {0.9,900}, {0.9,1000} };
const double
Second_Massiv[27][2]={{0.19,2},{0.26,3},{0.31,4},{0.35,5},{0.38,6},{0.4,7},{0.42,8},{0.45,9},{0.47, 10},{0.59,20}, {0.66,30}, {0.7,40},{0.73,50}, {0.75,60}, {0.77,70},{0.79,80}, {0.8,90},{0.81,100}, {0.86,200}, {0.89,300}, {0.9,400}, {0.91,500}, {0.92,600},{0.92,700}, {0.93,800},{0.93,900},{0.93,1000}};
int i,j,k;
double a,t,K,Experience_Data[27][2];
double Massiv_Ln[27](2];
double Massiv_Of_Factors[2][3];
double Massiv_Of_Gause[2][3];

//-----------------------------------------------------
_fasteall Form1::TForm1(TComponent*Owner): TForm(Owner)
{
}

//-----------------------------------------------------
void_fastcall TForm1::FormActivate(TObject*Sender)
{
for (i=0;i<=26;i++)
{
for (j=0;j<=1;j+4)
{
StringGrid1->Cells[j][i+1]=FloatToStr(First_Massiv[i][j]);//Заполняем таблицу исходными данными, которые занесены в массив-константу
}
}
}

//-----------------------------------------------------
void_fastcall TForm1::Button1Click(TObject *Sender)
{
for (i=0;i<=26;i++)
{
for (j=0;j<=1;j++)
{
Experience_Data[i][j]=StrToFloat(StringGrid1->Cells[j][i+1]);
}
}
//--------метаод наименьших квадроатов--------
for(i=0;i<=26;i++)
{
for(j=0;j<=1,j++)
{
Massiv_Ln[i][j]=log(Experience_Data[i][j]); //логарифмируем данные полученные с приборов для дальнейших вычислений
}
}
for (i=0;i<=26;i++)
{
for (j=0;j<=1;i++)
{
StringGrid2->Cells[j][i+1]=FloatToStr(Massiv_Ln[i][j]);//заполняем таблицу исходными данными, которые занесены в массив-константу
} 
}
for(i=0;<=1;i++)
{
for(j=0;j<=2;j++)
{
Massiv_Of_Factors[i][j]=0;//обнуляем массив кофицентов
}
}
for(i=0;i<=26;i++)
{
Massiv_Of_Factors[0][0]=Massiv_Of_ Factors[0][0]+1;
Massiv_Of_Factors[0][1]=Massiv_Of_ Factors[0][1]+1*Massiv_Ln[i][1]; 
//считаем
Massiv_Of_Factors[0][2]=Massiv_Of_ Factors[0][2]+1*Massiv_Ln[i][0];
}
for(i=0;i<=26;i++)
{
Massiv_Of_Factors[1][0]=Massiv_Of_Factors[1][0]+Massiv_Ln[i][1];
Mas-
siv_Of_Factors[1][1]=Massiv_Of_Factors[1][1]+Massiv_Ln[i][1]*Massiv_Ln[i][1];
//считаем
Mas-
siv_Of_Factors[1][2]=Massiv_Of_Factors[1][2]+Massiv_Ln[i][1]*Massiv_Ln[i][0];
}
for (i=0;i<=1;i++)
{
for (j=0;j<=2;j++)
{
StringGrid3->Cells[j][i+1]=Massiv_Of_Factors[i][j];
}
}
//=================Метод Гаусса==================
for (k=0;k<=1;k++)
{
for (i=k;i<=1;i++) //Приравнивая k=i мы тем самым сужаем исследуемую область матрицы
{
if(i==k)
{
for(j=k;j<=2;j++)
{
Massiv_Of_Gause[i][j]=Massiv_Of Factors[i][j]/Massiv_Of Factors[i][i]; //
}
}
else
{
for (j=k;j<=2;j++)
{
Massiv_Of_Gause[i][j]=Massiv_Of_Factors[i][j]-
Massiv_Of_Factors[i][k]*Massiv_Of_Gause[k][j]; //Считаем коэффициенты остальных управлений
}
}
}
for (i=0;i<=1;i++)
{
for (j=0;j<=2;j++)
{
Massiv_Of_Factors[i][j]=Massiv_Of_ Gause[i][j]; //Присваиваем матрицу Гауса матрица коэффициентов
}
}
}
for (i=0;i<=1;i++)
{
for (j=0;j<=2;j++)
{
StringGrid3->Cells[j][i+1]=FloatToStr(Massiv_Of_Factorsf[i][j]); //вывод на экран уравнения Гауса
}
}
t=Massiv_Of_Gause[1][2];//Коэфицент m
K=Massiv_Of_Gause[0][2]-t*Massiv_Of_Gause[0][1];//Коэфицент b
Editl->Text=FloatToStr(t);
Edit2->Text=FloatToStr(exp(K));
}

//---------------------------------------------------------------------
void __fastcall TForm] ::Button2Click(TObject *Sender)
{
for (i=0;i<=26;i++)
{
for (j=0;j<=26;j++)
{
StringGrid1->Cells[j][i+1]=FloatToStr(First_Massiv[i][j]);//заполняем таблицу исходными данными, которые занесены в массив-константу
}
}
}

//---------------------------------------------------------------------
void_fastcall TForm1::Button3Click(TObject*Sender)
{
for (i=0;i<=26;i++)
{
for (j=0;j<=1;j++)
{
StringGridl->Cells[j][i+1]=FloatToStr(Second_Massiv[i][j]);//заполняем таблицу исходными данными, которые занесены в массив-константу
}
}
}

//----------------------------------------------------------------------
void_fastcall TForm1:;Button4Click(TObject*Sender)
{
for (i=0;i<=26;i++)
{
a=First_Massiv[i][1];
Chart->Series[0]->AddXY(a,exp(K)*pow(a,t));
StringGrid1->Cells[2|[i+1]=exp(K)*pow(a,);
}
}

//----------------------------------------------------------------------
void_fastcall TForm1::Button5Click(TObject*Sender)
{
for (i=0;i<=26;i++)
{
a=Second_Massiv[i][1];
Chart1->Series[1]->AddXY(a,exp(K)*pow(a,t));
StringGrid1->Cells[2][i+1]=exp(K)*pow(a,t);
}
}

