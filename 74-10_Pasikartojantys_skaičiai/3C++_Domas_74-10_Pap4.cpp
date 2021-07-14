// Pasikartojantys skai�iai
#include <fstream>
#include <iomanip>
#include <iostream>
#include <cmath>
using namespace std;
const char CDfv[] = "DuomenysPS.txt";
const char CRfv[] = "RezultatasPS4.txt";
const int CMax    = 1000;
//-------------------------------------------------------------------
void Skaityti(const char fv[], int A[], int & n);
void Spausdinti(const char fv[], int A[], int n);
int IeskotiSkaiciaus(int A[], int n, int sk);
void IterptiSkaiciu(int A[], int & n, int sk, int ind);
//-------------------------------------------------------------------
int main()
{
   int S[CMax]; int n; // skaiciu sekos masyvas
   int m = 11; // skaicius, kuriuo reikia papildyti skaiciu seka
   int mind; // skaiciaus m paieskos indeksas
   ofstream fr;
   Skaityti(CDfv, S, n);
   fr.open(CRfv); fr.close();
   Spausdinti(CRfv, S, n);
   fr.open(CRfv, ios:: app);
   mind = IeskotiSkaiciaus(S, n, m);
   if (mind >= 0) { // skaicius m sekoje yra
      fr << "Skaiciaus " << m << " indeksas masyve " << mind << endl;
      IterptiSkaiciu(S, n, m, mind);
   }
   else { // skaiciaus m sekoje nera
      fr << "Skaicius " << m << " masyve nerastas" << endl;
      IterptiSkaiciu(S, n, m, n);
   }
   Spausdinti(CRfv, S, n);
   fr.close();
   cout << "Done" << '\n';
   return 0;
}


//-------------------------------------------------------------------
// Skaito duomenis is failo fv i masyva A(n)
void Skaityti(const char fv[], int A[], int & n)
{
   ifstream fd(fv); // atidaromas ivesties srautas
   fd >> n; // perskaitomas masyvo reiksmiu kiekis
   for (int i = 0; i < n; i++)
      fd >> A[i];
   fd.close(); // uzdaromas ivesties srautas
}
//-------------------------------------------------------------------
// Raso masyvo A(n) reiksmes i faila fv
// Vienoje eiluteje vienodi skaiciai
void Spausdinti(const char fv[], int A[], int n)
{
   ofstream fr(fv, ios::app); // atidaromas isvesties srautas papildyti
   fr << " Skaiciu seka " << endl;
   fr << "--------------" << endl;
   for (int i = 0; i < n - 1; i++) {
      while (A[i] == A[i+1]) { // rasomi eiluteje vienodi skaiciai
         fr << setw(4) << A[i];
         i++;
      }
      fr << setw(4) << A[i] << endl;
   }
   fr << "--------------" << endl;
   fr.close(); // uzdaromas isvesties srautas
}
//-------------------------------------------------------------------
// Masyve A(n) iesko reiksmes, lygios skaiciui sk
// Jeigu reiksme suranda, grazina masyvo elemento indeksa
// Jeigu tokios reiksmes masyve neranda, grazina -1
int IeskotiSkaiciaus(int A[], int n, int sk)
{
   for (int i = 0; i < n; i++)
      if (A[i] == sk)
         return i;
   return -1;
}
//-------------------------------------------------------------------
// iterpia skaici�u sk i masyva A(n) pries elementa, kurio indeksas yra ind
void IterptiSkaiciu(int A[], int & n, int sk, int ind)
{
   for (int i = ind + 1; i <= n; i++)
      A[i-1] = A[i];
   A[ind] = sk;
   n--;
}
//-------------------------------------------------------------------
