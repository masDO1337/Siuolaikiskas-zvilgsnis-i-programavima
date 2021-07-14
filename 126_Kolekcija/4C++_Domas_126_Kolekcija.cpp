#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;
const char CDfva[] = "Duomenys.txt";
const char CRfv[] = "Rezultatai.txt";
const int CMax = 30;
const int CPav = 20;
//-----------------------------------------------------------------------
struct Kolekcija {
          string pav;
          int metai;
          int laikas;
          int kiek;
};
//-----------------------------------------------------------------------
void Skaityti(const char fv[], Kolekcija A[], int & n);
void Spausdinti(Kolekcija A[], int n);
void Rikiuoti(Kolekcija A[], int n);
//-----------------------------------------------------------------------
int main()
{
   Kolekcija A[CMax]; int n;
   Skaityti(CDfva, A, n);
   Rikiuoti(A, n);
   Spausdinti(A, n);
   return 0;
}
//-----------------------------------------------------------------------

void Skaityti(const char fv[], Kolekcija A[], int & n)
{
   ifstream fd (fv);
   int val, min;
   char eil[CPav+1];
   fd >> n;
   fd.ignore(80, '\n');
   for (int i = 0; i < n; i++) {
      fd.get(eil, CPav);
      A[i].pav = eil;
      fd >> A[i].metai;
      fd >> val >> min;
      fd >> A[i].kiek;
      fd.ignore(80, '\n');
      A[i].laikas = val * 60 + min;
   }
   fd.close();
}
//-----------------------------------------------------------------------
void Spausdinti(Kolekcija A[], int n)
{
   ofstream fr (CRfv);
   int laikas = 0;
   double vid = 0;
   for (int i = 0; i < n; i++) {
     laikas += A[i].laikas;
     vid += A[i].kiek;
   }
   fr << laikas / 60 << " " << laikas % 60 << endl;
   fr << left << setprecision(3) << vid / n << endl;
   for (int i = 0; i < n; i++)
      fr << setw(20) << left << A[i].pav << " " << A[i].metai << endl;
   fr.close();
}
//-----------------------------------------------------------------------
void Rikiuoti(Kolekcija A[], int n)
{
   for (int i = 0; i < n; i++)
      for (int j = i + 1; j < n; j++)
         if (A[j].kiek < A[i].kiek) {
            Kolekcija sp = A[i];
            A[i] = A[j];
            A[j] = sp;
         }
}
