#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
   double d, s, r, g, k;

   cout << "Kiek Saulius ir Ramune pakvete bendrai draugu: "; cin >> d;
   cout << "Kiek Saulius pakvete savo draugu: "; cin >> s;
   cout << "Kiek Ramune pakvete savo draugiu: "; cin >> r;
   cout << "Kiek vaikai sutaupe pinigu: "; cin >> g;

   k = g / (d + s + r);

   if (k > 0) cout << endl << "Gali skirti kiekvienam sveciui: "<< fixed << setprecision(2) << k << " pinigu" << endl;
   else cout << "Vaikai nesutaupe pinigu !" << endl;

   return 0;
}
