//Ciklas WHILE
#include <iostream>
using namespace std;

int main()
{
  int s = 10; int a = 10; int b = 5; int c = 2;
  while (a > b) {
    s = s + a;
    a = a - c;
    b = b + c;
  }
  cout << "s = " << s << endl;
  cout << "a = " << a << endl;
  cout << "b = " << b << endl;
  cout << "c = " << c << endl;
  return 0;
}
