// 80-1 Seka
#include <fstream>
#include <iomanip>
#include <iostream>
#include <cmath>
using namespace std;
const char CDfv[] = "duomenys.txt";
const char CRfv[] = "rezultatai.txt";
const int CMax    = 10;
//-------------------------------------------------------------------
void Skaityti(const char fv[], int A[], int B[], int C[], int & n, int & m);
void Rikiavimas(int A[], int B[], int C[], int & n, int m);
//-------------------------------------------------------------------
int main()
{
   int SekaA[CMax], SekaB[CMax]; //
   int SekaC[CMax]; // sukurta nauja seka
   int n, m;
   Skaityti(CDfv, SekaA, SekaB, SekaC, n, m);
   Rikiavimas(SekaA, SekaB, SekaC, n, m);
    ofstream fr(CRfv);
    for(int i=0; i<n; i++) {
        fr << SekaC[i] << " " ;
    }
   fr << endl;
   return 0;
}

//-------------------------------------------------------------------
// Skaito duomenis is failo fv
void Skaityti(const char fv[], int A[], int B[], int C[], int & n, int & m)
{
    ifstream fd(fv); // atidaromas ivesties srautas
    fd >> n;
    for (int i = 0; i < n; i++) {
        fd >> A[i];
        C[i] = A[i]; }
    fd >> m;
    for (int j = 0; j < m; j++) {
        fd >> B[j]; }
   fd.close(); // uzdaromas ivesties srautas
}

//-------------------------------------------------------------------
//
void Rikiavimas(int A[], int B[], int C[], int & n, int m)
{
    int n0 = n;
    int off = 0; //reiksmiu pasislinkimas del iterptos reiksmes
    for(int i=0; i < n0; i++) {
        for (int j=0; j < m; j++) {
            if (B[j] % A[i] == 0) {
                n++;
                for (int z=n; z > i+1+off; z--) {
                C[z] = C[z-1]; }
                C[i+1+off] = B[j];
                off++;
            }
    }}
}
