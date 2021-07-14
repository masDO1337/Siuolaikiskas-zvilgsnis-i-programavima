#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;
const char CDfv[] = "Duomenys.txt";
const char CRfv[] = "Rezultatai.txt";
const int Max     = 3000;
//-------------------------------------------------------------------
void Skaityti(int A[][5], int & n);
void Spausdinti(int A[][5], int n);

int nr(int A[][5], int n, bool a);
string metai(int A[][5], int n);

//-------------------------------------------------------------------
int main() {
  int A[Max][5]; int n;
  Skaityti(A, n);
  Spausdinti(A, n);
  cout << "OK" << '\n';
  return 0;
}
//-------------------------------------------------------------------
void Skaityti(int A[][5], int & n) {
   ifstream fd(CDfv);
   char index = 0;
   fd >> n;
   for (int i = 0; i < n; i++) {
     for (int j = 0; j < 5; j++) {
       A[i][j] = 0;
       fd >> index;
       if (j == 0) {
         A[i][j] = (int)index - 48;
       }
       if (j >= 1 && j <= 3) {
         int a = ((int)index - 48) * 10;
         fd >> index;
         a += (int)index - 48;
         A[i][j] = a;
       }
       if (j == 4) {
         int a = ((int)index - 48) * 1000;
         fd >> index;
         a += (((int)index - 48) * 100);
         fd >> index;
         a += (((int)index - 48) * 10);
         fd >> index;
         a += (int)index - 48;
         A[i][j] = a;
       }
     }
   }
   fd.close();
}
//-------------------------------------------------------------------
void Spausdinti(int A[][5], int n) {
   ofstream fr(CRfv);
   fr << "Vyriausias vyras gime: " << metai(A, nr(A, n, true)) << '\n';
   fr << "Vyriausia moteris gime: " << metai(A, nr(A, n, false)) << '\n';
   fr.close();
}
//-------------------------------------------------------------------
int nr(int A[][5], int n, bool a) {
  int MIN = 99999;
  int ID = 0;
  for (int i = 0; i < n; i++) {
    if (a) {
      if (A[i][0] == 3 || A[i][0] == 5) {
        if (A[i][4] < MIN) {
          MIN = A[i][4];
          ID = i;
        }
      }
    } else {
      if (A[i][0] == 4 || A[i][0] == 6) {
        if (A[i][4] < MIN) {
          MIN = A[i][4];
          ID = i;
        }
      }
    }
  }
  return ID;
}
//-------------------------------------------------------------------
string metai(int A[][5], int n) {
  if (A[n][0] == 3 || A[n][0] == 4) {
    string ret = "19";
    if (A[n][1] < 10) { ret += "0"; }
    ret += to_string(A[n][1]) + " m. ";
    return ret + to_string(A[n][2]) + " " + to_string(A[n][3]) + " d.";
  } else if (A[n][0] == 5 || A[n][0] == 6) {
    string ret = "20";
    if (A[n][1] < 10) { ret += "0"; }
    ret += to_string(A[n][1]) + " m. ";
    return ret + to_string(A[n][2]) + " " + to_string(A[n][3]) + " d.";
  } else {
    return "nera";
  }
}
