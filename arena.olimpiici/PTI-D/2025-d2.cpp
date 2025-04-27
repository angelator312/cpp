#include <iostream>
#include <vector>
using namespace std;
using LL = long long;
using uLL = __int128_t;
const int N = 1e6 + 3;
const int MODULO = 1e9 + 7;
LL n;
uLL ans = 0;
LL redica[N];
uLL stepeniNa2[N];
inline void read() {
  cin >> n;
  ans = (stepeniNa2[n] - 1) % MODULO;
  for (int i = 0, e; i < n; ++i) {
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
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (redica[i] != redica[j])
        ans = (ans + stepeniNa2[n - (j - i + 1)]) % MODULO;
    }
  }
  cout << (LL)ans << endl;
  return 0;
}