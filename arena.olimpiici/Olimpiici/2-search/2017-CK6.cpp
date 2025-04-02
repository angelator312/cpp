#include <algorithm>
#include <iostream>
#define endl "\n"
using namespace std;
using LL = __int128_t;
using LLORg = long long;
const int N = 1e5 + 2;
LLORg A, K, B, M, X;
LL a, k, b, m, x;
int redica[N];
inline bool ok(LL time) {
  return ((time - time / k) * a) + ((time - time / m) * b) >= x;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> A >> K >> B >> M >> X;
  a = A;
  k = K;
  b = B;
  m = M;
  x = X;
  LL l = 1, r = 2e18, ans = 0;
  while (l <= r) {
    LL mid = l + (r - l) / 2;
    if (ok(mid)) {
      ans = mid;
      r = mid - 1;
    } else
      l = mid + 1;
  }
  cout << (long long)ans << endl;
  return 0;
}
/*
1
5
4 3 3 4 4
*/
