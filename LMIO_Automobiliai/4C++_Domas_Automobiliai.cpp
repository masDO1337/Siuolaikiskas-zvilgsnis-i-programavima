#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;
const char CDfv[] = "Duomenys.txt";
const char CRfv[] = "Rezultatai.txt";
const int CMax = 1000;
//-----------------------------------------------------------------------
void Skaityti(int N[][20], int & n, char K[], int & m);
void Spausdinti(int ats);

//-----------------------------------------------------------------------
int main()
{
   int N[CMax][20];
   char K[20];
   int ats, n, m;
   ats = 0;

   Skaityti(N, n, K, m);

   int M[CMax];
   for (int i = 0; i < CMax; i++) {
     M[i] = 0;
   }

   for (int i = 0; i < m; i++) {
     int x = 0;
     int y = 0;
     if (K[i] == 'M') {
       x = 9999;
     }
     for (int j = 0; j < n; j++) {
       if (K[i] == 'D') {
         if (N[j][i] >= x) {
           x = N[j][i];
           M[j] ++;
           y = j;
         }
       }
       if (K[i] == 'M') {
         if (N[j][i] <= x) {
           x = N[j][i];
           M[j] ++;
           y = j;
         }
       }
     }
     if (y > 0) {
       if (N[0][i] != N[y][i]) {
         M[0] --;
       }
     }
   }

   int z = 0;
   int x = 0;

   for (int i = 0; i < n; i++) {
     if (M[i] >= x) {
       if (M[i] == M[ats]) {
         z ++;
       }
       x = M[i];
       ats = i;
     }
   }
   if (z > 1) {
     ats = -1;
   }
   Spausdinti(ats);
   return 0;
}
//-----------------------------------------------------------------------
void Skaityti(int N[][20], int & n, char K[], int & m)
{
   ifstream fd (CDfv);

   fd >> m;
   for (int i = 0; i < m; i++) {
     fd >> K[i];
   }

   fd >> n;
   for (int i = 0; i < n; i++) {
     for (int j = 0; j < m; j++) {
       fd >> N[i][j];
     }
   }

   fd.close();
}
//-----------------------------------------------------------------------
void Spausdinti(int ats)
{
   ofstream fr (CRfv);
   if (ats == -1) {
     fr << "Neegzistuoja" << endl;
   } else {
     fr << ats+1 << endl;
   }
   fr.close();
}
//-----------------------------------------------------------------------
