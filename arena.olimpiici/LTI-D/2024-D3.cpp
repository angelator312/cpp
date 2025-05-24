#include <cmath>
#include <iostream>
using namespace std;
using LL = __int128_t;
LL forSq = 1024001024;
LL read() {
  LL x = 0;
  char ch = getchar();
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x;
}
int main() {
  forSq = read();
  cout << (unsigned long long)sqrt(forSq) << endl;
}