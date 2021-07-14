#include <fstream>
#include <iomanip>
#include <iostream>
#include <cmath>
using namespace std;
const char CDfv[] = "duomenys.txt";
const char CRfv[] = "rezultatai.txt";
const int CMax    = 10;
//-------------------------------------------------------------------
void Skaityti(const char fv[], int A[], int B[], int & n, int & m);
void Spausdinti(const char fv[], int C[], int n);
void Rikiavimas(int A[], int B[], int C[], int & n, int m);
//-------------------------------------------------------------------
int main()
{
   int A[CMax], B[CMax], C[CMax];
   for (int i = 0; i <= CMax; i++) C[i] = 0;
   int n, m;
   Skaityti(CDfv, A, B, n, m);
   Rikiavimas(A, B, C, n, m);
   Spausdinti(CRfv, C, n);
   return 0;
}

//-------------------------------------------------------------------
void Skaityti(const char fv[], int A[], int B[], int & n, int & m)
{
    ifstream fd(fv);
    fd >> n;
    for (int i = 0; i < n; i++) {
        fd >> A[i];
    }
    fd >> m;
    for (int i = 0; i < m; i++) {
        fd >> B[i];
    }
    fd.close();
}
//-------------------------------------------------------------------
void Spausdinti(const char fv[], int C[], int n)
{
  ofstream fr(fv);
  for(int i=0; i<n; i++) {
    fr << C[i] << " " ;
  }
  fr.close();
}
//-------------------------------------------------------------------
void Rikiavimas(int A[], int B[], int C[], int & n, int m)
{
  int nNew = 0;
  int nOff = 0;
  for (int i = 0; i < n; i++) {
    C[nNew] = A[i];
    nNew ++;
    nOff = nNew;
    for (int j = 0; j < m; j++) {
      if (B[j] % A[i] == 0) {
        if (C[nNew-1] == A[i]) {
          C[nNew] = B[j];
          nNew ++;
        } else {
          for (int z = nNew; z > nOff; z--) {
            C[z] = C[z-1];
          }
          C[nOff] = B[j];
          nNew ++;
        }
      }
    }
  }
  n = nNew;
}
