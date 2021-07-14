#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;
const int lim = 12;
void skaitymas(int & n, int z[], int l[], int d[], int t[], int b[]); // skaito duomenys
void daugiausiat (int n, int z[], int d[], int t[], int b[], int & dtz); //daugiausia tasku
void maziausiailaik (int n, int l[], int z[], int & mz);// maziausiai zaides
void daugiausiatry (int n, int z[], int t[], int & dtryz); // daugiausia tritaskiu
void bttv(int n, int t[], int d[], int b[], int & dvitt, int & baudos, int & viso); // baudos, dvitaskiu taskai, visi taskai
//-------------------------------------------------------------------
//-------------------------------------------------------------------
int main()
{
    int n, z[lim], l[lim], d[lim], t[lim], b[lim], dtz, mz, dtryz, dvitt, baudos, viso; // n - zaideju skaicius, z - zaideju numeris, l - kiek laiko zaide, d - zaidejo dvitaskiai, t - zaidejo trytaskiai, b - zaidejo baudos, dtz - daugiausia tasku gaves, mz - maziausiai zaides, dtryz- daugiausia trytaskiu, dvitt- kiek tasku per dvitaskius, baudos- baudos, viso-isvis tasku.
    skaitymas(n, z, l, d, t, b);
    daugiausiat(n, z, d, t, b, dtz);
    maziausiailaik(n, l, z, mz);
    daugiausiatry(n, z, t, dtryz);
    bttv(n, t, d, b, dvitt, baudos, viso);
    ofstream fr;
    fr.open("rezultatai.txt");
    fr << dtz << endl;
    fr << mz << endl;
    fr << dtryz << endl;
    fr << dvitt << endl;
    fr << baudos << endl;
    fr << viso << endl;
    fr.close();
    return 0;
}
void skaitymas(int & n, int z[], int l[], int d[], int t[], int b[])
{
    int i, minu, s;// minu -  minutes, s- sekundes
    ifstream fd;
    fd.open("Duomenys.txt");
    fd >> n;
    for(i = 0; i <= n-1; i++)
    {
        fd >> z[i];
        fd >> minu;
        fd >> s;
        l[i] = minu*60+s;
        fd >> d[i];
        fd >> t[i];
        fd >> b[i];
    }
    fd.close();
}
void daugiausiat (int n, int z[], int d[], int t[], int b[], int & dtz)
{
    int i, tz, maxt;// tz - zaidejo taskai, maxt - daugiausia tasku;
    dtz = 0;
    maxt = 0;
    for(i = 0; i<= n-1; i++)
    {
        tz = d[i]*2+t[i]*3+b[i];
        if(tz > maxt)
        {
            maxt = tz; dtz = i;
        }
    }
    dtz = z[dtz];
}
void maziausiailaik (int n, int l[], int z[], int & mz)
{
    int i, mzl;// mzl- maziausias laikas
    mzl = l[0];
    for(i = 1; i < n-1; i++)
    {
        if (l[i] < mzl){mzl = l[i]; mz = i;}
    }
    mz = z[mz];
}
void daugiausiatry (int n, int z[], int t[], int & dtryz)
{
    int i, maxtryz;// maxtryz daugiausias tritaskiu skaicius
    maxtryz = 0;
    for(i = 0; i <= n-1; i++)
    {
        if(t[i]>maxtryz){maxtryz = t[i]; dtryz = i;}
    }
    dtryz = z[dtryz];
    }
void bttv(int n, int t[], int d[], int b[], int & dvitt, int & baudos, int & viso)
{
    int i;
    viso = 0;
    dvitt = 0;
    baudos = 0;
    for(i = 0; i <= n-1; i++)
    {
        dvitt = d[i]*2+dvitt;
        baudos = baudos+b[i];
        viso = viso+d[i]*2+t[i]*3+b[i];
    }
}
