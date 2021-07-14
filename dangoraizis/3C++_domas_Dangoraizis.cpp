// Siena
#include <fstream>
#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;
const char CDfv[] = "duomenys.txt"; // pradiniø duomenø failo vardas
const char CRfv[] = "rezultatai.txt"; // rezultatø failo vardas

//-------------------------------------------------------------------

int Fun(int a, int b);

//-------------------------------------------------------------------
int main() {
   int n;
   double ats = 0;

   ifstream fd(CDfv);
   fd >> n;
   fd.close();

   ats = Fun(n, 0);

   ofstream fr(CRfv);
   fr << ats;
   fr.close();
   return 0;
}
//-------------------------------------------------------------------

int Fun(int a, int b) {
  int c;

  for (int i = 1; i <= a; i++) {
    c = i;
    int d = 1;
    while (c >= 10) {
      c /= 10;
      d += 1;
    }
    b += d;
  }
  return b;
}
