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
std::ostream &operator<<(std::ostream &o, const __int128 &x) {
  if (x == std::numeric_limits<__int128>::min())
    return o << "-170141183460469231731687303715884105728";
  if (x < 0)
    return o << "-" << -x;
  if (x < 10)
    return o << (char)(x + '0');
  return o << x / 10 << (char)(x % 10 + '0');
}
int main() {
  forSq = read();
  cout << (unsigned long long)sqrt(forSq) << endl;
}