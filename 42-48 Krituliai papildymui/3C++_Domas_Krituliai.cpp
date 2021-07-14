// Krituliai
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;
const char CDfv[] = "Duomenys61.txt";
const char CRfv[] = "Rezultatai61.txt";
const int CMax    = 100;
//-------------------------------------------------------------------
void Skaityti(int A[], int & n);
void Spausdinti(int A[], int n);
int KrituliuKiekis(int A[], int n);
int DienuSkaicius(int A[], int n);
int KrituliuVidurkis (int A[], int n, bool a);
//-------------------------------------------------------------------
int main()
{
   int Kr[CMax]; int n;
   Skaityti(Kr, n);
   Spausdinti(Kr, n);
   cout << "OK" << '\n';
   return 0;
}
//-------------------------------------------------------------------
// Skaito duomenis i� failo CDfv � masyv� A(n)
void Skaityti(int A[], int & n)
{
   ifstream fd(CDfv); // atidaromas �vesties srautas
   fd >> n; // perskaitomas masyvo reik�mi� kiekis
   for (int i = 0; i < n; i++)
      fd >> A[i]; // perskaitoma i-oji reik�m�
   fd.close(); // u�daromas �vesties srautas
}
//-------------------------------------------------------------------
// Ra�o lentele masyvo A(n) reik�mes � fail� CRfv
void Spausdinti(int A[], int n)
{
   ofstream fr(CRfv); // atidaromas i�vesties srautas
   fr << " Krituliai (lietus) " << endl;
   fr << "---------------------------" << endl;
   fr << "Diena Krituli� kiekis (mm)" << endl;
   fr << "---------------------------" << endl;
   for (int i = 0; i < n; i++)
      fr << setw(4) << i+1 << "         " << setw(3) << A[i] << endl;
   fr << "---------------------------" << endl;
   fr << "I� viso i�krito krituli� (mm): " << KrituliuKiekis(A, n) << endl;
   fr << "Nelijo (dienas): " << DienuSkaicius(A, n) << endl;
   fr << "Lijo (dienas): " << n - DienuSkaicius(A, n) << endl;
   fr << "Vidutini�kai kiekvien� lieting� dien� i�krito krituli� (mm): " << KrituliuVidurkis(A, n, false) << endl;
   fr << "Vidutini�kai visu stebetu dienu i�krito krituli� (mm): " << KrituliuVidurkis(A, n, true ) << endl;
   fr.close(); // u�daromas i�vesties srautas
}
//-------------------------------------------------------------------
// Apskai�iuoja ir gr��ina masyvo A(n)reik�mi� sum�
int KrituliuKiekis(int A[], int n)
{
   int suma = 0;
   for (int i = 0; i < n; i++)
      suma = suma + A[i];
   return suma;
}
//-------------------------------------------------------------------
// Apskai�iuoja, kiek masyve A(n) yra nulini� reik�mi�, ir jas gr��ina
int DienuSkaicius(int A[], int n)
{
   int kiek = 0;
   for (int i = 0; i < n; i++)
      if (A[i] == 0)
         kiek = kiek + 1;
   return kiek;
}
//-------------------------------------------------------------------
// Apskai�iuoja masyvo A(n) teigiam�j� reik�mi� vidurk� ir j� gr��ina
// Jeigu masyve teigiam�j� reik�mi� nebuvo, gr��ina 0 (nul�)
int KrituliuVidurkis(int A[], int n, bool a)
{
   int suma = 0;
   int kiek = 0;
   for (int i = 0; i < n; i++)
      if (!a) {
        if (A[i] > 0) {
          suma = suma + A[i];
          kiek = kiek + 1;
        }
      } else {
        suma = suma + A[i];
        kiek = kiek + 1;
      }
   if (kiek > 0)
      return suma / kiek;
   return 0;
}
