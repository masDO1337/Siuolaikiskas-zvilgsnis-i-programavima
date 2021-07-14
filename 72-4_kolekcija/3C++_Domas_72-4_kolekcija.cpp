#include <fstream>
#include <iomanip>
#include <iostream>
#include <cmath>
using namespace std;
const char CD1fv[] = "Duomenys1.txt";
const char CD2fv[] = "Duomenys2.txt";
const char CRfv[] = "Rezultatai.txt";
const int CMax    = 1000;
//-------------------------------------------------------------------
void Skaityti(const char fv1[], const char fv2[], int & n, int & m, int A[], int B[]);
void Spausdinti(const char fv[], int A[], int B[], int n, int m);
//-------------------------------------------------------------------
int main()
{
   int A[CMax];
   int B[CMax];
   int n, m;
   Skaityti(CD1fv, CD2fv, n, m, A, B);
   Spausdinti(CRfv, A, B, n, m);
   cout << "Done!" << '\n';
   return 0;
}

//-------------------------------------------------------------------
void Skaityti(const char fv1[], const char fv2[], int & n, int & m, int A[], int B[]) {
   int x;
   for (int i = 1; i <= 1000; i++) {
      A[i] = 0;
      B[i] = 0;
   }
   ifstream fd(fv1);
   fd >> n;
   for (int i = 1; i <= n; i++) {
      fd >> x;
      A[x] = A[x] + 1;
   }
   fd.close();
   ifstream fd1(fv2);
   fd1 >> m;
   for (int i = 1; i <= m; i++) {
      fd1 >> x;
      B[x] = B[x] + 1;
   }
   fd1.close();
}
//-------------------------------------------------------------------
void Spausdinti(const char fv[], int A[], int B[], int n, int m)
{
   ofstream fr(fv);
   for (int i = 1; i <= 1000; i++) {
     if (A[i] > 1) {
       if (B[i] == 0) {
         fr << i << " ";
       }
     }
   }
   fr.close();
}
