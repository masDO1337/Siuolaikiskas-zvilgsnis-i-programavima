#include <fstream>
#include <iomanip>
#include <iostream>
#include <cmath>
using namespace std;
const char CDfv1[] = "duomenys1.txt";
const char CDfv2[] = "duomenys2.txt";
const char CDfv3[] = "duomenys3.txt";
const char CRfv[] = "rezultatai.txt";
const int CMax    = 31;
//-------------------------------------------------------------------
void Skaityti(const char fv[], int A[]);
void Spausdinti(const char fv[], int A1[], int A2[]);
void Filtravimas(int A[], string mode, int B[]);
//-------------------------------------------------------------------
int main()
{
   int A1[CMax];
   int A2[CMax];
   int A3[CMax];

   for (int i = 0; i < CMax; i++) {
       A3[i] = 0;
   }

   Skaityti(CDfv1, A1);
   Skaityti(CDfv2, A2);
   Filtravimas(A1, "remove", A2);
   Skaityti(CDfv3, A2);
   Filtravimas(A1, "add", A2);

   Filtravimas(A3, "x>2", A1);

   Spausdinti(CRfv, A1, A3);

   cout << "Done!" << '\n';
   return 0;
}

//-------------------------------------------------------------------
void Skaityti(const char fv[], int A[]) {
    ifstream fd(fv);
    int id = 0;
    int n;

    for (int i = 0; i < CMax; i++) {
        A[i] = 0;
    }

    fd >> n;

    for (int i = 0; i < n; i++) {
      fd >> id;
      fd >> A[id];
    }

    fd.close();
}
//-------------------------------------------------------------------
void Spausdinti(const char fv[], int A1[], int A2[]) {
  ofstream fr(fv);
  fr << "Galutinis" << endl;
  for (int i = 0; i < CMax; i++) {
    if (A1[i] != 0) {
      fr << i << " " << A1[i] << endl;
    }
  }
  fr << "Papildomas" << endl;
  for (int i = 0; i < CMax; i++) {
    if (A2[i] != 0) {
      fr << i << " " << A2[i] << endl;
    }
  }
  fr.close();
}
//-------------------------------------------------------------------
void Filtravimas(int A[], string mode, int B[]) {
  if (mode == "add") {
    for (int i = 0; i < CMax; i++) {
      if (B[i] != 0) {
        A[i] += B[i];
      }
    }
  }
  if (mode == "remove") {
    for (int i = 0; i < CMax; i++) {
      if (B[i] != 0) {
        A[i] -= B[i];
      }
    }
  }
  if (mode == "x>2") {
    for (int i = 0; i < CMax; i++) {
      if (B[i] > 2) {
        A[i] = B[i]-2;
        B[i] = 2;
      }
    }
  }
}
