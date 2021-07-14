// Lankytin� viet� s�ra�as
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
void Rikiuoti(string A[], int n);
void RikiuotiPagalIlgi(string A[], int n);
//-----------------------------------------------------------------------
int main()
{
   string A[CMax]; int n;
   ofstream fr (CRfv); fr << 0 << endl; fr.close();
   Skaityti(A, n);
   Spausdinti(A, n, "Pradiniai duomenys");
   Rikiuoti(A, n);
   Spausdinti(A, n, "Surikiuoti duomenys");
   RikiuotiPagalIlgi(A, n);
   Spausdinti(A, n, "Surikiuoti pagal ilgi duomenys");
   return 0;
}
//-----------------------------------------------------------------------
// Simboli� eilut�s skaitomos i� konstanta CDfv nurodyto failo � masyv� A(n)
void Skaityti(string A[], int & n)
{
   ifstream fd (CDfv);
   fd >> n; // perskaitomas eilu�i� skai�ius
   fd.ignore(80, '\n'); // faile pereinama � kitos eilut�s prad�i�
   for (int i = 0; i < n; i++)
      getline(fd, A[i]); // perskaitomi visi simboliai iki failo eilut�s pabaigos ir
// pereinama � kitos eilut�s prad�i�
   fd.close();
}
//-----------------------------------------------------------------------
// Masyve A(n) laikomos eilut�s ra�omos � fail�, nurodyt� konstanta CRfv
// komentaras � i�vedam� duomen� paai�kinimas
void Spausdinti(string A[], int n, string komentaras)
{
   ofstream fr (CRfv, ios::app); // srautas paruo�iamas papildyti
   fr << "----------------------------------" << endl;
   fr << komentaras << endl;
   fr << "----------------------------------" << endl;
   for (int i = 0; i < n; i++)
      fr << A[i] << endl;
   fr.close();
}
//-----------------------------------------------------------------------
// Ab�c�li�kai rikiuoja masyve A(n) laikomas simboli� eilutes
void Rikiuoti(string A[], int n)
{
   string eil;
   for (int i = 0; i < n; i++)
      for (int j = i + 1; j < n; j++)
// Dvi simboli� eilutes palygina ir, jeigu reikia, sukei�ia vietomis
         if (A[j] < A[i]) {
            eil = A[j];
            A[j] = A[i];
            A[i] = eil;
         }
}
//-----------------------------------------------------------------------
void RikiuotiPagalIlgi(string A[], int n)
{
   string eil;
   for (int i = 0; i < n; i++)
      for (int j = i + 1; j < n; j++)
// Dvi simboli� eilutes palygina ir, jeigu reikia, sukei�ia vietomis
         if (A[j].length() > A[i].length()) {
            eil = A[j];
            A[j] = A[i];
            A[i] = eil;
         }
}
//-----------------------------------------------------------------------
