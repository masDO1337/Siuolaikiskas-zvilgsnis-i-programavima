// Raidziu daznis tekste
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;
const char CDfv[] = "Duomenys.txt"; // pradiniu duomenu failo vardas
const char CRfv[] = "Rezultatas.txt"; // rezultatu failo vardas
const int CMax = 256; // masyvø dydis
//----------------------------------------------------------------------
void Skaityti(char S[], int A[], int & n);
void Rasyti(char S[], int A[], int n);
//----------------------------------------------------------------------
int main() {
   char S[CMax];
   int A[CMax];
   int n = 0;
   Skaityti(S, A, n);
   Rasyti(S, A, n);
   return 0;
}
//----------------------------------------------------------------------
// Apskaiciuoja ir grazina simbolio sim pasikartojimo pradiniu duomenu faile skaiciu
void Skaityti(char S[], int A[], int & n) {
   char ss;
   n = 0;

   S[n] = '0'; A[n] = 0; n++;
   S[n] = '1'; A[n] = 0; n++;
   S[n] = '2'; A[n] = 0; n++;
   S[n] = '3'; A[n] = 0; n++;
   S[n] = '4'; A[n] = 0; n++;
   S[n] = '5'; A[n] = 0; n++;
   S[n] = '6'; A[n] = 0; n++;
   S[n] = '7'; A[n] = 0; n++;
   S[n] = '8'; A[n] = 0; n++;
   S[n] = '9'; A[n] = 0; n++;

   ifstream fd(CDfv);
   while (!fd.eof()) {
      fd.get(ss);
      for (int i = 0; i <= n; i++) {
        if (!fd.eof() && (ss == S[i])) {
          //cout << S[i] << '\n';
          A[i]++;
        }
      }
   }
   fd.close();
}

//----------------------------------------------------------------------
void Rasyti(char S[], int A[], int n) {
  ofstream fr(CRfv);
  for (int i = 0; i < n; i++) {
    fr << S[i] << " " << setw(2) << A[i] << endl;
  }
  fr.close();
}
//----------------------------------------------------------------------
