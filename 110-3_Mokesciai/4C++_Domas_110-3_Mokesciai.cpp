#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;
const char CDfv[] = "Duomenys.txt";
const char CRfv[] = "Rezultatai.txt";
const int CMax = 30;
//-----------------------------------------------------------------------
struct Mokejimas {
         string pav;
         double siluma;
         double telefona;
         double vandeni;
         double moketi;
};
//---------------------------------------------------------------------------------
void Skaityti(Mokejimas A[], int & n);
void Spausdinti(Mokejimas A[], int n);
void Atrinkti(Mokejimas A[], int n);
double MAX(Mokejimas A[], double n, string a);
//---------------------------------------------------------------------------------
int main()
{
   Mokejimas A[CMax]; int n;
   Skaityti(A, n);
   Atrinkti(A, n);

   ofstream fr (CRfv);
   fr << "Už šilumą turi būti sumokėta: " << left << MAX(A, n, "siluma"); fr << endl;
   fr << "Už telefoną turi būti sumokėta: " << left << MAX(A, n, "telefona"); fr << endl;
   fr << "Už vandenį turi būti sumokėta: " << left << MAX(A, n, "vandeni"); fr << endl;
   fr.close();

   Spausdinti(A, n);
   return 0;
}
//-----------------------------------------------------------------------
// Pradini� duomen� skaitymas i� failo: A � duomen� masyvas, n � duomen� skai�ius
void Skaityti(Mokejimas A[], int & n)
{
   ifstream fd (CDfv);
   fd >> n;
   for (int i = 0; i < n; i++) {
     fd >> A[i].pav >> A[i].siluma >> A[i].telefona >> A[i].vandeni;
     A[i].moketi = 0;
   }
   fd.close();
}
//-----------------------------------------------------------------------
void Spausdinti(Mokejimas A[], int n)
{
   ofstream fr (CRfv, ios::app);

   if (n < 1) {
     fr << "----------------------------" << endl;
     fr << "#   " << "   [Sąrašo Nera]   " << "    #" << endl;
     fr << "# " << "[Niekas nepsiekė limito]" << " #" << endl;
     fr << "----------------------------" << endl;
   } else {
     fr << "-------------------------------------------" << endl;
     fr << " " << setw(15) << left << "Vardas" << " " << setw(10) << "Turi moketi" << endl;
     fr << "-------------------------------------------" << endl;
     for (int i = 0; i < n; i++)
     if (A[i].moketi > 0)
     fr << " " << setw(15) << left << A[i].pav << " " << setw(10) << A[i].moketi << endl;
     fr << "-------------------------------------------" << endl;
     fr.close();
   }
}
//-----------------------------------------------------------------------
void Atrinkti(Mokejimas A[], int n)
{
   for (int i = 0; i < n; i++) {
     if (A[i].siluma > 0) {
       A[i].moketi += A[i].siluma;
     }
     if (A[i].telefona > 0) {
       A[i].moketi += A[i].telefona;
     }
     if (A[i].vandeni > 0) {
       A[i].moketi += A[i].vandeni;
     }
   }
}
//-----------------------------------------------------------------------
double MAX(Mokejimas A[], double n, string a)
{
  double max = 0;
  for (int i = 0; i < n; i++) {
    if (a == "siluma") {
      if (A[i].siluma > 0) {
        max += A[i].siluma;
      }
    }
    if (a == "telefona") {
      if (A[i].telefona > 0) {
        max += A[i].telefona;
      }
    }
    if (a == "vandeni") {
      if (A[i].vandeni > 0) {
        max += A[i].vandeni;
      }
    }
  }
  return max;
}
//-----------------------------------------------------------------------
