// Krep�ininkai
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;
const char CDfv[] = "Duomenys14.txt";
const char CRfv[] = "Rezultatai14.txt";
const int CMax = 30;
//-----------------------------------------------------------------------
struct Mokinys {
         string pav; // mokinio vardas
         int    kiek; // ta�k� skai�ius
};
//---------------------------------------------------------------------------------
void Skaityti(Mokinys A[], int & n);
void Spausdinti(Mokinys A[], int n, string eil);
void Atrinkti(Mokinys A[], int n, Mokinys B[], int & m);
void AtrinktiTaikliausias(Mokinys A[], int n, Mokinys B[], int & m);
int Suma(Mokinys A[], int n);
//---------------------------------------------------------------------------------
int main()
{
   Mokinys A[CMax]; int n; // klas�s mokini� duomenys
   Mokinys B[CMax]; int m; // atrinkt� mokini� duomenys
   Skaityti(A, n);
   Atrinkti(A, n, B, m);
   string eil = "Mokini�, surinkusi� ne ma�iau kaip 15 ta�k�, s�ra�as";
   Spausdinti(B, m, eil);
   ofstream fr (CRfv, ios::app); // srautas atveriamas papildyti
   fr << "Klas�s mokinys vidutini�kai surinko ta�k�: " << Suma(A,n) / n << endl;
   fr << "Atrinkti mokiniai vidutini�kai surinko ta�k�: " << Suma(B, m) / m << endl;
   AtrinktiTaikliausias(A, n, B, m);
   fr << "Taikliausias mokinys: " << B[m].pav << " surinko taškų: " << B[m].kiek << endl;
   fr.close();
   return 0;
}
//-----------------------------------------------------------------------
// Pradini� duomen� skaitymas i� failo: A � duomen� masyvas, n � duomen� skai�ius
void Skaityti(Mokinys A[], int & n)
{
   ifstream fd (CDfv);
   fd >> n; // perskaitomas klas�s mokini� skai�ius
   for (int i = 0; i < n; i++)
      fd >> A[i].pav >> A[i].kiek;
   fd.close();
}
//-----------------------------------------------------------------------
// Mokini� s�ra�as ra�omas � fail�, nurodyt� konstanta CRfv
// A � duomen� masyvas, n � duomen� skai�ius
void Spausdinti(Mokinys A[], int n, string eil)
{
   ofstream fr (CRfv);
   if (n < 1) {
     fr << eil << endl;
     fr << "----------------------------" << endl;
     fr << "#   " << "   [Sąrašo Nera]   " << "    #" << endl;
     fr << "# " << "[Niekas nepsiekė limito]" << " #" << endl;
     fr << "----------------------------" << endl;
   } else {
     fr << eil << endl;
     fr << "----------------------------" << endl;
     fr << " Vardas Ta�kai " << endl;
     fr << "----------------------------" << endl;
     for (int i = 0; i < n; i++)
     fr << " " << setw(15) << left << A[i].pav << " " << setw(10) << A[i].kiek << endl;
     fr << "----------------------------" << endl;
     fr.close();
   }
}
//-----------------------------------------------------------------------
// I� masyvo A(n) atrenkami � masyv� B(m) mokiniai, var�ybose surink� ne ma�iau kaip 15 ta�k�
void Atrinkti(Mokinys A[], int n, Mokinys B[], int & m)
{
   m = 0;
   for (int i = 0; i < n; i++)
      if (A[i].kiek >= 15) {
         B[m] = A[i]; // kopijuojami i-ojo mokinio duomenys i� masyvo A � masyvo B pabaig�
         m++; // masyvo B �ra�� skai�ius padid�jo vienetu
      }
}
//-----------------------------------------------------------------------
void AtrinktiTaikliausias(Mokinys A[], int n, Mokinys B[], int & m)
{
  m = 0;
  int id = 0;
  for (int i = 0; i < n; i++) {
    if (A[i].kiek > A[id].kiek) {
      id = i;
      B[m] = A[i];
    }
  }

}
//-----------------------------------------------------------------------
// Apskai�iuoja ir gr��ina masyve A(n) esan�i� mokini� surinkt� ta�k� sum�
int Suma(Mokinys A[], int n)
{
   int s = 0;
   for (int i = 0; i < n; i++)
      s += A[i].kiek;
   return s;
}
//-----------------------------------------------------------------------
