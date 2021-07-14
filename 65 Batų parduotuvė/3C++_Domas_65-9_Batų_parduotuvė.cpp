// Batu parduotuve
#include <fstream>
#include <iomanip>
#include <iostream>
#include <cmath>
using namespace std;
const char CDfv[] = "Duomenys.txt";
const char CRfv[] = "Rezultatai.txt";
const int CMax    = 100;
//-------------------------------------------------------------------
void Skaityti(const char fv[], char A[], int B[], int & n);
void Spausdinti(const char fv[], char A[], int B[], int n);
int IeskotiBatu(char A[], int B[], int n, char tp, int dd);
void SalintiBatus(char A[], int B[], int & n, int ind);
//-------------------------------------------------------------------
int main()
{
   char T[CMax]; // batu tipai (m � moteriski, v � vyriski)
   int D[CMax]; // batu dydziai
   int n; // batu skaicius
   int bind;
   ofstream fr;
   Skaityti(CDfv, T, D, n);
   fr.open(CRfv);
   fr.close();
   Spausdinti(CRfv, T, D, n);
   fr.open(CRfv, ios::app); // atidaro isvesties srauta papildyti
   bind = IeskotiBatu(T, D, n, 'v', 43);
   if (bind >= 0) { // batai surasti
      fr << "Mykolo 43-io dydzio batu indeksas masyve " << bind << endl;
      SalintiBatus(T, D, n, bind);
   }
   else // bat� nerasta
      fr << "Parduotuveje Mykolo 43-io dydzio batu nebuvo" << endl;
   bind = IeskotiBatu(T, D, n, 'm', 38);
   if (bind >= 0) { // batai surasti
      fr << "Marytes 38-o dydzio batu indeksas masyve " << bind << endl;
      SalintiBatus(T, D, n, bind);
   }
   else // bat� nerasta
      fr << "Parduotuveje Marytes 38-o dydzio batu nebuvo" << endl;
   Spausdinti(CRfv, T, D, n);
   fr.close(); // uzdaro isvesties srauta
   cout << "Done!" << '\n';
   return 0;
}

//-------------------------------------------------------------------
// Skaito duomenis is failo fv i masyvus A(n) ir B(n)
void Skaityti(const char fv[], char A[], int B[], int & n)
{
   ifstream fd(fv); // atidaromas ivesties srautas
   fd >> n; // perskaitomas masyv� reiksmiu kiekis
   for (int i = 0; i < n; i++) {
     fd >> A[i] >> B[i];
   }
   fd.close(); // uzdaromas ivesties srautas
}
//-------------------------------------------------------------------
// Raso masyva A(n) ir B(n) reiksmes i faila fv lentele
void Spausdinti(const char fv[], char A[], int B[], int n)
{
   ofstream fr(fv, ios::app); // atidaro isvesties srauta papildyti
   fr << " Batu sarasas " << endl;
   fr << "--------------" << endl;
   fr << " Tipas Dydis " << endl;
   fr << "--------------" << endl;
   for (int i = 0; i < n; i++)
      fr << setw(4) << A[i] << "     " << setw(2) << B[i] << endl;
   fr << "--------------" << endl;
   fr.close(); // uzdaro isvesties srauta
}
//-------------------------------------------------------------------
// Masyvuose A(n) ir B(n) ie�ko reiksmiu, atitinkamai lygiu tp (tipas) ir dd (dydis);
// jeigu reiksmes suranda, grazina masyvu reiksmiu elementu indeksa,
// jeigu tokiu reiksmiu masyvuose nera, grazina -1
int IeskotiBatu(char A[], int B[], int n, char tp, int dd)
{
   int ind = -1;
   for (int i = 0; i < n; i++) {
     if ((A[i] == tp) && (B[i] == dd)) {
       ind = i;
     }
     if (ind >= 0) {
       return ind;
     }
   }
   return ind;
}
//-------------------------------------------------------------------
// Pasalina is masyvu A(n) ir B(n) elementa, kuriu indeksas yra ind, reiksmes
void SalintiBatus(char A[], int B[], int & n, int ind)
{
   for (int i = ind; i < n-1; i++) {
      A[i] = A[i+1];
      B[i] = B[i+1];
   }
   n--;
}
//-------------------------------------------------------------------
