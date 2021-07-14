#include <fstream>
#include <iomanip>
#include <iostream>
#include <cmath>
using namespace std;
const char CDfv[] = "Duomenys2.txt";
const char CRfv[] = "Rezultatai2.txt";
const int CMax    = 100;
struct dataInfo {
                    int zibintas[CMax];
};
//-------------------------------------------------------------------
void Skaityti(const char fv[], dataInfo [], int & n, int & k);
void Naktis(dataInfo [], int n, int k);
void Spausdinti(const char fv[], dataInfo [], int n, int k);
string MaxOrMin(dataInfo [], int n, int k, bool a);
//-------------------------------------------------------------------
int main()
{
   dataInfo A[CMax];
   int n, k;
   Skaityti(CDfv, A, n, k);
   Naktis(A, n, k);
   Spausdinti(CRfv, A, n, k);
   return 0;
}

//-------------------------------------------------------------------
void Skaityti(const char fv[], dataInfo B[], int & n, int & k)
{
   ifstream fd(fv);
   fd >> n >> k;
   for (int index = 0; index < n; index++) {
     fd >> B[0].zibintas[index];
   }
   fd.close();
}
//-------------------------------------------------------------------
void Naktis(dataInfo B[], int n, int k) {
  for (int i = 1; i < k; i++) {
    for (int j = 0; j < n; j++) {
      if (j <= 0) {
        if (B[i-1].zibintas[j+1] == 1) {
          B[i].zibintas[j] = 1;
        }
        if (i % 2 == 1) {
          B[i].zibintas[j] = 1;
        } else {
          B[i].zibintas[j] = 0;
        }
      } else if ((j > 0) && (j < n-1)) {
        if ((B[i-1].zibintas[j-1] == 1) && (B[i-1].zibintas[j+1] == 1)) {
          B[i].zibintas[j] = 0;
        } else if ((B[i-1].zibintas[j-1] == 0) && (B[i-1].zibintas[j+1] == 1)) {
          B[i].zibintas[j] = 1;
        } else if ((B[i-1].zibintas[j-1] == 1) && (B[i-1].zibintas[j+1] == 0)) {
          B[i].zibintas[j] = 1;
        } else {
          if (i % 2 == 1) {
            B[i].zibintas[j] = 1;
          } else {
            B[i].zibintas[j] = 0;
          }
        }
      } else if (j >= n-1) {
        if (B[i-1].zibintas[j-1] == 1) {
          B[i].zibintas[j] = 1;
        }
        if (i % 2 == 1) {
          B[i].zibintas[j] = 1;
        } else {
          B[i].zibintas[j] = 0;
        }
      }
    }
  }

}
//-------------------------------------------------------------------
void Spausdinti(const char fv[], dataInfo B[], int n, int k)
{
   ofstream fr(fv);
   for (int j = 0; j < k; j++) {
     for (int i = 0; i < n; i++) {
       fr << B[j].zibintas[i] << " ";
     }
     fr << endl;
   }
   fr << "Naktis, kai sviete" << endl;
   fr << MaxOrMin(B, n, k, true) << endl;
   fr << "Naktis, kai sviete" << endl;
   fr << MaxOrMin(B, n, k, false) << endl;
   fr.close();
}
//-------------------------------------------------------------------
string MaxOrMin(dataInfo B[], int n, int k, bool a) {
  int b = 0;
  for (int i = 1; i < k; i++) {
    for (int j = 0; j < n; j++) {
      if (B[i-1].zibintas[j] != B[i].zibintas[j]) {
        if (a) {
          if (B[i].zibintas[j] == 1) {
            b++;
          }
        } else {
          if (B[i].zibintas[j] == 0) {
            b++;
          }
        }
      }
    }
  }
  if (a) {
    return "Daugiausia: " + to_string(b);
  } else {
    return "Maziausiai: " + to_string(b);
  }
}
