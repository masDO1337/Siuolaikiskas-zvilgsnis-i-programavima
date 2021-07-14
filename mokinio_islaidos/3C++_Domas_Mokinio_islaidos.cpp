#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;
const char CDfv[] = "Duomenys1.txt";
const char CRfv[] = "Rezultatai1.txt";
const int Max     = 31;
//-------------------------------------------------------------------
void Skaityti(int A[], int B[], int & n);
void Spausdinti(int A[], int B[], int n);
double sudeti(int A[], int n);
int MinOrMax(bool a, int A[], int B[], int n);
double vidurkis(int A[], int n);


//-------------------------------------------------------------------
int main() {
  int A[Max]; int B[Max]; int n;
  Skaityti(A, B, n);
  Spausdinti(A, B, n);
  cout << "OK" << '\n';
  return 0;
}
//-------------------------------------------------------------------
void Skaityti(int A[], int B[], int & n) {
   ifstream fd(CDfv);
   fd >> n;
   for (int i = 0; i < n; i++)
      fd >> A[i] >> B[i];
   fd.close();
}
//-------------------------------------------------------------------
void Spausdinti(int A[], int B[], int n) {
   ofstream fr(CRfv);
   fr << fixed << setprecision(2) << sudeti(B, n) << "\n";
   fr << fixed << MinOrMax(false, A, B, n) << "\n";
   fr << fixed << MinOrMax(true, A, B, n) << "\n";
   fr << fixed << setprecision(2) << vidurkis(B, n) << "\n";
   fr.close();
}
//-------------------------------------------------------------------
double sudeti(int A[], int n) {
  double a = 0;
  for (int i = 0; i < n; i++) {
    a += A[i];
  }
  return a;
}
//-------------------------------------------------------------------
int MinOrMax(bool a, int A[], int B[], int n) {
  int id = 0;
  for (int i = 0; i < n; i++) {
    if (a) {
      if (B[i] > B[id]) id = i;
    } else {
      if (B[i] < B[id]) id = i;
    }
  }
  return A[id];
}
//-------------------------------------------------------------------
double vidurkis(int A[], int n) {
  double a = 0;
  for (int i = 0; i < n; i++) {
    a += A[i];
  }
  return a/n;
}
