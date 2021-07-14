// Autobusu tvarkarastis
#include <fstream>
#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;
const char CDfv[] = "Duomenys.txt"; // pradiniu duomenu failo vardas
const char CRfv[] = "Rezultatai.txt"; // rezultatu failo vardas
//-------------------------------------------------------------------
void MetCol(int a, double & b);
void MetPed(int a, double & b);
void MetJar(int a, double & b);
//-------------------------------------------------------------------
int main()
{
   int n;
   double a;
   double Col, Ped, Jar;

   ifstream fd(CDfv);
   ofstream fr(CRfv);
   fr << "Metrai    Coliai   Pedos   Jardai" << endl;
   fd >> n;
   for (int i = 1; i <= n; i++) {
      fd >> a;
      MetCol(a, Col);
      MetPed(a, Ped);
      MetJar(a, Jar);

      fr << fixed << setprecision(0) << a;
      if (a >= 100) { fr << "       " << fixed << setprecision(2) << Col;
      } else if (a >= 10) { fr << "        " << fixed << setprecision(2) << Col;
      } else { fr << "         " << fixed << setprecision(2) << Col; }
      if (Col >= 100) { fr << "   " << Ped; }else{ fr << "    " << Ped; }
      if (Ped >= 10) { fr << "   " << Jar; }else{ fr << "    " << Jar; }
      fr << endl;
   }
   fd.close();
   fr.close();
   return 0;
}
//-------------------------------------------------------------------
void MetCol(int a, double & b) {
  b = a * 39.370;
}
void MetPed(int a, double & b) {
  b = a * 3.2808;
}
void MetJar(int a, double & b) {
  b = a * 1.0936;
}
//-------------------------------------------------------------------
