// G�li� puok�t�
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;
const char CDfv[] = "Duomenys.txt";
const char CRfv[] = "Rezultatai.txt";
const int CMax    = 50;
//-------------------------------------------------------------------
void Skaityti(const char fv[], int A[], int & n);
void Spausdinti(const char fv[], int A[], int n);
int IlgiausiaiArMinZydi(int A[], int n, bool a);
void SpausdintiIlgZydi(const char fv[], int A[], int n, int sk, bool a);
//-------------------------------------------------------------------
int main()
{
   int P[CMax]; int n; // geliu zydejimo trukmiu masyvas
   Skaityti(CDfv, P, n);
   Spausdinti(CRfv, P, n);
   cout << "Done!" << '\n';
   return 0;
}

//-------------------------------------------------------------------
// Skaito duomenis is failo fv i masyva A(n)
void Skaityti(const char fv[], int A[], int & n)
{
   ifstream fd(fv); // atidaromas ivesties srautas
   fd >> n; // perskaitomas masyvo reiksmiu kiekis
   for (int i = 0; i < n; i++)
   fd >> A[i]; // perskaitoma i-oji reiksme
   fd.close(); // uzdaromas ivesties srautas
}
//-------------------------------------------------------------------
// Suraso masyvo A(n) reiksmes i faila fv lentele
void Spausdinti(const char fv[], int A[], int n)
{
   ofstream fr(fv); // atidaromas isvesties srautas
   fr << " Puokstes geles " << endl;
   fr << "------------------" << endl;
   fr << " G. Nr. �. laikas" << endl;
   fr << "------------------" << endl;
   for (int i = 0; i < n; i++)
      fr << setw(4) << i+1 << "        " << setw(2) << A[i] << endl;
   fr << "------------------" << endl;
   fr << "Visos geles nuvys po " << IlgiausiaiArMinZydi(A, n, true) << " d." << endl;
   fr << "Pirma gele nuvys po " << IlgiausiaiArMinZydi(A, n, false) << " d." << endl;
   fr.close(); // uzdaromas isvesties srautas
   SpausdintiIlgZydi(fv, A, n, IlgiausiaiArMinZydi(A, n, true), false);
   SpausdintiIlgZydi(fv, A, n, IlgiausiaiArMinZydi(A, n, false), true);
}
//-------------------------------------------------------------------
// Randa ir grazina masyvo A(n) didziausia reiksme
int IlgiausiaiArMinZydi(int A[], int n, bool a)
{
   int max = A[0];
   for (int i = 1; i < n; i++)
    if (a) {
        if (A[i] > max) max = A[i];
    } else {
        if (A[i] < max) max = A[i];
    }
   return max;
}
//-------------------------------------------------------------------
// Suraso masyvo A(n) elementu reiksmiu, lygiu skaiciui sk, indeksus i faila fv
void SpausdintiIlgZydi(const char fv[], int A[], int n, int sk, bool a)
{
   ofstream fr(fv, ios::app); // atidaro isvesties srauta papildyti
   if (a) {
     fr << "Geliu, kurios zydi trumpiausiai, rusiu numeriai:" << endl;
   } else {
     fr << "Geliu, kurias reiktu deti i puokste, numeriai:" << endl;
   }
   for (int i = 0; i < n; i++)
      if (A[i] == sk)
         fr << " " << i+1;
   fr << endl;
   fr.close(); // uzdaro isvesties srauta
}
