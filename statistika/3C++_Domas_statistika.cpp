#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;
const char CDfv[] = "duomenys1.txt";
const char CRfv[] = "rezultatai1.txt";
const int Max     = 13;

struct dataInfo {
  int krepsininkoNumeris;
  int laikas[2];
  int dvitaskiu;
  int tritaskiu;
  int baudu;
};
//-------------------------------------------------------------------
void Skaityti(dataInfo A[], int & n);
void Spausdinti(dataInfo A[], int n);
int DidziausiasTasku(dataInfo A[], int n);
int DidziausiasTritaskiuTasku(dataInfo A[], int n);
int MaziausiasLaiko(dataInfo A[], int n);
int SumaVisuDvitaskiu(dataInfo A[], int n);
int SumaVisuBaudu(dataInfo A[], int n);
int SumaVisu(dataInfo A[], int n);
//-------------------------------------------------------------------
int main() {
  dataInfo A[Max];
  int n;
  Skaityti(A, n);
  Spausdinti(A, n);
  cout << "OK" << '\n';
  return 0;
}
//-------------------------------------------------------------------
void Skaityti(dataInfo A[], int & n) {
   ifstream fd(CDfv);
   fd >> n;
   for (int i = 0; i < n; i++) {
     fd >> A[i].krepsininkoNumeris;
     fd >> A[i].laikas[0];
     fd >> A[i].laikas[1];
     fd >> A[i].dvitaskiu;
     fd >> A[i].tritaskiu;
     fd >> A[i].baudu;
   }
   fd.close();
}
//-------------------------------------------------------------------
void Spausdinti(dataInfo A[], int n) {
   ofstream fr(CRfv);
   fr << A[DidziausiasTasku(A, n)].krepsininkoNumeris << endl;
   fr << A[MaziausiasLaiko(A, n)].krepsininkoNumeris << endl;
   fr << A[DidziausiasTritaskiuTasku(A, n)].krepsininkoNumeris << endl;
   fr << SumaVisuDvitaskiu(A, n) << endl;
   fr << SumaVisuBaudu(A, n) << endl;
   fr << SumaVisu(A, n) << endl;
   fr.close();
}
//-------------------------------------------------------------------
int DidziausiasTasku(dataInfo A[], int n)
{
   int vieta = 0;
   int suma = 0;
   int sumaOld = 0;
   for (int i = 1; i < n; i++) {
     suma = 0;
     suma += A[i].dvitaskiu;
     suma += A[i].tritaskiu;
     suma += A[i].baudu;
     if (suma > sumaOld) {
       vieta = i;
       sumaOld = suma;
     }
   }
   return vieta;
}
//-------------------------------------------------------------------
int DidziausiasTritaskiuTasku(dataInfo A[], int n)
{
   int vieta = 0;
   for (int i = 1; i < n; i++) {
     if (A[i].tritaskiu > A[vieta].tritaskiu) {
       vieta = i;
     }
   }
   return vieta;
}
//-------------------------------------------------------------------
int MaziausiasLaiko(dataInfo A[], int n)
{
   int vieta = 0;
   int suma = 0;
   int sumaOld = 999999;
   for (int i = 1; i < n; i++) {
     suma = 0;
     suma += (A[i].laikas[0] * 60);
     suma += A[i].laikas[1];
     if (suma < sumaOld) {
       vieta = i;
       sumaOld = suma;
     }
   }
   return vieta;
}
//-------------------------------------------------------------------
int SumaVisuDvitaskiu(dataInfo A[], int n)
{
   int suma = 0;
   for (int i = 0; i < n; i++)
     suma = suma + A[i].dvitaskiu;
   return suma*2;
}
//-------------------------------------------------------------------
int SumaVisuBaudu(dataInfo A[], int n)
{
   int suma = 0;
   for (int i = 0; i < n; i++)
     suma = suma + A[i].baudu;
   return suma;
}
//-------------------------------------------------------------------
int SumaVisu(dataInfo A[], int n)
{
   int suma = 0;
   for (int i = 0; i < n; i++) {
     suma += A[i].dvitaskiu * 2;
     suma += A[i].tritaskiu * 3;
     suma += A[i].baudu;
   }
   return suma;
}
