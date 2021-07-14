#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;
const char CDfv[] = "Duomenys.txt";
const char CRfv[] = "Rezultatai.txt";
const int CMax = 30;
const int CPav = 20;
//-----------------------------------------------------------------------
struct DienuValge {
      int vienitai;
      double kaina;
};
struct Globejas {
          string pav;
          double balancas;
          int kiekDienuValge;
          DienuValge valge[CMax];
};
//-----------------------------------------------------------------------
void Skaityti(const char fv[], Globejas A[], int & n);
void Spausdinti(Globejas A[], int n);
void pirko(Globejas A[], int n);
//-----------------------------------------------------------------------
int main()
{
   Globejas A[CMax]; int n;
   Skaityti(CDfv, A, n);
   pirko(A, n);
   Spausdinti(A, n);
   return 0;
}
//-----------------------------------------------------------------------

void Skaityti(const char fv[], Globejas A[], int & n)
{
   ifstream fd (fv);
   double litai, centai;
   char eil[CPav+1];
   fd >> n;
   fd.ignore(80, '\n');
   for (int i = 0; i < n; i++) {
      fd.get(eil, CPav);
      A[i].pav = eil;
      fd >> litai >> centai;
      A[i].balancas = litai + (centai/100);
      fd >> A[i].kiekDienuValge;
      for (int j = 0; j < A[i].kiekDienuValge; j++) {
        fd >> A[i].valge[j].vienitai;
        fd >> A[i].valge[j].kaina;
      }
      fd.ignore(80, '\n');
   }
   fd.close();
}
//-----------------------------------------------------------------------
void Spausdinti(Globejas A[], int n)
{
   ofstream fr (CRfv);
   double balancai = 0;
   double MAX = 0;
   int ID = 0;
   for (int i = 0; i < n; i++) {
     fr << setw(20) << left << A[i].pav << " " << A[i].balancas << endl;
     balancai += A[i].balancas;
     if (A[i].balancas > MAX)
       ID = i;
   }
   fr << balancai << endl;
   fr << setw(20) << left << A[ID].pav << " " << A[ID].balancas << endl;
   fr.close();
}
//-----------------------------------------------------------------------
void pirko(Globejas A[], int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < A[i].kiekDienuValge; j++) {
      A[i].balancas -= A[i].valge[j].vienitai * A[i].valge[j].kaina;
    }
  }
}
