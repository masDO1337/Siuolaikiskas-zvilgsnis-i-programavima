#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;
const char CDfv[] = "U1.txt";
const char CRfv[] = "Rezultatai.txt";
const int CMax = 10;
//-----------------------------------------------------------------------
struct Imones {
  int balsai[CMax];
  int taskai = 0;
  int suma = 0;
  int direktoriaus_taskai;
};
//-----------------------------------------------------------------------
void Skaityti(const char fv[], Imones A[], int & n);
void Spausdinti(Imones A[], int n);
void Taskai(Imones A[], int n);
//-----------------------------------------------------------------------
int main()
{
   Imones A[CMax]; int n;
   Skaityti(CDfv, A, n);
   Taskai(A, n);
   Spausdinti(A, n);
   return 0;
}
//-----------------------------------------------------------------------

void Skaityti(const char fv[], Imones A[], int & n)
{
   ifstream fd (fv);
   fd >> n;
   fd.ignore(80, '\n');
   for (int i = 0; i < n; i++) {
     for (int j = 0; j < 3; j++) {
       fd >> A[j].balsai[i];
       //cout << A[j].balsai[i] << '\n';
       A[j].suma += A[j].balsai[i];
     }
     fd.ignore(80, '\n');
   }
   for (int i = 0; i < 3; i++) {
     fd >> A[i].direktoriaus_taskai;
   }
   fd.close();
}
//-----------------------------------------------------------------------
void Spausdinti(Imones A[], int n)
{
   ofstream fr (CRfv);
   int suma = 0;
   int id = 0;
   for (int i = 0; i < 3; i++) {
     fr << A[i].suma << " ";
   }
   fr << endl;
   for (int i = 0; i < 3; i++) {
     fr << A[i].taskai << " ";
     if (suma < A[i].suma + A[i].taskai + A[i].direktoriaus_taskai) {
       suma = A[i].suma + A[i].taskai + A[i].direktoriaus_taskai;
       id = i;
     }
   }
   fr << endl << id + 1;
   fr.close();
}
//-----------------------------------------------------------------------
void Taskai(Imones A[], int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      if (j == 0) {
        if (A[j].balsai[i] > A[j+1].balsai[i] && A[j].balsai[i] > A[j+2].balsai[i]) {
          A[j].taskai += 4;
        } else if (A[j].balsai[i] == A[j+1].balsai[i] || A[j].balsai[i] == A[j+2].balsai[i]) {
          A[j].taskai += 1;
        }
      }
      if (j > 0 && j < 2) {
        if (A[j].balsai[i] > A[j-1].balsai[i] && A[j].balsai[i] > A[j+1].balsai[i]) {
          A[j].taskai += 4;
        } else if (A[j].balsai[i] == A[j-1].balsai[i] || A[j].balsai[i] == A[j+1].balsai[i]) {
          A[j].taskai += 2;
        }
      }
      if (j == 2) {
        if (A[j].balsai[i] > A[j-1].balsai[i] && A[j].balsai[i] > A[j-2].balsai[i]) {
          A[j].taskai += 4;
        } else if (A[j].balsai[i] == A[j-1].balsai[i] || A[j].balsai[i] == A[j-2].balsai[i]) {
          A[j].taskai += 1;
        }
      }
    }
  }
}
