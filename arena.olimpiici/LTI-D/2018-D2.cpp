#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
using LL = long long;
using uLL = __int128_t;
using pB = pair<bool, int>;
const int SQRT = 1e7 + 2;
const int PRIMES = 664578;
bool erat[SQRT];
const int LOG1e14 = log2(1e14);
LL a, b, br = 0, sz = 0;
LL primes[PRIMES];
LL pow2(const int &a) { return 1 << a; }
LL tmp = 0;
constexpr inline void eratosten() {
  primes[0] = 2;
  for (int i = 3; i < SQRT; i += 2) {
    if (erat[i])
      continue;
    primes[++sz] = i;
    for (int j = 2 * i; j <= SQRT; j += i)
      erat[j] = true;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  eratosten();
  cin >> a >> b;
  for (auto e : primes) {
    // if (e > b)
    //   break;
    uLL ch = 1;
    uLL e2 = e * e;
    for (int i = 2; i <= LOG1e14; i += 2) {
      ch *= e2;
      if (ch > b)
        break;
      // cerr << i << " " << (LL)ch << endl;
      if (!erat[i + 1] && a <= ch)
        ++br;
    }
  }

  cout << br << endl;
  return 0;
}