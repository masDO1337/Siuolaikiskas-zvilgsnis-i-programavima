#include <iostream>
#include <iomanip>
using namespace std;
int main() {
   int v1, m1, m2, v, m, l1, l;

   cout << "kada Petras isejo is namu kelinta valandu: "; cin >> v1;
   cout << "kada Petras isejo is namu kelinta minuciu: "; cin >> m1;
   cout << "kiek Petro kelione trunka minuciu: "; cin >> m2;
   cout << "kelinta valanda prasideda pamoka: "; cin >> v;
   cout << "kelinta minute prasideda pamoka: "; cin >> m;

   l1 = v1*60+m1+m2;
   l = v*60+m;

   if (l1 > l) cout << endl << "Petras i pamoka paveluos" << endl;
   else cout << endl << "Petras i pamoka nepaveluos" << endl;

   return 0;
}
