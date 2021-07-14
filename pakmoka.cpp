#include <iostream>
using namespace std;

int main()
{
  bool a, b, c;
  a = true; b = false; c = true;
  a = a && b || !c;
  b = !a || c && b;
  c = !b && !c || a;
  cout << "a = " << a << endl;
  cout << "b = " << b << endl;
  cout << "c = " << c << endl;
  return 0;
}
