#include <iostream>
#include <sys/types.h>

using namespace std;
using LL = long long;

LL gcd(LL a, LL b) {
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

pair<LL, LL> extendedEvklid(LL a, LL b) {
  if (b == 0)
    return {1, 0};
  pair<LL, LL> p = extendedEvklid(b, a % b);
  LL x = p.second;
  LL y = p.first - (a / b) * p.second;
  return {x, y};
}

signed main() {
  LL a, b, c;
  cin >> a >> b >> c;

  int nod = gcd(a, b);
  if (c % nod != 0) {
    cout << "Impossible" << endl;
    return 0;
  }
  a /= nod;
  b /= nod;
  c /= nod;

  pair<LL, LL> p = extendedEvklid(a, b);

  int x = p.first * c;
  int y = p.second * c;
  cout << x + y << endl;
}
