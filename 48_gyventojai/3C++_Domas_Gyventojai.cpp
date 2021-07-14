#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;
const char CDfv[] = "Duomenys.txt";
const char CRfv[] = "Rezultatai.txt";
const int Max     = 500;
//-------------------------------------------------------------------
void Skaityti(int A[], int & n);
void Spausdinti(int A[], int n);
int KiekisGyventoju(int A[], int n);
int KiekisGyventojuPuse(int A[], int n, bool a);
double KiekisGyventojuPuseVirdurkis(int A[], int n, bool a);

//-------------------------------------------------------------------
int main() {
  int Kr[Max]; int n;
  Skaityti(Kr, n);
  Spausdinti(Kr, n);
  cout << "OK" << '\n';
  return 0;
}
//-------------------------------------------------------------------
void Skaityti(int A[], int & n) {
   ifstream fd(CDfv);
   fd >> n;
   int a;
   for (int i = 0; i < n; i++)
      fd >> a >> A[i];
   fd.close();
}
//-------------------------------------------------------------------
void Spausdinti(int A[], int n) {
   ofstream fr(CRfv);
   fr << KiekisGyventoju(A, n) << endl;
   fr << KiekisGyventojuPuse(A, n, true ) << endl;
   fr << KiekisGyventojuPuse(A, n, false) << endl;
   fr << fixed << setprecision(2) << KiekisGyventojuPuseVirdurkis(A, n, true ) << endl;
   fr << fixed << setprecision(2) << KiekisGyventojuPuseVirdurkis(A, n, false) << endl;
   fr.close();
}
//-------------------------------------------------------------------
int KiekisGyventoju(int A[], int n) {
  int suma = 0;
  for (int i = 0; i < n; i++)
     suma = suma + A[i];
  return suma;
}
//-------------------------------------------------------------------
int KiekisGyventojuPuse(int A[], int n, bool a) {
  int suma = 0;
  for (int i = 0; i < n; i++)
    if (a) {
      if (i % 2 == 0) {
        suma = suma + A[i];
      }
    } else {
      if (i % 2 == 1) {
        suma = suma + A[i];
      }
    }
  return suma;
}
//-------------------------------------------------------------------
double KiekisGyventojuPuseVirdurkis(int A[], int n, bool a) {
  int suma = 0;
  int nr = 0;
  for (int i = 0; i < n; i++) {
    if (a) {
      if (i % 2 == 0) {
        suma = suma + A[i];
        nr ++;
      }
    } else {
      if (i % 2 == 1) {
        suma = suma + A[i];
        nr ++;
      }
    }
  }
  double ret = (double)suma/(double)nr;
  return ret;
}
//-------------------------------------------------------------------
