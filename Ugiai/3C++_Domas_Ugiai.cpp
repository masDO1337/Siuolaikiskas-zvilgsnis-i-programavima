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

double KVir(int A[], int n);
double KVieLVir(int A[], int n, bool a);

string VLKS(int A[], int n, bool a);
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
   fr << fixed << setprecision(1) << KVir(A, n) << endl;
   fr << fixed << setprecision(2) << KVieLVir(A, n, false) << endl;
   fr << fixed << setprecision(2) << KVieLVir(A, n, true) << endl;
   fr << "Merginu komandos sudaryti " << fixed << setprecision(2) << VLKS(A, n, false) << endl;
   fr << "Vaikinu komandos sudaryti " << fixed << setprecision(2) << VLKS(A, n, true) << endl;
   fr.close();
}
//-------------------------------------------------------------------
double KVir(int A[], int n) {
  int suma = 0;
  for (int i = 0; i < n; i++) {
    if (A[i] < 0) {
        suma = suma + (A[i]*-1);
    }else {
        suma = suma + A[i];
    }
  }
  return (double)suma/(double)n;
}
//-------------------------------------------------------------------
double KVieLVir(int A[], int n, bool a) {
  int suma = 0;
  int nr = 0;
  for (int i = 0; i < n; i++) {
    if (!a) {
      if (A[i] > 0) {
        suma = suma + A[i];
        nr ++;
      }
    } else {
      if (A[i] < 0) {
        suma = suma + (A[i]*-1);
        nr ++;
      }
    }
  }
  return (double)suma/(double)nr;
}
//-------------------------------------------------------------------
string VLKS(int A[], int n, bool a) {
  int kiekis = 0;
  for (int i = 0; i < n; i++) {
    if (!a) {
      if (A[i] > 175) {
        kiekis ++;
      }
    } else {
      if ((A[i] < 0) && ((A[i]*-1) > 175)) {
        kiekis ++;
      }
    }
  }
  if (kiekis >= 7) {
    return "galima";
  } else {
    return "negalima " ;//+ to_string(kiekis);
  }
}
//-------------------------------------------------------------------
