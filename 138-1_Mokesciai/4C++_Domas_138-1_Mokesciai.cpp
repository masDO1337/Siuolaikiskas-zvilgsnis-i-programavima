#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;
const char CDfv0[] = "Duomenys0.txt";
const char CDfv1[] = "Duomenys1.txt";
const char CRfv[] = "Rezultatai.txt";
const int CMax = 30;
const int CPav = 20;
//-----------------------------------------------------------------------
struct Giventojas {
          string pav;
          int numeris;
          double siluma;
          double elektra;
          double vanduo;
};
//-----------------------------------------------------------------------
void Skaityti(const char fv[], Giventojas A[], int & n);
void Spausdinti(Giventojas A[], int n);
//-----------------------------------------------------------------------
int main()
{
   Giventojas A[CMax]; int n;
   Giventojas B[CMax]; int m;
   Skaityti(CDfv0, A, n);
   Skaityti(CDfv1, B, m);
   for (int i = 0; i < m; i++) {
     for (int j = 0; j < n; j++) {
       if (B[i].pav == A[j].pav && B[i].numeris == A[j].numeris) {
         A[j].siluma += B[i].siluma;
         A[j].elektra += B[i].elektra;
         A[j].vanduo += B[i].vanduo;
       }
     }
   }
   Spausdinti(A, n);
   return 0;
}
//-----------------------------------------------------------------------

void Skaityti(const char fv[], Giventojas A[], int & n)
{
   ifstream fd (fv);
   char eil[CPav+1];
   fd >> n;
   fd.ignore(80, '\n');
   for (int i = 0; i < n; i++) {
      fd.get(eil, CPav);
      A[i].pav = eil;
      fd >> A[i].numeris;
      fd >> A[i].siluma;
      fd >> A[i].elektra;
      fd >> A[i].vanduo;
      fd.ignore(80, '\n');
   }
   fd.close();
}
//-----------------------------------------------------------------------
void Spausdinti(Giventojas A[], int n)
{
   ofstream fr (CRfv);
   fr << setw(20) << left << "Pavarde, Vardas" << setw(10) << "Buto Nr." << setw(10) << "Sildymas" << setw(10) << "Eiektra" << setw(10) << "Vanduo" << endl;
   fr << "--------------------------------------------------------" << endl;
   for (int i = 0; i < n; i++) {
     fr << setw(20) << right << A[i].pav << A[i].numeris << setw(13) << fixed << setprecision(2) << A[i].siluma << setw(10) << A[i].elektra << setw(10) << A[i].vanduo << endl;
   }
   fr << "--------------------------------------------------------" << endl;
   fr << setw(20) << left << "Pavarde, Vardas" << setw(10) << "Buto Nr." << setw(10) << "Sildymas" << setw(10) << "Eiektra" << setw(10) << "Vanduo" << endl;
   fr << "--------------------------------------------------------" << endl;
   for (int i = 0; i < n; i++) {
     if (A[i].siluma < 0 || A[i].elektra < 0 || A[i].vanduo < 0 ) {
       fr << setw(20) << right << A[i].pav << A[i].numeris << setw(13) << fixed << setprecision(2) << A[i].siluma << setw(10) << A[i].elektra << setw(10) << A[i].vanduo << endl;
     }
   }
   fr << "--------------------------------------------------------" << endl;
   fr.close();
}
//-----------------------------------------------------------------------
