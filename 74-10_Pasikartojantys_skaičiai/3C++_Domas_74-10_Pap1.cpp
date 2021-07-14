#include <fstream>
#include <iomanip>
#include <iostream>
#include <cmath>
using namespace std;
const char CDfv[] = "DuomenysPS.txt";
const char CRfv[] = "RezultatasPS1.txt";
const int CMax    = 1000;
//-------------------------------------------------------------------
void Skaityti(const char fv[], int A[], int & n, int m, int & mind);
void Spausdinti(const char fv[], int A[], int n);
//-------------------------------------------------------------------
int main()
{
   int S[CMax]; int n;
   int m = 11;
   int mind = 0;
   ofstream fr;
   Skaityti(CDfv, S, n, m, mind);
   fr.open(CRfv); fr.close();
   Spausdinti(CRfv, S, n);
   fr.open(CRfv, ios:: app);
   if (mind >= 0) { // skaicius m sekoje yra
      fr << "Skaiciaus " << m << " indeksas masyve " << mind << endl;
      S[m] ++;
   }
   else {
      fr << "Skaicius " << m << " masyve nerastas" << endl;
   }
   Spausdinti(CRfv, S, n);
   fr.close();
   cout << "Done" << '\n';
   return 0;
}


//-------------------------------------------------------------------
void Skaityti(const char fv[], int A[], int & n, int m, int & mind)
{
   ifstream fd(fv);
   for (int i = 0; i <= CMax; i++) {
      A[i] = 0;
   }
   int a = 0;
   fd >> n;
   for (int i = 0; i < n; i++) {
     fd >> a;
     A[a] ++;
     if (mind == 0) {
       if (a == m) mind = i;
     }
   }
   fd.close();
}
//-------------------------------------------------------------------
void Spausdinti(const char fv[], int A[], int n)
{
   ofstream fr(fv, ios::app);
   fr << " Skaiciu seka " << endl;
   fr << "--------------" << endl;
   for (int i = 0; i <= CMax; i++) {
      if (A[i] > 0) {
        fr << setw(4) << A[i] << setw(4) << i << endl;
      }
   }
   fr << "--------------" << endl;
   fr.close();
}
//-------------------------------------------------------------------
