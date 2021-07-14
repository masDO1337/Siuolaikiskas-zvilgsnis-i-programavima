#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;
const char CDfv[] = "U1.txt";
const char CRfv[] = "Rezultatai.txt";
const int CMax = 40;
const int CPav = 10;
//-----------------------------------------------------------------------
struct Imones {
  string pav;
  int x;
  int y;
  int atstumas = 0;
  bool nuvesta = false;
};
//-----------------------------------------------------------------------
void Skaityti(const char fv[], Imones A[], int & n, int & MAXAtstumas);
void Spausdinti(Imones A[], int n, int MAXAtstumas);
void Atstumas(Imones A[], int n, int MAXAtstumas, int & atstumas);
//-----------------------------------------------------------------------
int main()
{
   Imones A[CMax]; int n;
   int MAXAtstumas;
   int atstumas = 0;
   Skaityti(CDfv, A, n, MAXAtstumas);
   Atstumas(A, n, MAXAtstumas, atstumas);
   Spausdinti(A, n, atstumas);
   return 0;
}
//-----------------------------------------------------------------------

void Skaityti(const char fv[], Imones A[], int & n, int & MAXAtstumas)
{
   ifstream fd (fv);
   char eil[CPav+1];
   fd >> n;
   fd >> MAXAtstumas;
   fd.ignore(80, '\n');
   for (int i = 0; i < n; i++) {
      fd.get(eil, CPav);
      A[i].pav = eil;
      fd >> A[i].x >> A[i].y;
      fd.ignore(80, '\n');
   }
   fd.close();
}
//-----------------------------------------------------------------------
void Spausdinti(Imones A[], int n, int atstumas)
{
   ofstream fr (CRfv);
   int nurvazuota = 0;
   string paskPav;
   for (int i = 0; i < n; i++) {
     if (!A[i].nuvesta) {break;}
     nurvazuota ++;
     paskPav = A[i].pav;
   }
   fr << nurvazuota << " " << atstumas << " " << paskPav << endl;
   fr.close();
}
//-----------------------------------------------------------------------
void Atstumas(Imones A[], int n, int MAXAtstumas, int & atstumas)
{
  for (int i = 0; i < n; i++) {
    A[i].atstumas = 0;
    if (A[i].x < 0) {
      A[i].atstumas += A[i].x*-1;
    } else {
      A[i].atstumas += A[i].x;
    }
    if (A[i].y < 0) {
      A[i].atstumas += A[i].y*-1;
    } else {
      A[i].atstumas += A[i].y;
    }
    if (atstumas+(A[i].atstumas*2) <= MAXAtstumas) {
      atstumas += A[i].atstumas*2;
      A[i].nuvesta = true;
    }
  }
}
