#include <fstream>
#include <cmath>
#include <iostream>
using namespace std;
const char CDfv[] = "Duomenys.txt"; // pradiniu duomenu failo vardas
const char CRfv[] = "Rezultatai.txt"; // rezultatu failo vardas
//-------------------------------------------------------------------
void Fun(int & a, int & b, int & c);
//-------------------------------------------------------------------
int main()
{
   int n; // autobusu skaicius
   int a = 0;
   int f = 0;
   int m = 0;
   ifstream fd(CDfv);
   ofstream fr(CRfv);
   fd >> n;
   fr << "Bandymų rezultatai" << endl;
   fr << "--------------------" << endl;
   fr << "   a     F     m        " << endl;
   fr << "--------------------" << endl;
   for (int i = 1; i <= n; i ++) {
        fd >> a >> f >> m;
        Fun(a, f, m);
        fr << "   " << a << "     " << f << "     " << m << endl;
   }
   fd.close();
   fr.close();
   return 0;
}
//-------------------------------------------------------------------
void Fun(int & a, int & b, int & c) {
    if (a == 0) a = b/c;
    if (b == 0) b = a*c;
    if (c == 0) c = b/a;
}
//-------------------------------------------------------------------
