// B�gikai
#include <fstream>
#include <iomanip>
#include<iostream>
using namespace std;
const char CDfva[] = "Duomenys1.txt";
const char CDfvb[] = "Duomenys2.txt";
const char CRfv[] = "Rezultatai.txt";
const int CMax = 30;
const int CPav = 20;
//-----------------------------------------------------------------------
struct Sportininkas {
          string pav; // vardas ir pavard�
          int laikas; // laikas sekund�mis
};
//-----------------------------------------------------------------------
void Skaityti(const char fv[], Sportininkas A[], int & n);
void Spausdinti(Sportininkas A[], int n);
void Rikiuoti(Sportininkas A[], int n);
void Atrinkti(Sportininkas A[], int n, Sportininkas B[], int & m);
//-----------------------------------------------------------------------
int main()
{
   Sportininkas A[CMax]; int n; // pradini� duomen� masyvas
   Sportininkas B[CMax]; int m = 0; // s�ra�as i� prad�i� turi b�ti tu��ias (m = 0)
   Skaityti(CDfva, A, n);
   Rikiuoti(A, n);
   Atrinkti(A, n, B, m);
   Skaityti(CDfvb, A, n);
   Rikiuoti(A, n);
   Atrinkti(A, n, B, m);
   Rikiuoti (B, m);
   Spausdinti(B, m);
   return 0;
}
//-----------------------------------------------------------------------
// Skaitomi pradiniai duomenys i� failo � masyv� A(n)
void Skaityti(const char fv[], Sportininkas A[], int & n)
{
   ifstream fd (fv);
   int min, sek;
   char eil[CPav+1];
   fd >> n; // b�gik� skai�ius
   fd.ignore(80, '\n'); // pereinama � kit� eilut�
   for (int i = 0; i < n; i++) {
      fd.get(eil, CPav); // b�giko vardas ir pavard�
      A[i].pav = eil;
      fd >> min >> sek; // b�giko laikas minut�mis ir sekund�mis
      fd.ignore(80, '\n'); // pereinama � kit� eilut�
      A[i].laikas = min * 60 + sek; // apskai�iuojamas laikas sekund�mis
   }
   fd.close();
}
//-----------------------------------------------------------------------
// Masyvo A(n) duomenys ra�omi � fail�, nurodyt� konstanta CRfv
void Spausdinti(Sportininkas A[], int n)
{
   ofstream fr (CRfv);
   fr << "B�gik� finalinio b�gimo s�ra�as" << endl;
   fr << "--------------------------------" << endl;
   fr << "Vardas ir        Parodytas     B�gimo" << endl;
   fr << "pavard�          laikas        takelis" << endl;
   fr << "--------------------------------" << endl;
   for (int i = 0; i < n; i++)
      fr << setw(20) << left << A[i].pav << " " << A[i].laikas / 60 << " : " << A[i].laikas % 60 << "    " << n - i << endl;
   fr << "--------------------------------" << endl;
   fr.close();
}
//-----------------------------------------------------------------------
// Rikiuojami masyvo A(n) duomenys pagal laik� did�jan�iai
void Rikiuoti(Sportininkas A[], int n)
{
   for (int i = 0; i < n; i++)
      for (int j = i + 1; j < n; j++)
         if (A[j].laikas < A[i].laikas) {
            Sportininkas sp = A[i];
            A[i] = A[j];
            A[j] = sp;
         }
}
//-------------------------------------------------------------------
// I� masyvo A(n) pus� duomen� kopijuojama � masyv� B(m)
void Atrinkti(Sportininkas A[], int n, Sportininkas B[], int & m)
{
   for (int i = 0; i < n; i++ ) {
      B[m] = A[i];
      m++;
   }
}
