#include <iostream>
#define prov()                                                                 \
  if (brL > maxL) {                                                            \
    best = predi;                                                              \
    maxL = brL;                                                                \
  }
using namespace std;
int main() {
  int maxL = 0;
  int brL = 0;
  char predi = '*', best = '*';
  char ch = getchar();
  while (ch >= 'a' && ch <= 'z') {
    if (predi == ch)
      ++brL;
    else {
      prov();
      brL = 1;
    }
    predi = ch;
    ch = getchar();
  }
  prov();
  cout << maxL << " " << best << endl;
  return 0;
}