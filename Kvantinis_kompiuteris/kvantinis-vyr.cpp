#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;
const char CDfv[] = "kvantinis-vyr.in";
const char CRfv[] = "kvantinis-vyr.out";
const int CMax = 1000;

struct map {
         int N;
         int M;
         char S[CMax][CMax];
         bool end = false;
         int endN = 0;
         int endM = 0;
         bool start = false;
         int n = 0;
         int m = 0;
         int nT = 0;
         int mT = 0;
};

//-----------------------------------------------------------------------
void Skaityti(map & S);
void Spausdinti(map S);
//-----------------------------------------------------------------------
int main()
{
   map K;
   Skaityti(K);
   for (int i = 0; i < K.N; i++) {
     for (int j = 0; j < K.M; j++) {
       char ss = K.S[i][j];
       if (ss == '.') {
         if (K.start == false) {
           K.start = true;
           K.n = i;
           K.m = j;
           K.S[i][j] = 'L';
         }
       }
       if (ss == 'J') {
         K.end = true;
         K.endN = i;
         K.endM = j;
         K.S[i][j] = '.';
       }
     }
   }
   for (int i = 0; i < K.N; i++) {
     for (int j = 0; j < K.M; j++) {
       if (K.S[i][j] == '.') {
         if (K.S[i + 1][j] == '.') {
           if (K.m != j && K.mT != j) {
             K.S[i][j] = 'v';
             K.nT = i;
             K.mT = j;
           }
         }
         if (K.S[i - 1][j] == '.') {
           if (K.m != j && K.mT != j) {
             K.S[i][j] = '^';
             K.nT = i;
             K.mT = j;
           }
         }
         if (K.S[i][j + 1] == '.') {
           if (K.n != i && K.nT != i) {
             K.S[i][j] = '>';
             K.nT = i;
             K.mT = j;
           }
         }
         K.m = j;
       }
       K.n = i;
     }
   }
   K.S[K.endN][K.endM] = 'J';
   Spausdinti(K);
   return 0;
}
//-----------------------------------------------------------------------
void Skaityti(map & S)
{
   ifstream fd (CDfv);

   fd >> S.N;
   fd >> S.M;
   for (int i = 0; i < S.N; i++) {
     for (int j = 0; j < S.M; j++) {
       fd >> S.S[i][j];
     }
   }

   fd.close();
}
//-----------------------------------------------------------------------
void Spausdinti(map S)
{
   ofstream fr (CRfv);
   if (S.end == true && S.start == true) {
     for (int i = 0; i < S.N; i++) {
       for (int j = 0; j < S.M; j++) {
         fr << S.S[i][j];
         cout << S.S[i][j];
       }
       fr << endl;
       cout << endl;
     }
   } else {
     fr << "NEPASIEKIAMA";
     cout << "NEPASIEKIAMA";
   }
   fr.close();
}
//-----------------------------------------------------------------------
