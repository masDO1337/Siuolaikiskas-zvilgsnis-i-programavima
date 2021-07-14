#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;
const char CDfv[] = "Duomenys.txt"; // pradiniu duomenu failo vardas
const char CRfv[] = "Rezultatai.txt"; // rezultatu failo vardas
const int CMax = 100; // masyvø dydis
//----------------------------------------------------------------------
void Kiek(const char fv[], int A[], int & n);
void Rasyti(const char fv[], int A[], int n);
//----------------------------------------------------------------------
int main() {
   int A[CMax]; // raidziu pasikartojimo skaiciai
   int n = 0;
   Kiek(CDfv, A, n);
   Rasyti(CRfv, A, n);
   return 0;
}
//----------------------------------------------------------------------
// Apskaiciuoja ir grazina simbolio sim pasikartojimo pradiniu duomenu faile skaiciu
void Kiek(const char fv[], int A[], int & n) {
  for (int i = 0; i < CMax; i++) {
    A[i] = 0;
   }
   int a = 0;
   ifstream fd(fv);
   fd >> n;
   cout << n;
   for (int i = 0; i < n; i++) {
         fd >> a;
         cout << a;
        A[a] ++;
   }
   fd.close();
}

//----------------------------------------------------------------------
void Rasyti(const char fv[], int A[], int n) {
  ofstream fr(fv);
  for (int i = 0; i < CMax; i++) {
        if (A[i] > 0) {
            for (int i = 0; i < A[i]; i++) {
                fr << i << endl;
            }
        }
        //fr << A[i] << endl;
  }

  fr.close();
}
//----------------------------------------------------------------------
