#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;
const char CDfv[] = "U2.txt";
const char CRfv[] = "U2rez.txt";
const int CMax = 30;
const int CPav = 20;

struct Daliviai {
  char pav[CPav+1];
  int nr;
  int start_time;
  int time[3];
  int stop_time = 0;
  int patake[4];
};
//-----------------------------------------------------------------------
void Skaityti(const char fv[], Daliviai A[], int & n);
void Spausdinti(Daliviai A[], int n, ofstream & fr, string s);
void Rikiuoti(Daliviai A[], int n);
//-----------------------------------------------------------------------
int main()
{
   Daliviai A[CMax]; int n;
   Skaityti(CDfv, A, n);
   for (size_t i = 0; i < n; i++) {
     if (A[i].stop_time > 0) {
       A[i].stop_time -= A[i].start_time;
       int z = 4;
       if (A[i].nr < 200) z -= 2;
       for (size_t j = 0; j < z; j++) {
         A[i].stop_time += (5 - A[i].patake[j])*60;
       }
       A[i].time[0] = A[i].stop_time / 3600;
       A[i].time[1] = A[i].stop_time / 60 % 60;
       A[i].time[2] = A[i].stop_time % 60;
     }
   }
   Rikiuoti(A, n);
   ofstream fr (CRfv);
   Spausdinti(A, n, fr, "Merginos");
   Spausdinti(A, n, fr, "Vaikinai");
   fr.close();
   return 0;
}
//-----------------------------------------------------------------------
void Skaityti(const char fv[], Daliviai A[], int & n)
{
   ifstream fd (fv);
   int v, m, s;
   int x, nr;
   fd >> n;
   fd.ignore(80, '\n');
   for (size_t i = 0; i < n; i++) {
     fd.get(A[i].pav, CPav);
     fd >> A[i].nr;
     fd >> v >> m >> s;
     A[i].start_time = v*3600+m*60+s;
     fd.ignore(80, '\n');
   }
   fd >> x;
   fd.ignore(80, '\n');
   while (x > 0) {
     fd >> nr;
     for (size_t i = 0; i < n; i++) {
       if (nr == A[i].nr) {
         fd >> v >> m >> s;
         A[i].stop_time = v*3600+m*60+s;
         int z = 4;
         if (nr < 200) z -= 2;
         for (size_t j = 0; j < z; j++) {
           fd >> A[i].patake[j];
         }
       }
     }
     fd.ignore(80, '\n');
     x --;
   }
   fd.close();
}
//-----------------------------------------------------------------------
void Spausdinti(Daliviai A[], int n, ofstream & fr, string s)
{
   fr << s << endl;
   for (int i = 0; i < n; i++) {
     if (s == "Merginos") {
       if (A[i].nr < 200 && A[i].stop_time > 0) {
         fr << A[i].nr << " " << A[i].pav << " " << A[i].time[0] << " " << A[i].time[1] << " " << A[i].time[2] << endl;
       }
     } else {
       if (A[i].nr > 200 && A[i].stop_time > 0) {
         fr << A[i].nr << " " << A[i].pav << " " << A[i].time[0] << " " << A[i].time[1] << " " << A[i].time[2] << endl;
       }
     }
   }
}
//-----------------------------------------------------------------------
void Rikiuoti(Daliviai A[], int n)
{
  for (int i = 0; i < n; i++)
     for (int j = i + 1; j < n; j++)
        if (A[j].stop_time < A[i].stop_time) {
           Daliviai sp = A[i];
           A[i] = A[j];
           A[j] = sp;
        }
}
