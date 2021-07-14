// Siena
#include <fstream>
#include <cmath>
#include <iostream>
using namespace std;
const char CDfv[] = "Duomenys.txt"; // pradiniø duomenø failo vardas
const char CRfv[] = "Rezultatai.txt"; // rezultatø failo vardas
//-------------------------------------------------------------------
int Plotas(int x1, int y1, int x2, int y2);
//-------------------------------------------------------------------
int main()
{
   int n;
   int sa, sp, spl;
   int x1, y1, x2, y2;
   ifstream fd(CDfv);
   fd >> sa >> sp;
   spl = sa * sp;
   fd >> n;
   for (int i = 1; i <= n; i++) {
      fd >> x1 >> y1 >> x2 >> y2;
      spl -=  Plotas(x1, y1, x2, y2);
   }
   fd.close();
   ofstream fr(CRfv);
   fr << spl;
   fr.close();
   return 0;
}
//-------------------------------------------------------------------
int Plotas(int x1, int y1, int x2, int y2)
{
   return fabs ((x1 - x2) * (y1 - y2));
}
