// Klases sarasas
#include <fstream>
#include <iomanip>
#include<iostream>
#include <string>
using namespace std;
const char CDfv[] = "Duomenys.txt";
const char CRfv[] = "Rezultatai.txt";
const int CMax = 30;
const int CPav = 25;
//-----------------------------------------------------------------------
struct Mokinys {
  string pav; // pavarde ir vardas
  string dalykas; // pasirinkto dalyko pavadinimas
};
//-----------------------------------------------------------------------
void SkaitytiPav(ifstream & fd, Mokinys A[], int & n);
void SkaitytiKlase(ifstream & fd, Mokinys A[], int & n);
void Spausdinti(Mokinys A[], int n, string eil);
void Trinti(Mokinys B[], int m, Mokinys A[], int &n);
void Papildyti(Mokinys C[], int k, Mokinys A[], int & n);
void Rikiuoti(Mokinys A[], int n);
void Atrinkti(Mokinys A[], int n, string dalykas, Mokinys B[], int & m);
//-----------------------------------------------------------------------
int main()
{
  Mokinys Klase[CMax]; int n; // klases mokiniu sarasas Mokinys
  Ate[CMax]; int m; // isvykusiu mokiniu sarasas Mokinys
  Nauji[CMax]; int k; // naujoku sarasas ofstream
  fr(CRfv); fr.close();
  ifstream fd(CDfv);
  SkaitytiPav(fd, Ate, m);
  SkaitytiKlase(fd, Nauji, k);
  SkaitytiKlase(fd, Klase, n);
  fd.close();
  Trinti(Ate, m, Klase, n);
  Papildyti(Nauji, k, Klase, n);
  Rikiuoti(Klase, n);
  Spausdinti(Klase, n, "Klases sarasas");
  Atrinkti(Klase, n, "Etika", Ate, m);
  Spausdinti(Ate, m, "Etika pasirinkusieji mokiniai");
  return 0;
}
//-----------------------------------------------------------------------
// Is nurodyto duomenu srauto fd skaitoma n reiksmiu i masyva A (isvykusiu mokiniu pavardes)
void SkaitytiPav(ifstream & fd, Mokinys A[], int & n)
{
  char eil[CPav + 1]; fd >> n; // skaicius mokiniu, kuriu pavardes yra surasytos
  fd.ignore(80, '\n'); // pereinama i kita eilutæ
  for (int i = 0; i < n; i++) {
    fd.get(eil, CPav); // perskaitoma vieno mokinio pavarde ir vardas
    A[i].pav = eil; A[i].dalykas = ""; // dalykas nenurodytas, todel i masyva irasoma tuscia eilute
    fd.ignore(80, '\n'); // pereinama i kita eilutæ
  }
}
//-----------------------------------------------------------------------
// Skaitomi klases mokiniu duomenys
// fd – duomenu srautas, A(n) – masyvas, i kuri skaitomi duomenys
void SkaitytiKlase(ifstream & fd, Mokinys A[], int & n)
{
  char eil[CPav + 1]; fd >> n; // skaicius mokiniu, kuriu pavardes surasytos
  fd.ignore(80, '\n'); // pereinama i kita eilutæ
  for (int i = 0; i < n; i++) {
    fd.get(eil, CPav); // perskaitoma vieno mokinio pavarde ir vardas
    A[i].pav = eil;
    fd >> ws; // praleidþiami tarpo simboliai iki kitos simboliu eilutes
    getline(fd, A[i].dalykas); // perskaitomas dalyko pavadinimas (iki eilutes pabaigos)
  }
}
//------------------------------------------------------------------- \
// Rasomi masyvo A(n) duomenys lentele, kurios pavadinimas perduodamas eilute eil
void Spausdinti(Mokinys A[], int n, string eil)
{
  ofstream fr(CRfv, ios::app); // failas paruosiamas papildyti
  fr << eil << endl;
  fr << "-------------------------------" << endl;
  fr << " Mokinys Dalykas " << endl;
  fr << "-------------------------------" << endl;
  for (int i = 0; i < n; i++) fr << setw(20) << left << A[i].pav << " " << A[i].dalykas << endl;
  fr << "-------------------------------" << endl;
  fr.close();
}
//-----------------------------------------------------------------------
// Is A(n) masyvo pasalinami masyvo B(m) duomenys
void Trinti(Mokinys B[], int m, Mokinys A[], int & n)
{
  for (int i = 0; i < m; i++) // perþiûrimas salinamuju sarasas
  for (int j = 0; j < n; j++) // ieskoma klases sarase
  if (B[i].pav == A[j].pav) { // lyginamos pavardþiu ir vardu eilutes
    A[j] = A[n - 1]; // salinamos reiksmes vietoje irasoma paskutine masyvo reiksme
    n--; // sumaþinamas klases saraso reiksmiu skaicius
    j = n; // vidinio ciklo darbas nutraukiamas
  }
}
//-----------------------------------------------------------------------
// Masyvo C(k) reiksmes kopijuoja i masyvo A(n) pabaiga
void Papildyti(Mokinys C[], int k, Mokinys A[], int & n)
{
  for (int i = 0; i < k; i++) {
    A[n] = C[i]; n++;
  }
}
//-----------------------------------------------------------------------
// Masyvas A(n) rikiuojamas pagal kintamojo pav reiksmæ abeceliskai
void Rikiuoti(Mokinys A[], int n)
{
  for (int i = 0; i < n; i++)
  for (int j = i + 1; j < n; j++)
  if (A[j].pav < A[i].pav) {
    Mokinys sp = A[i];
    A[i] = A[j];
    A[j] = sp;
  }
}
//-----------------------------------------------------------------------
// Is masyvo A(n) perrasomi i masyva B(m) duomenys,
// kuriu kintamojo dalykas reiksme sutampa su funkcijos parametro dalykas reiksme
void Atrinkti(Mokinys A[], int n, string dalykas, Mokinys B[], int & m)
{
  m = 0;
  for (int i = 0; i < n; i++)
  if (A[i].dalykas == dalykas) {
    B[m] = A[i]; m++;
  }
}
