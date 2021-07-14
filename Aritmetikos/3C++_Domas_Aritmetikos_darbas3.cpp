// Programuotojø maratonas
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;
const char CDfv[] = "Duomenys.txt";   // pradiniu duomenu failo vardas
const char CRfv[] = "Rezultatai.txt"; // rezultatø failo vardas
//-------------------------------------------------------------------
int main()
{
   int n;           // programuotoju skaicius
   int us = 0;      // programuotoju parasytu programu skaicius
   int ds = 0;      // visu dienu, kuriomis buvo rasomos programos, skaicius
   int p, d, up;    // programuotojo duomenys: per diena parasytu programøu skaicius,
   string line;
                   // dalyvavimo maratone dienu skaicius, is viso parasytu programu skaicius
   double uv;       // vidutiniskai per diena parasytu programu skaicius
   ifstream fd(CDfv);
   ofstream fr(CRfv);
   fd >> n;

   getline (fd,line);
   cout << "line overflow = " << line << '\n';

   for (int i = 1; i <= n; i++) {
      fd >> d;
      up = 0;
      for (int j = 1; j <= d; j++) {
         fd >> p;
         up = up + p;
         if (j == d) {
           getline (fd,line);
           cout << "line overflow = " << line << '\n';
         }
      }


      fr << up << " " << fixed << setprecision(1) << (double) up / d << endl;
      ds = ds + d;
      us = us + up;
   }
   fd.close();
   fr << us << endl;
   uv = (double) us / ds;
   fr << fixed << setprecision(1) << uv << endl;
   fr.close();
   return 0;
}
