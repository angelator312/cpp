#include <iostream>
using namespace std;
using LL = long long;
using LL2 = __int128_t;
const int N = 1e7 + 2;
LL boxers[N];
LL n,k;
LL sum;
LL2 umnozh;
LL minR[N];
inline void Init() {
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    cin >> boxers[i];
  }
}

int main() {
  Init();
  LL j = 0, br = 0;
  for (int i = 0; i < n; ++i) {
    while (j < n && umnozh < k) {
      umnozh += boxers[j] * sum;
      sum += boxers[j];
      ++j;
    }
    minR[i] = j;
    if (umnozh < k)
      minR[i] = n + 1;
    // cerr << i << " " << j << " " << umnozh << endl;
    sum -= boxers[i];
    umnozh -= sum * boxers[i];
  }
  for (int i = 0; i < n; ++i) {
    br += (n - minR[i]) + 1;
  }
  cout << br << endl;
  return 0;
}