#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;
const char CDfv[] = "U2.txt";
const char CRfv[] = "Rezultatai.txt";
const int CMax = 10;
const int KMax = 31;
//-----------------------------------------------------------------------
struct Map {
  int x0;
  int y0;
  int x1;
  int y1;
};
struct Komandos {
  int komandos[KMax];
  int komandosIlgis;
  int kiek = 0;
  string res = "sekos pabaiga";
};
//-----------------------------------------------------------------------
void Skaityti(const char fv[], Komandos A[], Map & B, int & n);
void Spausdinti(Komandos A[], int n);
void Eina(Komandos A[], Map B, int n);
//-----------------------------------------------------------------------
int main()
{
   Komandos A[CMax]; int n;
   Map B;
   Skaityti(CDfv, A, B, n);
   Eina(A, B, n);
   Spausdinti(A, n);
   return 0;
}
//-----------------------------------------------------------------------

void Skaityti(const char fv[], Komandos A[], Map & B, int & n)
{
   ifstream fd (fv);
   fd >> B.x0 >> B.y0;
   fd.ignore(80, '\n');
   fd >> B.x1 >> B.y1;
   fd.ignore(80, '\n');
   fd >> n;
   fd.ignore(80, '\n');
   for (int i = 0; i < n; i++) {
     fd >> A[i].komandosIlgis;
     for (int j = 0; j < A[i].komandosIlgis; j++) {
       fd >> A[i].komandos[j];
     }
     fd.ignore(80, '\n');
   }
   fd.close();
}
//-----------------------------------------------------------------------
void Spausdinti(Komandos A[], int n)
{
   ofstream fr (CRfv);
   for (int i = 0; i < n; i++) {
     fr << A[i].res << " ";
     for (int j = 0; j < A[i].kiek; j++) {
       fr << A[i].komandos[j] << " ";
     }
     fr << A[i].kiek << endl;
   }
   fr.close();
}
//-----------------------------------------------------------------------
void Eina(Komandos A[], Map B, int n) {
  for (int i = 0; i < n; i++) {
    int x = B.x0;
    int y = B.y0;
    for (int j = 0; j < A[i].komandosIlgis; j++) {
      switch (A[i].komandos[j]) {
        case 1:
          y += 1;
          break;
        case 2:
          x += 1;
          break;
        case 3:
          y -= 1;
          break;
        case 4:
          x -= 1;
          break;
      }
      A[i].kiek ++;
      if (x == B.x1 && y == B.y1) {
        A[i].res = "pasiektas tikslas";
        break;
      }
    }
  }
}
