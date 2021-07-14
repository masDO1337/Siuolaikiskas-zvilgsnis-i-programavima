#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;
const char CDfv[] = "U2.txt";
const char CRfv[] = "U2.res";
const int CMax0 = 10;
const int CMax1 = 100;
const int CPav = 40;
//-----------------------------------------------------------------------
struct Knygos {
          string pav;
          int kiekBalsu = 0;
          int var[CMax1];
          double vidurkis;
};
//-----------------------------------------------------------------------
void Skaityti(const char fv[], Knygos A[], int & k);
void vidurkis(Knygos A[], int k);
void rikuoti(Knygos A[], int k);
void Spausdinti(Knygos A[], int k);
//-----------------------------------------------------------------------
int main()
{
   Knygos A[CMax0]; int k;
   Skaityti(CDfv, A, k);
   vidurkis(A, k);
   rikuoti(A, k);
   Spausdinti(A, k);
   return 0;
}
//-----------------------------------------------------------------------

void Skaityti(const char fv[], Knygos A[], int & k)
{
   ifstream fd (fv);
   char eil[CPav+1];
   int n = 0;
   fd >> n;
   fd >> k;
   fd.ignore(80, '\n');
   for (int i = 0; i < k; i++) {
      fd.get(eil, CPav);
      A[i].pav = eil;
      A[i].kiekBalsu = n;
      for (int j = 0; j < n; j++) {
        fd >> A[i].var[j];
      }
      fd.ignore(80, '\n');
   }
   fd.close();
}
//-----------------------------------------------------------------------
void Spausdinti(Knygos A[], int k)
{
   ofstream fr (CRfv);
   double var = 0;
   for (int i = 0; i < k; i++) {
       fr << setw(20) << right << A[i].pav << setw(1) << A[i].kiekBalsu << " " << fixed << setprecision(2) << A[i].vidurkis << endl;
       var += A[i].vidurkis;
   }
   var /= k;
   fr << fixed << setprecision(2) << var << endl;
   fr.close();
}
//-----------------------------------------------------------------------
void vidurkis(Knygos A[], int k)
{
  for (int i = 0; i < k; i++) {
    int x = 0;
    int y = 0;
    for (int j = 0; j < A[i].kiekBalsu; j++) {
      x += A[i].var[j];
      if (A[i].var[j] <= 0) {
        y ++;
      }
    }
    A[i].kiekBalsu -= y;
    A[i].vidurkis = (double)x/(double)A[i].kiekBalsu;
  }
}
//-----------------------------------------------------------------------
void rikuoti(Knygos A[], int k)
{
  // Nebera laiko :(
}
//-----------------------------------------------------------------------
