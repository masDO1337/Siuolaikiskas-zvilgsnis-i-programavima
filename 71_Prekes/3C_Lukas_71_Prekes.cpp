// Prekes
#include <fstream>
#include <iomanip>
#include <iostream>
#include <cmath>
using namespace std;
const char CDfv[] = "duomenys.txt";
const char CRfv[] = "rezultatai.txt";
const int CMax    = 100;
//-------------------------------------------------------------------
void Skaityti(const char fv[], int A[][100], int & p, int & n, int & xmax);
void Pirkti(int A[][100], int & p, int n, int xmax, int & pirko);
//-------------------------------------------------------------------
int main()
{
   int Kaina[50][CMax]; //
   int p, n, xmax=0, pirko = 0;
   Skaityti(CDfv, Kaina, p, n, xmax);
    ofstream fr(CRfv);
    Pirkti(Kaina, p, n, xmax, pirko);
fr << pirko << " " << p << endl;
   return 0;
}

//-------------------------------------------------------------------
// Skaito duomenis is failo fv
void Skaityti(const char fv[], int A[][100], int & p, int & n, int & xmax)
{
   ifstream fd(fv); // atidaromas ivesties srautas
   int x;
   fd >> p >> n;
   for (int i = 0; i < n; i++) {
        fd >> x;
        if(x>xmax) xmax = x;
        for (int j = 0; j < x; j++) {
            fd >> A[i][j] ;}}
   fd.close(); // uzdaromas ivesties srautas
}
//-------------------------------------------------------------------
//
void Pirkti(int A[][100], int & p, int n, int xmax, int & pirko)
{
    int kaina;
    for(int i=0; i<n; i++) {
            kaina=0;
    for (int j=0; j<xmax; j++) {
        if((A[i][j] <= p) && (A[i][j] >= kaina)){
            kaina = A[i][j]; }}
        if(kaina != 0) {
    p = p - kaina;
    pirko++; }
}}
