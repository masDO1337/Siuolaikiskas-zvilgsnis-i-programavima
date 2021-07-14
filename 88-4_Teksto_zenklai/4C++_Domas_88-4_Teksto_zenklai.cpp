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

   S[n] = 'r'; A[n] = 0; n++;
   S[n] = 's'; A[n] = 0; n++;
   S[n] = 't'; A[n] = 0; n++;
   S[n] = 'k'; A[n] = 0; n++;

   ifstream fd(CDfv);
   while (!fd.eof()) {
      fd.get(ss);
      if (!fd.eof()) {
        for (char i = 'a'; i < 'z'; i++) {
          if (tolower(ss) == i) {
            A[0] ++;
          }
        }
        if (ss == 'ą' || ss == 'č' || ss == 'ę' || ss == 'ė' || ss == 'į' || ss == 'š' || ss == 'ų' || ss == 'ū' || ss == 'ž') {
          A[0] ++;
        }
        if (ss == '0' || ss == '1' || ss == '2' || ss == '3' || ss == '4' || ss == '5' || ss == '6' || ss == '7' || ss == '8' || ss == '9') {
          A[1] ++;
        }
        if (ss == ' ') {
          A[2] ++;
        }
        if (ss == '.' || ss == ',' || ss == ';' || ss == ':' || ss == '—' || ss == '(' || ss == ')') {
          A[3] ++;
        }
      }
   }
   fd.close();
}

//----------------------------------------------------------------------
void Rasyti(char S[], int A[], int n) {
  ofstream fr(CRfv);
  for (int i = 0; i < n; i++) {
    if (S[i] == 'r') {
      fr << "Raidziu yra  " << setw(2) << A[i] << endl;
    }
    if (S[i] == 's') {
      fr << "Skaitmeniu yra  " << setw(2) << A[i] << endl;
    }
    if (S[i] == 't') {
      fr << "Tarpo simboliu yra  " << setw(2) << A[i] << endl;
    }
    if (S[i] == 'k') {
      fr << "Kitokiu simboliu yra  " << setw(2) << A[i] << endl;
    }
  }
  fr.close();
}
//----------------------------------------------------------------------
