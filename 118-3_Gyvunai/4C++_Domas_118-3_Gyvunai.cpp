#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;
const char CDfv[] = "Duomenys.txt";
const char CRfv[] = "Rezultatai.txt";
const int CMax = 300;
const int CPav = 15;
//-----------------------------------------------------------------------
struct Gyvunai {
           string pav;
           int kiek;
           string sav;
};
//-----------------------------------------------------------------------
void Skaityti(Gyvunai A[], int & n);
void Spausdinti(Gyvunai A[], int n, string pav);
void Rikiuoti(Gyvunai A[], int n);
void Sudeti(Gyvunai A[], int n);
//-----------------------------------------------------------------------
int main()
{
   Gyvunai A[CMax]; int n;
   Skaityti(A, n);
   Rikiuoti(A, n);
   Sudeti(A, n);
   Spausdinti(A, n, "");
   return 0;
}
//-----------------------------------------------------------------------
void Skaityti(Gyvunai A[], int & n)
{
   char eil[CPav + 1];
   ifstream fd(CDfv);
   fd >> n ;
   fd.ignore(80, '\n');
   for (int i = 0; i < n; i++) {
      fd.get(eil, CPav);
      A[i].pav = eil;
      fd >> A[i].kiek;
      getline(fd, A[i].sav);
   }
   fd.close();
}
//-----------------------------------------------------------------------
void Spausdinti(Gyvunai A[], int n, string pav)
{
   ofstream fr (CRfv);
   if (n <= 0) {
     fr << "Nera informcijos";
   }
   for (int i = 0; i < n; i++)
    if (A[i].kiek > 0)
      fr << setw(15) << A[i].pav << setw(6) << A[i].kiek << endl;
    //fr << A[i].pav << right << setw(6) << A[i].kiek << endl;
   fr.close();
}
//-----------------------------------------------------------------------
void Rikiuoti(Gyvunai A[], int n)
{
  int max = 0;
  for (int i = 0; i < n; i++) {
    if (A[i].kiek > max) {max = A[i].kiek;}
  }
  Gyvunai B;
  for (int i = max; i > 0; i--) {
    for (int j = 0; j < n; j++) {
      if (i == A[j].kiek) {
        for (int x = 0; x < n; x++) {
          if (A[j].kiek > A[x].kiek) {
            B = A[x];
            A[x] = A[j];
            A[j] = B;
          }
        }
      }
    }
  }
}
void Sudeti(Gyvunai A[], int n)
{
  for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++) {
      if (A[i].pav == A[j].pav) {
        A[i].kiek += A[j].kiek;
        A[j].kiek = 0;
      }
    }
  }
}
