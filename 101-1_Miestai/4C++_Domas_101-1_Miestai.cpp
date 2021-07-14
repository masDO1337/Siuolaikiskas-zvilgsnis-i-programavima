#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;
const char CDfv[] = "Duomenys.txt";
const char CRfv[] = "Rezultatai.txt";
const int CMax = 30;
//-----------------------------------------------------------------------
void Skaityti(string A[], int & n);
void Spausdinti(string A[], int n, string komentaras);
void Rikiuoti(string A[], int & n);
//-----------------------------------------------------------------------
int main()
{
   string A[CMax]; int n;
   ofstream fr (CRfv); fr.close();
   Skaityti(A, n);
   Spausdinti(A, n, "Pradiniai duomenys");
   Rikiuoti(A, n);
   Spausdinti(A, n, "Isrinkti miestai");
   return 0;
}
//-----------------------------------------------------------------------
void Skaityti(string A[], int & n)
{
   ifstream fd (CDfv);
   fd >> n;
   fd.ignore(80, '\n');
   for (int i = 0; i < n; i++)
      getline(fd, A[i]);
   fd.close();
}
//-----------------------------------------------------------------------
void Spausdinti(string A[], int n, string komentaras)
{
   ofstream fr (CRfv, ios::app);
   fr << "----------------------------------" << endl;
   fr << komentaras << endl;
   fr << "----------------------------------" << endl;
   for (int i = 0; i < n; i++)
      fr << A[i] << endl;
   fr.close();
}
//-----------------------------------------------------------------------
void Rikiuoti(string A[], int & n)
{
   string eil;
   int m = 0;
   for (int i = 0; i < n; i++) {
     if (A[i].find(" " , 0) <= 100) {
       eil = A[i];
       A[m] = eil;
       m ++;
     }
   }
   n = m;
}
//-----------------------------------------------------------------------
