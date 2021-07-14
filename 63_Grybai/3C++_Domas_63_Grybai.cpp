#include <fstream>
#include <iomanip>
#include <iostream>
#include <cmath>
using namespace std;
const char CDfv[] = "Duomenys.txt";
const char CRfv[] = "Rezultatai.txt";
const int CMax    = 100;
struct dataInfo {
  int M;
  int D;
  double m;
  int b;
  int r;
};
//-------------------------------------------------------------------
void Skaityti(const char fv[], dataInfo [], int & n);
void Spausdinti(const char fv[], dataInfo [], int n);
string AuksciausiaM(dataInfo B[], int n);
string AuksciausiaB(dataInfo B[], int n);
string AuksciausiaR(dataInfo B[], int n);
//-------------------------------------------------------------------
int main()
{
   dataInfo A[CMax];
   int n;
   Skaityti(CDfv, A, n);
   Spausdinti(CRfv, A, n);
   return 0;
}

//-------------------------------------------------------------------
void Skaityti(const char fv[], dataInfo B[], int & n)
{
   ifstream fd(fv);
   fd >> n;
   for (int index = 0; index < n; index++) {
     fd >> B[index].M;
     fd >> B[index].D;
     fd >> B[index].m;
     fd >> B[index].b;
     fd >> B[index].r;
   }
   fd.close();
}
//-------------------------------------------------------------------
void Spausdinti(const char fv[], dataInfo B[], int n)
{
   ofstream fr(fv);
   fr << "Derlingiausia diena: " << AuksciausiaM(B, n) << endl;
   fr << "Derlingiausia baravyku diena: " << AuksciausiaB(B, n) << endl;
   fr << "Derlingiausia raudonvirsiu diena: " << AuksciausiaR(B, n) << endl;
   fr.close();
}
//-------------------------------------------------------------------
string AuksciausiaM(dataInfo B[], int n)
{
   double max = B[0].m;
   int index = 0;
   for (int i = 1; i < n; i++)
      if (B[i].m > max) {
         max = B[i].m;
         index = i;
      }
   if (max > 0) {
     return to_string(B[index].M) + " " + to_string(B[index].D);
   } else {
     return "nera";
   }
}
//-------------------------------------------------------------------
string AuksciausiaB(dataInfo B[], int n)
{
   double max = B[0].b;
   int index = 0;
   for (int i = 1; i < n; i++)
      if (B[i].b > max) {
         max = B[i].b;
         index = i;
      }
   if (max > 0) {
     return to_string(B[index].M) + " " + to_string(B[index].D);
   } else {
     return "nera";
   }
}
//-------------------------------------------------------------------
string AuksciausiaR(dataInfo B[], int n)
{
   double max = B[0].r;
   int index = 0;
   for (int i = 1; i < n; i++)
      if (B[i].r > max) {
         max = B[i].r;
         index = i;
      }
   if (max > 0) {
      return to_string(B[index].M) + " " + to_string(B[index].D);
   } else {
      return "nera";
   }
 }
//-------------------------------------------------------------------
