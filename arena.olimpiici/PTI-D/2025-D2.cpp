#include <iostream>
#include <map>
#include <vector>
using namespace std;
using LL = long long;
using uLL = __int128_t;
const int N = 1e6 + 3;
const int MODULO = 1e9 + 7;
LL n;
uLL ans = 0;
LL redica[N];
LL stepeniNa2[N];
map<int, LL> sumDoSega2;
inline void read() {
  cin >> n;
  for (int i = 1, e; i <= n; ++i) {
    cin >> redica[i];
  }
}
constexpr void precomputeStepeniNa2() {
  uLL ch = 1;
  for (int i = 0; i <= N; ++i) {
    stepeniNa2[i] = ch;
    ch <<= 1;
    ch %= MODULO;
  }
}
int main() {
  precomputeStepeniNa2();
  read();
  for (int j = 1; j <= n; ++j) {
    LL nj2 = stepeniNa2[j - 1] - 1;
    ans = ans +
          nj2 * ((stepeniNa2[j - 1] - 1) - (sumDoSega2[redica[j]])) % MODULO;
    ans %= MODULO;
    sumDoSega2[redica[j]] += stepeniNa2[j] % MODULO;
  }

  cout << (LL)ans << endl;
  return 0;
}