// Programuotoj¸ maratonas
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;
const char CDfv[] = "duomenys.txt";   // pradiniu duomenu failo vardas
const char CRfv[] = "rezultatai.txt"; // rezultat¸ failo vardas
//-------------------------------------------------------------------
int main()
{
    int n, m;
    double k, kd, kv;

    ifstream fd(CDfv);
    ofstream fr(CRfv);

    fd >> n >> m;

    for (int i = 1; i <= n; i++) {

      kd = 0;

      for (int j = 1; j <= m; j++) {
        fd >> k;
        kd += k;
      }

      fr << i << " " << fixed << setprecision(2) << kd << endl;
      kv += kd;
    }

    fr << fixed << setprecision(2) << kv << endl;
   return 0;
}
