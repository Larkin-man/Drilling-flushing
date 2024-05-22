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
double lamda ;//��������� ��������������� ������������� � ������
double lamdakp ;//��������� ��������������� ������������� � ���������� ������������ ��������
double lamdakpu ;//��������� ��������������� ������������� � ��������� ������������ ���
double Gmin ;//����������� ������ �������� �� ������
double Gmax ;//������������ ������ �������� �� ������
double Nmin ;//����������� ������ �������� �������� ������
double Nmax ;//������������ ������ �������� �������� ������
double Pnd ;//���������� �������� �� ������
double Pgr ;//�������� ������������ ������
double Np ;//������������ �������� �������
double Nr ;//�������������� �������� �������
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
