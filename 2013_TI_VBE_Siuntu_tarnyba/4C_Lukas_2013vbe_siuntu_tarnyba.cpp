// siuntu tarnyba
#include <fstream>
#include <iomanip>
#include <iostream>
#include <cmath>
using namespace std;
const char CDfv[] ="U1.txt";
const char CRfv[] ="Rezultatai.txt";
const int CMax = 99;
const int CPav = 10;
//
struct Imone {
    string pav;
    int x, y;
    int atstumas;
};
//
void Skaityti(Imone A[], int & n, int & max);
void Atstumas(Imone A[], int n, int & einama, int & max, int & aptarnauta, int & nuvaziuota);
void Spausdinti(Imone A[], int n, int aptarnauta, int einama, int nuvaziuota);
//
int main()
{
    Imone A[CMax]; int n;
    int einama, nuvaziuota;
    int aptarnauta, max;
    Skaityti(A, n, max);
    Atstumas(A, n, einama, max, aptarnauta, nuvaziuota);
    Spausdinti(A, n, aptarnauta, einama, nuvaziuota);
    return 0;
}
//
//
void Skaityti(Imone A[], int & n, int & max)
{
    char eil[CPav + 1];
    ifstream fd(CDfv);
    fd >> n >> max;
    fd.ignore(80, '\n');
    for (int j = 0; j < n ; j++) {
        fd.get(eil, CPav);
        A[j].pav = eil;
        fd >> A[j].x >> A[j].y ;
        if(A[j].x < 0) A[j].x *= -1;
        if(A[j].y < 0) A[j].y *= -1;
        fd.ignore(80, '\n');
    }
    fd.close();
}
//
//
void Atstumas(Imone A[], int n, int & einama, int & max, int & aptarnauta, int & nuvaziuota)
{
    einama = -1;
    aptarnauta = 0;
    nuvaziuota = 0;
    while ((nuvaziuota <= max) && (aptarnauta <= n)) {
            A[aptarnauta].atstumas = 2*(A[aptarnauta].x + A[aptarnauta].y);
        if((nuvaziuota+A[aptarnauta].atstumas)<= max) {
            nuvaziuota += A[aptarnauta].atstumas;
            einama++;
            aptarnauta++;
        }
    }
}
//
//

void Spausdinti(Imone A[], int n, int aptarnauta, int einama, int nuvaziuota)
{
    ofstream fr(CRfv);
    fr << aptarnauta << " " << nuvaziuota << " " << A[einama].pav;
    fr.close();
}
