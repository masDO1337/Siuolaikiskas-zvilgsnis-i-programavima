#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;
const char CDfv[] = "U2.txt";
const char CRfv[] = "U2rez.txt";
const int CMax = 20;
const int CPav = 12;

struct Avys {
  char pav[CPav+1];
  int DNR_Length;
  string DNR;
  int koeficientas = 0;
  bool tirimas = false;
};
//-----------------------------------------------------------------------
void Skaityti(const char fv[], Avys A[], int & n, int & TAEN);
void Spausdinti(Avys A[], int n);
void DNRApskaiciuoti(Avys A[], int n, int TAEN);
void DNRRikiavimas(Avys A[], int n);
//-----------------------------------------------------------------------
int main()
{
   Avys A[CMax]; int n;
   int TAEN;
   Skaityti(CDfv, A, n, TAEN);
   DNRApskaiciuoti(A, n, TAEN);
   DNRRikiavimas(A, n);
   Spausdinti(A, n);
   return 0;
}
//-----------------------------------------------------------------------
void Skaityti(const char fv[], Avys A[], int & n, int & TAEN)
{
   ifstream fd (fv);
   int m;
   fd >> n >> m;
   char dnr[m+1];
   fd.ignore(80, '\n');
   fd >> TAEN;
   fd.ignore(80, '\n');
   for (size_t i = 0; i < n; i++) {
     fd.get(A[i].pav, CPav);
     A[i].DNR_Length = m;
     fd.get(dnr, m+1);
     A[i].DNR = dnr;
     if (i == TAEN-1) A[i].tirimas = true;
     fd.ignore(80, '\n');
   }
   fd.close();
}
//-----------------------------------------------------------------------
void Spausdinti(Avys A[], int n)
{
   ofstream fr (CRfv);
   for (size_t i = 0; i < n; i++) {
     if (A[i].tirimas == true)
       fr << A[i].pav << '\n';
   }
   for (size_t i = 0; i < n; i++) {
     if (A[i].tirimas == false) {
       fr << A[i].pav << A[i].koeficientas << '\n';
     }
   }
   fr.close();
}
//-----------------------------------------------------------------------
void DNRApskaiciuoti(Avys A[], int n, int TAEN)
{
  for (size_t i = 0; i < n; i++) {
    if (i != TAEN-1) {
      for (size_t j = 0; j < A[TAEN-1].DNR_Length; j++) {
        if (A[TAEN-1].DNR[j] == A[i].DNR[j]) {
          A[i].koeficientas ++;
        }
      }
    }
  }
}
//-----------------------------------------------------------------------
void DNRRikiavimas(Avys A[], int n)
{
  Avys B;
  for(size_t i = 0; i < n - 1; ++i) {
    for(size_t j = i + 1; j < n; ++j) {
      if (A[i].koeficientas < A[j].koeficientas) {
        B = A[i];
        A[i] = A[j];
        A[j] = B;
      }
      if (A[i].koeficientas == A[j].koeficientas) {
        for (size_t x = 0; x < CPav; x++) {
          if (A[i].pav[x] > A[j].pav[x]) {
            B = A[i];
            A[i] = A[j];
            A[j] = B;
            break;
          }
        }
      }
    }
  }
}
