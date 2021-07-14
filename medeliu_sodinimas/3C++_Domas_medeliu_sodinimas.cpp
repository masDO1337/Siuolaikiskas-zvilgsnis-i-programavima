// Medeliø sodinimas
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
const char CDfv[] = "Duomenys2.txt"; // pradiniø duomenø failo vardas
const char CRfv[] = "Rezultatai2.txt"; // rezultatø failo vardas
//-------------------------------------------------------------------
int main()
{
   int n, m, x1, y1; // sodininkø skaièius ir kiekvieno sodininko uþsakytø medeliø skaièius
   int s = 0;
   int x = 0;
   int y = 0;

   ifstream fd(CDfv);

   fd >> n;
   fd >> x1;
   fd >> y1;

   cout << "n = " << n << '\n';
   cout << "x1 = " << x1 << '\n';
   cout << "y1 = " << y1 << '\n';

   for (int i = 1; i <= n; i++) {

      fd >> m; // perskaitomas sodininko uþsakytø medeliø skaièius
      
      cout << "m" << i << " = " << m << '\n';

      s += m; // uþsakytø medeliø suma papildoma nauju skaièiumi

      if (m >= x1) { x += 1; }
   }

   fd.close();

   y = (int)(47 / 12) + 1;

   ofstream fr(CRfv);

   fr << s << endl;
   cout << "s = " << s << '\n';
   fr << x << endl;
   cout << "x = " << x << '\n';
   fr << y << endl;
   cout << "y = " << y << '\n';

   fr.close();

   return 0;
}
