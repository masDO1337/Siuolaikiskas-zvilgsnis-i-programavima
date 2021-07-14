// kartojimas
#include <fstream>
#include <iomanip>
#include <iostream>
#include <cmath>
using namespace std;
const char CD1fv[] = "duomenys1.txt"; // pradini� duomen� failo vardas
const char CD2fv[] = "duomenys2.txt";
const char CD3fv[] = "duomenys3.txt";
const char CRfv[] = "Rezultatas.txt"; // rezultat� failo vardas
const char CMax = 31;
//-------------------------------------------------------------------
void Skaityti(const char fv[], int D[], int X[], int & k);
void Spausdinti(ofstream & fr, int D[], int X[], int k);
void Iterpti(int A[], int n, int k, int b);
void Salinti(int A[], int B[], int & n, int k);
//-------------------------------------------------------------------
int main()
{
int A1[CMax], B1[CMax], n;
int A2[CMax], B2[CMax], k;
int A3[CMax], B3[CMax], p;
//
Skaityti(CD1fv, A1, B1, n);
Skaityti(CD2fv, A2, B2, k);
Skaityti(CD3fv, A3, B3, p);
// Pasaliname perkeliamus kontrolinius
for (int d=0; d<k; d++) {
    for (int x=0; x<n; x++) {
        if (A2[d] == A1[x]) {
            B1[x] -= B2[d];
            if (B1[x] == 0) {
                Salinti(A1, B1, n, x);
            }
        }
    }
}
// Papildom esamas dienas kontroliniais
for (int d=0; d<n; d++) {
    for (int x=0; x<p; x++) {
        if (B1[d] != 2) {
        if (A1[x] == A3[d]) {
            B1[d] += 1;
            B3[x] -= 1;
            if (B3[x] == 0) Salinti(A3, B3, p, x);
        }}
    }
}
//
// VVVVVVVVVVVVVVVVVVVVV    ERROR       VVVVVVVVVVVVVVVVVVV
for (int x=0; x < p; x++) {
    for (int d=0; d < n; d++) {
      cout << A3[x] << endl;
      cout << A1[d] << endl;
       if ((A3[x] < A1[d]) || (A3[x] > A1[d])) {
           Iterpti(A1, n, d, A3[x]);
           Iterpti(B1, n, d, B3[x]);
           n += 1;
           Salinti(A3, B3, p, x);
       }
    }
}
// VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV
ofstream fr("rezultatai1.txt");
fr << "Galutinis" << endl;
Spausdinti(fr, A1, B1, n);
fr << "Papildomas" << endl;
Spausdinti(fr, A3, B3, p);



fr.close();
cout << "OK" << endl;
   return 0;
}
//-------------------------------------------------------------------
//
void Skaityti(const char fv[], int D[], int X[], int & k)
{
  ifstream fd(fv);
  fd >> k;
  for (int i = 0; i < k; i++) {
  fd >> D[i];
  fd >> X[i]; }
  fd.close();
}
//--------------------------------------------------------------------
//
void Spausdinti(ofstream & fr, int D[], int X[], int k)
{
for (int i = 0; i < k; i++)
fr << D[i] << " " << X[i] << endl;
fr << endl;
}
//--------------------------------------------------------------------
//
void Iterpti(int A[], int n, int k, int b)
{
  for (int i = n; i > k; i--)
    A[i] = A[i-1];
  A[k] = b;
}
//----------------------------------------------------------------------
//
void Salinti(int A[], int B[], int & n, int k)
{
  for (int i = k; i < n - 1; i++) {
    A[i] = A[i+1];
    B[i] = B[i+1]; }
  n = n - 1;
}
