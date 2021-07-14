// Sachmatai
#include <fstream>
#include <iomanip>
using namespace std;
const char CDfv[] = "Duomenys90-2.txt";
const char CRfv[] = "Rezultatai90-3Papildomas.txt";
//-----------------------------------------------------------------------
void Duomenys(char A[], int C[]);
int Kiek(char sim);
void Spausdinti(ofstream & fr, char A[], int C[]);
int Komplektai(int B[], int C[]);
void Liko(int k, int B[], int C[]);
void Truksta(int B[], int C[]);
//-----------------------------------------------------------------------
int main()
{
   char A[6] = {'p', 'b', 'z', 'r', 'v', 'k'};
   int B[6] = {16, 4, 4, 4, 2, 2};
   int C[6];
   Duomenys(A, C);
   ofstream fr(CRfv);
   Spausdinti(fr, A, C);
   int k = Komplektai(B, C);
   fr << k << endl;
   Liko(k, B, C);
   Spausdinti(fr, A, C);
   fr << "Reikia pagaminti:" << endl;
   Truksta(B, C);
   Spausdinti(fr, A, C);
   fr.close();
   return 0;
}
//-----------------------------------------------------------------------
// Sachmatu figuru kiekiai surasomi i masyva C(6). Masyve A(6) yra laikomi figuru pavadinimai (raides)
void Duomenys(char A[], int C[])
{
   for (int i = 0; i < 6; i++)
      C[i] = Kiek(A[i]);
}
//-----------------------------------------------------------------------
// Apskaiciuoja, kiek kartu nurodytame tekste pasitaiko simbolis sim
int Kiek(char sim)
{
   char s;
   int n, k = 0;
   ifstream fd(CDfv);
   fd >> n;
   for (int i = 0; i < n; i++) {
      fd >> s; // skaitant tarpo ir eilutes pabaigos simboliai praleidziami
      if (s == sim) k++;
   }
   fd.close();
   return k;
}
//-----------------------------------------------------------------------
// Iraso i faila, susieta su srautu fr, sachmatu figuru pavadinimus ir ju kiekius
// A � figuru pavadinimai (raides), C � figuru kiekiai
void Spausdinti(ofstream & fr, char A[], int C[])
{
   for (int i = 0; i < 6; i++)
      fr << A[i] << ' ' << C[i] << endl;
}
//-----------------------------------------------------------------------
// Apskaiciuoja, kiek zaidimo komplektu galima sudaryti is turimu sachmatu figuru
// B � vieno komplekto figuru kiekiai, C � turimi figuru kiekiai
int Komplektai(int B[], int C[])
{
   int i, L = 9999;
   for (int i = 0; i < 6; i++)
      if (C[i] / B[i] < L) L = C[i] / B[i];
   return L;
}
//-----------------------------------------------------------------------
// Apskaiciuoja, kiek liko nepanaudot� figuru
// k � komplektu skaicius, B � figuru kiekiai, reikalingi vienam zaidimo komplektui,
// C � turimi figuru kiekiai
void Liko(int k, int B[], int C[])
{
   for (int i = 0; i < 6; i++)
      C[i] -= B[i] * k;
}
//-----------------------------------------------------------------------
void Truksta(int B[], int C[])
{
  int A[6] = {0, 0, 0, 0, 0, 0};
  int a = 0;
  for (int i = 0; i < 6; i++) {
    while (0 < C[i] - (A[i] * B[i])) {
      A[i] ++;
    }
    if (a < A[i]) {
      a = A[i];
    }
  }
  for (int i = 0; i < 6; i++) {
    C[i] = a * B[i] - C[i];
    //C[i] = A[i];
  }
}
