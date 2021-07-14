#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;
const char CDfv[] = "U2.txt";
const char CRfv[] = "Rezultatai.txt";
const int CMax = 104;
const int CPav1 = 20;
const int CPav2 = 13;
//-----------------------------------------------------------------------
struct Miestai {
  string pav;
  string apskritis;
  int giventojai;
};
struct Apskritis {
  string pav;
  int minMestoGiventojai = 600000;
  int giventojai;
};
//-----------------------------------------------------------------------
void Skaityti(const char fv[], Miestai A[], int & n);
void Spausdinti(Apskritis A[], int m);
int Yra (Apskritis A[], int n, string pav);
//-----------------------------------------------------------------------
int main()
{
   Miestai A[CMax]; int n;
   Apskritis B[CMax]; int m = 0;
   Skaityti(CDfv, A, n);
   for (int i = 0; i < n; i++) {
     int x = Yra(B, m, A[i].apskritis);
     if (x < 0) {
       B[m].pav = A[i].apskritis;
       B[m].minMestoGiventojai = A[i].giventojai;
       B[m].giventojai = A[i].giventojai;
       m ++;
     } else {
       B[x].giventojai += A[i].giventojai;
       if (B[x].minMestoGiventojai > A[i].giventojai) {
         B[x].minMestoGiventojai = A[i].giventojai;
       }
     }
   }
   for (int i = 0; i < m; i++) {
     Apskritis C;
     if (B[i].minMestoGiventojai > B[i+1].minMestoGiventojai) {
       C = B[i];
       cout << C.pav << '\n';
       for (int j = i+1; j < m; j++) {
         B[j-1] = B[j];
       }
       B[m-1] = C;
     }
   }
   Spausdinti(B, m);
   return 0;
}
//-----------------------------------------------------------------------

void Skaityti(const char fv[], Miestai A[], int & n)
{
   ifstream fd (fv);
   char eil1[CPav1+1];
   char eil2[CPav2+1];
   fd >> n;
   fd.ignore(80, '\n');
   for (int i = 0; i < n; i++) {
      fd.get(eil1, CPav1);
      A[i].pav = eil1;
      fd.get(eil2, CPav2);
      A[i].apskritis = eil2;
      fd >> A[i].giventojai;
      fd.ignore(80, '\n');
   }
   fd.close();
}
//-----------------------------------------------------------------------
void Spausdinti(Apskritis A[], int n)
{
   ofstream fr (CRfv);
   fr << n << endl;
   for (int i = 0; i < n; i++) {
     fr << A[i].pav << " " << A[i].minMestoGiventojai << " " << A[i].giventojai << endl;
   }
   fr.close();
}
//-----------------------------------------------------------------------
int Yra (Apskritis A[], int n, string pav)
{
   for (int i = 0; i < n; i++)
      if (A[i].pav == pav) return i;

   return -1;
}
