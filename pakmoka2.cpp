#include <iostream>
using namespace std;

int main()
{
  int x;
  cout << "irašikite skaičiu: ";
  cin >> x;
  if ( (x == 4/* keturių kartotinis, aš necimenu*/) || (x == 0) ) cout << "Skaičius tinkamas";
  else cout << "Skaičius netinkamas";
  return 0;
}
