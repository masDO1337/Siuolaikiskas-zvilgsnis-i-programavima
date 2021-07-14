#include <fstream>
#include <iomanip>
#include <cctype>
#include <iostream>
using namespace std;
const char CDfv[] = "Duomenys.txt";
const char CRfv[] = "Rezultatai.txt";
const int CMax = 30;
//-----------------------------------------------------------------------
void Skaityti(char A[], int B[], int & n);
void Spausdinti(char A[], int B[], int n);
//-----------------------------------------------------------------------
int main()
{
   char A[CMax];
   int B[CMax];
   int n;
   Skaityti(A, B, n);
   Spausdinti(A, B, n);
   return 0;
}
//-----------------------------------------------------------------------
void Skaityti(char A[], int B[], int & n)
{
  char ss;
  n = 0;
  for (ss = 'a'; ss <= 'z'; ss++) {
    A[n] = ss; B[n] = 0; n++;
  }

  ifstream fd(CDfv);
  while (!fd.eof()) {
     fd.get(ss);
     for (int i = 0; i <= n; i++) {
       if (!fd.eof() && (tolower(ss) == A[i])) B[i]++;
     }
  }
  fd.close();
}
//-----------------------------------------------------------------------
void Spausdinti(char A[], int B[], int n)
{
   ofstream fr (CRfv);
   int id = 0;
   for (int i = 0; i < n; i++) { // rasomi simboliai po penkis eiluteje
     char ss = putchar(toupper(A[i]));
     fr << ss << A[i] << " " << setw(2) << B[i] << " ";
     if ((i + 1) % 5 == 0) fr << endl;
     if (B[i] > id) id = i;
   }
   fr << endl;
   char ss = putchar(toupper(A[id]));
   fr << "Dažniausiai kartojasi raidė "<< ss << A[id] << ".";
   fr.close();
}
