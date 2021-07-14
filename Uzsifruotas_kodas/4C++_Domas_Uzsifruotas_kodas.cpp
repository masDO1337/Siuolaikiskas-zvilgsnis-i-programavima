#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;
const char CDfvA[] = "Duomenys1_Uzsifruotas_kodas.txt"; // pradiniu duomenu failo vardas
const char CDfvB[] = "Duomenys2_Uzsifruotas_kodas.txt"; // pradiniu duomenu failo vardas
const char CRfv[] = "Rezultatas_Uzsifruotas_kodas.txt"; // rezultatu failo vardas
const int CMax = 10; // masyvø dydis
//----------------------------------------------------------------------
void Skaityti(char S[], char A[], int & m, int & n);
void Rasyti(char S[], char A[], int m, int n);
//----------------------------------------------------------------------
int main() {
   char S[CMax];
   char A[CMax];
   int m = 0;
   int n = 0;
   Skaityti(S, A, m, n);
   Rasyti(S, A, m, n);
   return 0;
}
//----------------------------------------------------------------------
// Apskaiciuoja ir grazina simbolio sim pasikartojimo pradiniu duomenu faile skaiciu
void Skaityti(char S[], char A[], int & m, int & n) {
   char ss;
   n = 0;
   m = 0;

   ifstream fd(CDfvA);
   while (!fd.eof()) {
      fd.get(ss);
      for (char i = 'a'; i <= 'z'; i++) {
        if (tolower(ss) == i) {
          A[m] = tolower(ss);
          m ++;
        }
      }
   }
   fd.close();

   ifstream fdB(CDfvB);
   while (!fdB.eof()) {
      fdB.get(ss);
      for (int i = 0; i < m; i++) {
        if (tolower(ss) == A[i]) {
          S[n] = tolower(ss);
          n ++;
        }
      }
   }
   fdB.close();
}
//----------------------------------------------------------------------
void Rasyti(char S[], char A[], int m, int n) {
  ofstream fr(CRfv);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (S[i] == A[j]) {
        fr << j;
      }
    }
  }
  fr.close();
}
//----------------------------------------------------------------------
