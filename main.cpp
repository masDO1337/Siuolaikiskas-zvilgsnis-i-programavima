#include <iostream>

using namespace std;

int main()
{
    int m, nr = 0;

    do {
        cout<<"Iveskite metus : "; cin>>m;
    } while ( m < 1896 );

    if ( m % 4 != 0 ) {
        cout <<"[Metai yra neolimpiniai "<< m <<" m.]"<< endl;
        return -1;
    }

    for ( int i = 1896; i <= m; i++)
        if ( i % 4 == 0 ) nr++;

    cout <<"[Metai yra olimpiniai "<< m <<" m.| Nr. "<< nr <<"]"<< endl;

    return 0;
}
