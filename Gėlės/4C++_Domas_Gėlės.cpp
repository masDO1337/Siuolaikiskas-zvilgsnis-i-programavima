#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;
const char CDfv[] = "U1.txt";
const char CRfv[] = "U1rez.txt";
const int CMax = 30;
//-----------------------------------------------------------------------
struct Geles {
          int id;
          int m;
          int d;
          int trukme;
          int endm;
          int endd;
};
//-----------------------------------------------------------------------
void Skaityti(const char fv[], Geles A[], int & n);
void Spausdinti(Geles A[], int n);
//-----------------------------------------------------------------------
int main()
{
   Geles A[CMax]; int n;
   Skaityti(CDfv, A, n);
   for (int i = 0; i < n; i++) {
     A[i].endd = A[i].d + A[i].trukme - 1;
     A[i].endm = A[i].m;
     if (A[i].endd > 31) {
       do {
         if (A[i].endm == 6) {
           A[i].endd -= 30;
         } else {
           A[i].endd -= 31;
         }
         A[i].endm += 1;
       } while (A[i].endd > 31);
     }
   }
   Spausdinti(A, n);
   return 0;
}
//-----------------------------------------------------------------------

void Skaityti(const char fv[], Geles A[], int & n)
{
   ifstream fd (fv);
   fd >> n;
   fd.ignore(80, '\n');
   for (int i = 0; i < n; i++) {
      fd >> A[i].id;
      fd >> A[i].m >> A[i].d;
      fd >> A[i].trukme;
      fd.ignore(80, '\n');
   }
   fd.close();
}
//-----------------------------------------------------------------------
void Spausdinti(Geles A[], int n)
{
   ofstream fr (CRfv);
   int x = 0;
   int f[12];
   int id = 0;
   int MAX = 0;
   for (int i = 0; i < 12; i++) f[i] = 0;
   for (int i = 0; i < n; i++) if (A[i].m >= 6 && A[i].m <= 7) x ++;
   for (int i = 6; i <= 8; i++) {
     for (int j = 0; j < n; j++) {
       if (A[j].m >= 6 && A[j].m <= 8) {
         if (A[j].m <= i && i <= A[j].endm) {
           f[i] ++;
         }
       }
     }
     if (f[i] > MAX) {
       MAX = f[i];
       id = i;
     }
   }
   fr << x << endl;
   for (int i = 0; i < n; i++) {
     if (A[i].m == id && A[i].endm == id) {
       fr << A[i].m << " " << A[i].d << endl;
       fr << A[i].endm << " " << A[i].endd << endl;
     }
   }
   fr.close();
}
