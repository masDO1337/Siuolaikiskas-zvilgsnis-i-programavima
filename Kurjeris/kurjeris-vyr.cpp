#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;
const char CDfv[] = "kurjeris-vyr.in";
const char CRfv[] = "kurjeris-vyr.out";
const int CMax = 1000;

struct siuntinys {
         int miestas;
         int laikas;
};
//-----------------------------------------------------------------------
void Skaityti(int N[], int & n, siuntinys K[], int & m);
void Spausdinti(int ats);
//-----------------------------------------------------------------------
int main()
{
   int N[CMax];
   siuntinys K[CMax];
   int ats, n, m;
   ats = 0;

   Skaityti(N, n, K, m);
   int miestas = 0;
   int laikas = 0;
   for (int i = 0; i < m; i++) {
     for (int j = miestas; j < K[i].miestas; j++) {
       ats += N[j];
     }
     if (miestas > K[i].miestas) {
       for (int j = miestas-1; j > K[i].miestas-1; j--) {
         ats += N[j];
       }
     }
     miestas = K[i].miestas;
     laikas += K[i].laikas;
   }
   for (int j = miestas-1; j > -1; j--) {
     ats += N[j];
   }
   if (laikas < ats) {
     ats = -1;
   }
   Spausdinti(ats);
   return 0;
}
//-----------------------------------------------------------------------
void Skaityti(int N[], int & n, siuntinys K[], int & m)
{
   ifstream fd (CDfv);

   fd >> n;
   for (int i = 0; i < n; i++) {
     fd >> N[i];
   }
   fd >> m;
   for (int i = 0; i < m; i++) {
     fd >> K[i].miestas >> K[i].laikas;
   }

   fd.close();
}
//-----------------------------------------------------------------------
void Spausdinti(int ats)
{
   ofstream fr (CRfv);
   fr << ats << endl;
   cout << ats << endl;
   fr.close();
}
//-----------------------------------------------------------------------
