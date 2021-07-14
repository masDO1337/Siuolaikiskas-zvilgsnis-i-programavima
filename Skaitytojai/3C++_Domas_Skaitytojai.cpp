#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;
const char CDfv[] = "Duomenys.txt";
const char CRfv[] = "Rezultatai.txt";
const int Max     = 30;
//-------------------------------------------------------------------
void Skaityti(int A[], int & n);
void Spausdinti(int A[], int n);

int KiekisVisu(int A[], int n);

double KiekisVisuVirkurkis(int A[], int n);
double KiekisVienoVirkurkisPerMenesi(int A[], int n);
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
   for (int i = 0; i < n; i++)
      fd >> A[i];
   fd.close();
}
//-------------------------------------------------------------------
void Spausdinti(int A[], int n) {
   ofstream fr(CRfv);
   fr << KiekisVisu(A, n) << endl;
   fr << fixed << setprecision(0) << KiekisVisuVirkurkis(A, n) << endl;
   fr << fixed << setprecision(1) << KiekisVienoVirkurkisPerMenesi(A, n) << endl;
   fr.close();
}
//-------------------------------------------------------------------
int KiekisVisu(int A[], int n) {
  int suma = 0;
  for (int i = 0; i < n; i++) {
    suma = suma + A[i];
  }
  return suma;
}
//-------------------------------------------------------------------
double KiekisVisuVirkurkis(int A[], int n) {
  int suma = 0;
  for (int i = 0; i < n; i++) {
    suma = suma + A[i];
  }
  return (double)suma/(double)n;
}
//-------------------------------------------------------------------
double KiekisVienoVirkurkisPerMenesi(int A[], int n) {
  double suma = 0;
  for (int i = 0; i < n; i++) {
    suma += (double)A[i]/(double)12;
  }
  return suma/(double)n;
}
//-------------------------------------------------------------------
