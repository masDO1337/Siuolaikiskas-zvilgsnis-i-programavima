// Ligonis
#include <fstream>
#include <iomanip>
#include <iostream>
#include <cmath>
using namespace std;
const char CDfv[] = "Duomenys8-3.txt";
const char CRfv[] = "Rezultatai8-3_papildymas.txt";
const int CMax    = 24;
//-------------------------------------------------------------------
void Skaityti(const char fv[], int A[], double B[], int & n);
void Spausdinti(const char fv[], int A[], double B[], int n);
int AuksciausiaTemp(double B[], int n);
double VirdurkisTemp(int A[], double B[], int n, int startTime, int stopTime);
void SpausdintiAukstaTemp(const char fv[], int A[], double B[], int n, double max);
//-------------------------------------------------------------------
int main()
{
   int V[CMax]; // temperaturos matavimo valandos
   double T[CMax]; // ligonio temperaturos rodmenys
   int n; // temperaturos matavimu skaicius
   int indmax;
   ofstream fr;
   Skaityti(CDfv, V, T, n);
   Spausdinti(CRfv, V, T, n);
   fr.open(CRfv, ios::app);
   indmax = AuksciausiaTemp(T, n);
   fr << "Auksciausia temperatura " << T[indmax] << " buvo " << V[indmax] << " val." << endl;
   fr << "Vidutinė temperatūra per visą laikotarpį buvo: " << fixed << setprecision(1) << VirdurkisTemp(V, T, n, V[0], V[n-1]) << endl;
   fr << "Vidutinė temperatūra per nurodytą laikotarpį nuo 10 iki 18 buvo: " << fixed << setprecision(1) << VirdurkisTemp(V, T, n, 10, 18) << endl;
   fr.close();
   SpausdintiAukstaTemp(CRfv, V, T, n, T[indmax]);
   cout << "DONE!" << '\n';
   return 0;
}

//-------------------------------------------------------------------
// Skaito duomenis is failo fv i masyvus A(n) ir B(n)
void Skaityti(const char fv[], int A[], double B[], int & n)
{
   ifstream fd(fv);
   fd >> n;
   for (int i = 0; i < n; i++)
      fd >> A[i] >> B[i];
   fd.close();
}
//-------------------------------------------------------------------
// Raso masyvu A(n) ir B(n) reiksmes i faila fv lentele
void Spausdinti(const char fv[], int A[], double B[], int n)
{
   ofstream fr(fv);
   fr << " Ligonio temperatûra " << endl;
   fr << "----------------------" << endl;
   fr << " Valanda Temperatûra " << endl;
   fr << "----------------------" << endl;
   for (int i = 0; i < n; i++)
      fr << setw(5) << A[i] << "            "<< fixed << setw(2) << setprecision(1) << B[i] << endl;
   fr << "----------------------" << endl;
   fr.close();
}
//-------------------------------------------------------------------
// Randa masyvo B(n) didziausios reiksmes indeksa ir ji grazina
int AuksciausiaTemp(double B[], int n)
{
   double max = B[0]; // didziausio skaiciaus pradine reiksme
   int maxind = 0; // didzia﻿usio skaiciaus vieta masyve
   for (int i = 1; i < n; i++)
      if (B[i] > max) { // jeigu rasta didesne reiksme, tai
         max = B[i]; // isimenama si reiksme ir
         maxind = i; // jos vieta masyve
      }
   return maxind; // grazinama didziausios reiksmes vieta masyve
}
//-------------------------------------------------------------------
double VirdurkisTemp(int A[], double B[], int n, int startTime, int stopTime)
{
  double virTemp = 0;
  int m = 0;
   for (int i = 0; i < n; i++){
     if (A[i] >= startTime && A[i] <= stopTime) {
       virTemp += B[i];
       m ++;
     }
   }
   return virTemp/m;
}
//-------------------------------------------------------------------
// Pagal masyvo B(n) reiksmes, artimas (+–0.5) skaiciui max,
// raso i faila fv masyvo A(n) reiksmes
void SpausdintiAukstaTemp(const char fv[], int A[], double B[], int n, double max)
{
    int a = 0;
   ofstream fr(fv, ios::app);
   fr << "Auksta temperatura dar buvo:" << endl;
   for (int i = 0; i < n; i++)
      if (fabs(max - B[i]) <= 0.5) {
            fr << A[i] << " val. " << B[i] << endl;
            a ++;
      }
   fr << "Artima aukščiausiai temperatūra buvo " << a << " kartus (-ų):" << endl;
   fr.close();
}
//-------------------------------------------------------------------
