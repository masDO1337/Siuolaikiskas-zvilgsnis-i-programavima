//Lenktyn�s
#include <iostream>
using namespace std;
int main()
{
   int kt, // kilometrai_tigras atsiliko
       kv, // kilometrai_vilkas atsiliko
       km, // kilometrai_mokytojas atsiliko
       gt, // greitis_tigro
       gv, // greitis_vilko
       gm; // greitis_mokytojo
   cout << "Tigras atsiliko: "; cin >> kt;
   cout << "Vilkas atsiliko: "; cin >> kv;
   cout << "Mokytojas atsiliko: "; cin >> km;
   cout << "Tigro greitis: "; cin >> gt;
   cout << "Vilko greitis: "; cin >> gv;
   cout << "Mokytojo greitis: "; cin >> gm;
   for (int i = 1; i <= 8; i++) {
      kt = kt - gt + 1; // tigras nubego gt km, o mokinys per ta pati laika nubego 1 km
      kv = kv - gv + 1; // vilkas nubego gv km, o mokinys  per ta pati laika nubego 1 km
      km = km - gm + 1; // mokytojas nubego gm km, o mokinys per ta pati laika nubego 1 km
   // cout << " kt = " << kt << " kv = " << kv << " km = " << km << endl;
   }
   if (kt <= 0) cout << "Tigras pavijo" << endl;
   else cout << "Tigras nepavijo" << endl;
   if (kv <= 0) cout << "Vilkas pavijo" << endl;
   else cout << "Vilkas nepavijo" << endl;
   if (km <= 0) cout << "Mokytojas pavijo" << endl;
   else cout << "Mokytojas nepavijo" << endl;
   return 0;
}
