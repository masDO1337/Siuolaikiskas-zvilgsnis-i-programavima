// Krep�ininkai
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;
const char CDfv[] = "Duomenys.txt";
const char CRfv[] = "Rezultatai.txt";
const int CMax = 30;
//-----------------------------------------------------------------------
struct Mokinys {
         string pav; // mokinio vardas
         double ugis;
         int    kiek; // ta�k� skai�ius
};
//---------------------------------------------------------------------------------
void Skaityti(Mokinys A[], int & n, int & p, int & k);
void Spausdinti(Mokinys A[], int n);
void Atrinkti(Mokinys A[], int n, Mokinys B[], int & m, int p, int k);
int MAX(Mokinys A[], int n, string a);
//---------------------------------------------------------------------------------
int main()
{
   Mokinys A[CMax]; int n; // klas�s mokini� duomenys
   Mokinys B[CMax]; int m; // atrinkt� mokini� duomenys
   int p, k;
   Skaityti(A, n, p, k);
   Atrinkti(A, n, B, m, p, k);
   Spausdinti(B, m);
   return 0;
}
//-----------------------------------------------------------------------
// Pradini� duomen� skaitymas i� failo: A � duomen� masyvas, n � duomen� skai�ius
void Skaityti(Mokinys A[], int & n, int & p, int & k)
{
   ifstream fd (CDfv);
   fd >> n; // perskaitomas klas�s mokini� skai�ius
   for (int i = 0; i < n; i++)
      fd >> A[i].pav >> A[i].ugis >> A[i].kiek;
   fd >> p >> k;
   fd.close();
}
//-----------------------------------------------------------------------
// Mokini� s�ra�as ra�omas � fail�, nurodyt� konstanta CRfv
// A � duomen� masyvas, n � duomen� skai�ius
void Spausdinti(Mokinys A[], int n)
{
   ofstream fr (CRfv);
   if (n < 1) {
     fr << "----------------------------" << endl;
     fr << "#   " << "   [Sąrašo Nera]   " << "    #" << endl;
     fr << "# " << "[Niekas nepsiekė limito]" << " #" << endl;
     fr << "----------------------------" << endl;
   } else {
     fr << "-------------------------------------------" << endl;
     fr << " " << setw(15) << left << "Vardas" << " " << setw(10) << "Ugis" << " " << setw(10) << "Ta�kai" << endl;
     fr << "-------------------------------------------" << endl;
     for (int i = 0; i < n; i++)
     fr << " " << setw(15) << left << A[i].pav << " " << setw(10) << A[i].ugis << " " << setw(10) << A[i].kiek << endl;
     fr << "-------------------------------------------" << endl;
     fr.close();
   }
}
//-----------------------------------------------------------------------
// I� masyvo A(n) atrenkami � masyv� B(m) mokiniai, var�ybose surink� ne ma�iau kaip 15 ta�k�
void Atrinkti(Mokinys A[], int n, Mokinys B[], int & m, int p, int k)
{
   m = 0;
   int maxUgis = MAX(A, n, "ugis")*(100-p)/100;
   int maxKiek = MAX(A, n, "kiek")*(100-k)/100;
   for (int i = 0; i < n; i++)
      if ((A[i].ugis >= maxUgis) || (A[i].kiek >= maxKiek)) {
         B[m] = A[i]; // kopijuojami i-ojo mokinio duomenys i� masyvo A � masyvo B pabaig�
         m++; // masyvo B �ra�� skai�ius padid�jo vienetu
      }
}
//-----------------------------------------------------------------------
int MAX(Mokinys A[], int n, string a)
{
  int max = 0;
  for (int i = 0; i < n; i++) {
    if (a == "ugis") {
      if (A[i].ugis > max) {
        max = A[i].ugis;
      }
    }
    if (a == "kiek") {
      if (A[i].kiek > max) {
        max = A[i].kiek;
      }
    }
  }
  return max;
}
//-----------------------------------------------------------------------
