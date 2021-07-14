#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;
const char CDfv[] = "Duomenys.txt";
const char CRfv[] = "Rezultatai.txt";
const int CMax = 100;
//-----------------------------------------------------------------------
void Skaityti(int N[], int & n, int & T, int & B);
void Spausdinti(int ats);

//-----------------------------------------------------------------------
int main()
{
   int N[CMax];
   int n, suma, ats, T, B;
   ats = 0;
   suma = 0;
   Skaityti(N, n, T, B);

   ats += T;
   for (int i = 0; i < n; i++) {
     suma += N[i];
     if (N[i] >= B) {
       ats += N[i]/2;
     } else {
       ats += N[i];
     }
   }
   ats = suma - ats;
   Spausdinti(ats);
   return 0;
}
//-----------------------------------------------------------------------
void Skaityti(int N[], int & n, int & T, int & B)
{
   ifstream fd (CDfv);
   fd >> T;
   fd >> B;
   fd >> n;
   for (int i = 0; i < n; i++) {
     fd >> N[i];
   }
   fd.close();
}
//-----------------------------------------------------------------------
void Spausdinti(int ats)
{
   ofstream fr (CRfv);
   fr << ats << endl;
   fr.close();
}
//-----------------------------------------------------------------------
