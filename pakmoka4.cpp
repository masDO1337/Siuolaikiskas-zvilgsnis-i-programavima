//Ciklas FOR
#include <iostream>
using namespace std;

int main()
{
   int m = 3; int n = 6; int x = 2;
   if (x % 2 == 0) m = m + 1;
   else m = m - 1;
   for (int a = m; a <= n; a++) {
     if (x % 2 != 0) x = x / 3;
     else x = x / 2;
     x--;
   }
  cout << "m = " << m << endl;
  cout << "x = " << x << endl;
  return 0;
}
