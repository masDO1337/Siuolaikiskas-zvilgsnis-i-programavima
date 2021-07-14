#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;
const char CDfv[] = "Duomenys_Mergaiciu_paslaptys.txt"; // pradiniu duomenu failo vardas
const char CRfv[] = "Rezultatas_Mergaiciu_paslaptys.txt"; // rezultatu failo vardas
const int CMax = 256; // masyvø dydis
//----------------------------------------------------------------------
void Skaityti(char S[], int A[], int & m, int & n);
void kita(char S[], int A[], int m, int n);
void Rasyti(char S[], int n);
//----------------------------------------------------------------------
int main() {
   char S[CMax];
   int A[CMax];
   int n = 0;
   int m = 0;
   Skaityti(S, A, m, n);
   kita(S, A, m, n);
   Rasyti(S, n);
   //cout << "/* message */" << '\n';
   return 0;
}
//----------------------------------------------------------------------
// Apskaiciuoja ir grazina simbolio sim pasikartojimo pradiniu duomenu faile skaiciu
void Skaityti(char S[], int A[], int & m, int & n) {
   char ss;
   char s[CMax];
   int x = 0;
   n = 0;
   m = 0;
   for (char i = 'a'; i <= 'z'; i++) {
     s[x] = i; x ++;
   }
   s[x] = 'ą'; x ++;
   s[x] = 'č'; x ++;
   s[x] = 'ę'; x ++;
   s[x] = 'ė'; x ++;
   s[x] = 'į'; x ++;
   s[x] = 'š'; x ++;
   s[x] = 'ų'; x ++;
   s[x] = 'ū'; x ++;
   s[x] = 'ž'; x ++;

   ifstream fd(CDfv);
   while (!fd.eof()) {
      fd.get(ss);
      for (int i = 0; i < x; i++) {
        if (ss == s[i]) {
          S[n] = ss;
          n ++;
        }
      }
      if (ss == ' ') {
        S[n] = ss;
        n ++;
        A[m] = n-1;
        m ++;
      }
   }
   A[m] = n; m++;
   fd.close();
}
//----------------------------------------------------------------------
void kita(char S[], int A[], int m, int n) {
  int x = 0;
  for (int i = 0; i < m; i++) {
    //cout << A[i] << '\n';
    if (i > 0) {x = A[i-1]+1;}
    int b = (A[i] - x)/2;
    //cout << b << '\n';
    for (int j = 0; j < b; j++) {
      char a = S[A[i]-1];
      //cout << a << '\n';
      for (int z = A[i]-1; z > x; z--) {
        S[z] = S[z-1];
      }
      S[x] = a;
    }
  }
}
//----------------------------------------------------------------------
void Rasyti(char S[], int n) {
  ofstream fr(CRfv);
  for (int i = 0; i < n; i++) {
    fr << S[i];
  }
  fr.close();
}
//----------------------------------------------------------------------
