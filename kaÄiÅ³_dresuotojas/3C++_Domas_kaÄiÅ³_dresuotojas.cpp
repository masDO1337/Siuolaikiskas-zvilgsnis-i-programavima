// Medeli� sodinimas
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
const char CDfv[] = "Duomenys.txt"; // pradini� duomen� failo vardas
const char CRfv[] = "Rezultatai.txt"; // rezultat� failo vardas
//-------------------------------------------------------------------
int main()
{
   int n;
   int t = 0;

   ifstream fd(CDfv);

   fd >> n;

   int ta[n];

   for (int i = 1; i <= n; i++) {
         fd >> ta[i];
         t += ta[i];
   }

   fd.close();

   ofstream fr(CRfv);

   fr << t << endl;

   fr << t/n << endl;

   fr.close();

   return 0;
}
