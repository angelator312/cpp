#include <iostream>

using namespace std;
using LL = long long;

const int K = 1e5 + 1;
const LL TIME = 1e10 + 2;

int n, k;
int a[K];

bool ok(LL t) {
  LL out = 0;
  for (int i = 0; i < k; ++i) {
    out += t / a[i];
  }
  return out >= n;
}

int main() {
  cin >> n >> k;
  for (int i = 0; i < k; ++i) {
    cin >> a[i];
  }
  LL l = 0, r = TIME, ans = -1;
  while (l <= r) {
    LL m = l + (r - l) / 2;
    if (ok(m)) {
      ans = m;
      r = m - 1;
    } else
      l = m + 1;
  }
  cout << ans << endl;
  return 0;
}
