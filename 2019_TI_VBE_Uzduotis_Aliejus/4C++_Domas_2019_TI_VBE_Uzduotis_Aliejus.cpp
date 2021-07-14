#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;
const char CDfv[] = "U1.txt";
const char CRfv[] = "U1rez.txt";
//-----------------------------------------------------------------------
struct Ukininkas {
  int tusti_indai[3];
  int indai[3] = {0,0,0};
  int kiek_indu_reikia[3] = {0,0,0};
  int kiek_turi;
  int islaidos;
  int kainos[3];
  int suma = 0;
};
//-----------------------------------------------------------------------
void Skaityti(const char fv[], Ukininkas & A);
void Spausdinti(Ukininkas A);
void Suskaiciuoti(Ukininkas & A);
//-----------------------------------------------------------------------
int main()
{
   Ukininkas A;
   Skaityti(CDfv, A);
   Suskaiciuoti(A);
   Spausdinti(A);
   return 0;
}
//-----------------------------------------------------------------------
void Skaityti(const char fv[], Ukininkas & A)
{
   ifstream fd (fv);
   for (int i = 0; i < 3; i++) {
     fd >> A.tusti_indai[i];
   }
   fd >> A.kiek_turi;
   fd.ignore(80, '\n');
   fd >> A.islaidos;
   for (int i = 0; i < 3; i++) {
     fd >> A.kainos[i];
   }
   fd.close();
}
//-----------------------------------------------------------------------
void Spausdinti(Ukininkas A)
{
   ofstream fr (CRfv);
   for (int i = 0; i < 3; i++) {
     fr << A.indai[i] << ' ';
   }
   fr << A.kiek_turi << endl;
   for (int i = 0; i < 3; i++) {
     fr << A.tusti_indai[i] << ' ';
   }
   fr << endl;
   for (int i = 0; i < 3; i++) {
     fr << A.kiek_indu_reikia[i] << ' ';
   }
   fr << endl << A.suma << endl;
   fr.close();
}
//-----------------------------------------------------------------------
void Suskaiciuoti(Ukininkas & A)
{
  for (int i = 2; i >= 0; i--) {
    int tuscias_indas = A.tusti_indai[i];
    for (int j = 0; j < tuscias_indas; j++) {
      if (i == 2 && A.kiek_turi-5 < 0) break;
      if (i == 1 && A.kiek_turi-3 < 0) break;
      if (i == 0 && A.kiek_turi-1 < 0) break;
      A.tusti_indai[i] --;
      A.indai[i] ++;
      if (i == 2) A.kiek_turi -= 5;
      if (i == 1) A.kiek_turi -= 3;
      if (i == 0) A.kiek_turi --;
    }
  }
  int likutis = A.kiek_turi;
  while (likutis > 0) {
    if (likutis > 5) {
      likutis -= 5;
      A.kiek_indu_reikia[2] ++;
    } else if (likutis > 3) {
      likutis -= 3;
      A.kiek_indu_reikia[1] ++;
    } else if (likutis > 0) {
      likutis -= 1;
      A.kiek_indu_reikia[0] ++;
    }
  }
  for (int i = 0; i < 3; i++) {
    A.suma += A.kainos[i] * (A.indai[i] + A.kiek_indu_reikia[i]);
  }
  A.suma -= A.islaidos;
}
//-----------------------------------------------------------------------
