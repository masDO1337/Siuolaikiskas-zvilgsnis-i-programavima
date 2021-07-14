#include <fstream>
#include <iomanip>
#include <iostream>
#include <cmath>
using namespace std;
const char CDfv[] = "Duomenys2.txt";
const char CRfv[] = "Rezultatai2.txt";
const int CMax    = 50;
//-------------------------------------------------------------------
void Skaityti(const char fv[], int A[], int & p, int & n);
void Spausdinti(const char fv[], int A[], int p, int n);
void pirko(int A[], int p, int n, int & pr, int & l);
//-------------------------------------------------------------------
int main()
{
   int A[CMax];
   int n, p;
   Skaityti(CDfv, A, p, n);
   Spausdinti(CRfv, A, p, n);
   cout << "Done!" << '\n';
   return 0;
}

//-------------------------------------------------------------------
void Skaityti(const char fv[], int A[], int & p, int & n)
{
   int index = 0;
   int a = 0;
   ifstream fd(fv);
   fd >> p;
   fd >> n;
   for (int i = 0; i < n; i++) {
     fd >> a;
     A[index] = a;
     index ++;
     for (int j = 0; j < a; j++) {
       fd >> A[index];
       index ++;
     }
   }
   fd.close();
}
//-------------------------------------------------------------------
void Spausdinti(const char fv[], int A[], int p, int n)
{
   ofstream fr(fv);
   int pr, l;
   pirko(A, p, n, pr, l);
   fr << pr << " " << l << endl;
   fr.close();
}
//-------------------------------------------------------------------
void pirko(int A[], int p, int n, int & pr, int & l) {
  int index = 0;
  int kaina = 0;
  int a = 0;
  pr = 0;
  l = p;
  for (int i = 0; i < n; i++) {
    kaina = 0;
    a = A[index];
    index ++;
    for (int j = 0; j < a; j++) {
      if (l >= A[index]) {
        if (A[index] > kaina) {
          kaina = A[index];
        }
      }
      index ++;
    }
    if (kaina >= 1) {
      l -= kaina;
      pr ++;
    }
  }
}
