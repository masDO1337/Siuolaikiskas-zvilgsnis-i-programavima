#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;
const char CDfv[] = "U1.txt";
const char CRfv[] = "U1rez.txt";
const int CMax = 20;
//-----------------------------------------------------------------------
void Skaityti(const char fv[], int A[], int n);
void Spausdinti(int A[], int n);
void suvalge(int A[], int n);
bool likutis(int A[], int n);
//-----------------------------------------------------------------------
int main()
{
   int A[CMax]; int n = 20;
   Skaityti(CDfv, A, n);
   suvalge(A, n);
   Spausdinti(A, n);
   return 0;
}
//-----------------------------------------------------------------------
void Skaityti(const char fv[], int A[], int n)
{
   ifstream fd (fv);
   for (size_t i = 0; i < n; i++) {
     A[i] = 0;
     if (i < n/2) { fd >> A[i]; }
   }

   fd.ignore(80, '\n');
   fd.close();
}
//-----------------------------------------------------------------------
void Spausdinti(int A[], int n)
{
   ofstream fr (CRfv);
   for (size_t i = 0; i < n; i++) {
     fr << A[i] << ' ';
   }
   fr.close();
}
//-----------------------------------------------------------------------
void suvalge(int A[], int n)
{
  int M[CMax];
  for (size_t i = 0; i < n; i++) {
    M[i] = 0;
    if (i < n/2) M[i] = 10 - A[i];
  }
  while (likutis(M, n)) {
    int x = M[n-1];
    for (size_t i = n-1; i > 0; i--) {
      M[i] = M[i-1];
      if (M[i] > 0) {
        M[i] --;
        A[i] ++;
      }
    }
    M[0] = x;
  }
}
//-----------------------------------------------------------------------
bool likutis(int A[], int n)
{
  for (size_t i = 0; i < n; i++)
    if (A[i] > 0) return true;
  return false;
}
