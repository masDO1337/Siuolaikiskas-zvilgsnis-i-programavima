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
void Spausdinti(const char fv[], int A[], int B[], int n, int m);
void Ieskojimas(int X1[], int & x1, int X2[], int & x2, int k);
void Rikiavimas(int X[], int & x, int nr);
//-------------------------------------------------------------------
int main()
{
   int A[CMax], B[CMax];
   int n, m;
   Skaityti(CDfv, A, B, n, m);
   Ieskojimas(A, n, B, m, 100);
   Ieskojimas(B, m, A, n, 10);
   Spausdinti(CRfv, A, B, n, m);
   cout << "Done!" << '\n';
   return 0;
}

//-------------------------------------------------------------------
void Skaityti(const char fv[], int A[], int B[], int & n, int & m) {
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
void Spausdinti(const char fv[], int A[], int B[], int n, int m) {
  ofstream fr(fv);
  fr << "Rasos kolekcija: " << endl;
  for (int i = 0; i < n; i++) {
    fr << A[i] << " ";
  }
  fr << endl << "Rimo kolekcija: " << endl;
  for (int i = 0; i < m; i++) {
    fr << B[i] << " ";
  }
  fr.close();
}
//-------------------------------------------------------------------
void Ieskojimas(int X1[], int & x1, int X2[], int & x2, int k) {
  int i = 0;
  do {
    if ((X1[i] >= k) && (X1[i] < k*10)) {
      Rikiavimas(X2, x2, X1[i]);

      x1 --;
      for (size_t j = i; j < x1; j++) {
        X1[j] = X1[j+1];
      }
    } else {
      i ++;
    }
  } while(i < x1);
}
//-------------------------------------------------------------------
void Rikiavimas(int X[], int & x, int nr) {
  bool c = true;
  for (int i = 0; i < x; i++) {
    if ((nr >= X[i]) && (nr <= X[i+1]) && (c)) {
      x++;
      for (int j = x; j > i+1; j--) {
        X[j] = X[j-1];
      }
      X[i+1] = nr;
      c = false;
    } else if ((nr >= X[i]) && (i == x-1) && (c)) {
      x++;
      for (int j = x; j > i+1; j--) {
        X[j] = X[j-1];
      }
      X[i+1] = nr;
      c = false;
    }
  }
}
