#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;
const int lim = 10000;
//----------------------------------------------------------------------------
void skaitymas(int & n1, int & n2, int pinigine[], int graza[]);
void sujungti(int n1, int n2, int pinigine[], int graza[]);
void skirstymas(int n1, int n2, int pinigine[]);
void spausdinti (int pinigine[], int n1, int n2);
//----------------------------------------------------------------------------
int main()
{
    int n1, n2, pinigine[lim], graza[lim];
    skaitymas(n1, n2, pinigine, graza);
    sujungti(n1, n2, pinigine, graza);
    skirstymas(n1, n2, pinigine);
    spausdinti(pinigine, n1, n2);
    return 0;
}
void skaitymas(int & n1, int & n2, int pinigine[], int graza[])
{
    ifstream fdra;
    ifstream fdri;
    fdra.open("duomenys1.txt");
    fdri.open("duomenys2.txt");
    fdra >> n1;
    fdri >> n2;
    for (int i = 0; i < n1; i++)
		{
			fdra >> pinigine[i];
			cout << pinigine[i] << " ";
		}
		cout << endl;
    for (int i = 0; i < n2; i++)
		{
			fdri >> graza[i];
			cout << graza[i] << " ";
		}
		cout << endl;
	fdra.close();
    fdri.close();
}
void sujungti(int n1, int n2, int pinigine[], int graza[])
{
    int m = 0;
    for (int i = n1; i < n1+n2; i++)
    {
        pinigine[i] = graza [m];
        m++;
    }
    for (int i = 0; i < n1+n2; i++)
    {
        cout << pinigine[i] << " ";
    }
    cout << endl;
}
void skirstymas(int n1, int n2, int pinigine[])
{
	int laik = 0;
	for (int i = 1; i < n1+n2; i++)
	{
	    int j = i;
	    while (j > 0 && pinigine[j - 1] > pinigine[j])
	    {
	        laik = pinigine[j];
	        pinigine[j] = pinigine[j - 1];
	        pinigine[j - 1] = laik;
	        j--;
	    }
	}
	for (int i = 0; i < n1+n2; i++)
    {
        cout << pinigine[i] << " ";
    }
}
void spausdinti(int pinigine[], int n1, int n2)
{
    ofstream fr;
    fr.open("rezultatas.txt");
    for (int i = 0; i < n1 + n2; i++)
        {
        fr << pinigine[i] << " ";
        }
    fr.close();
}
