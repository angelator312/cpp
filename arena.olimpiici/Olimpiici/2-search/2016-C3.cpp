#include <algorithm>
#include <iostream>
#define endl "\n"
#define int LL
using namespace std;
using LL = long long;
const int N = 1e5 + 2;
int k, n, min_boiadisvane;
int redica[N];
inline bool ok(int x) {
  int broiZadni = -10;
  for (int i = 0; i < n; ++i) {
    broiZadni = max(broiZadni, redica[i] - x * (1 + i));
  }
  // cerr << x << " " << broiZadni << endl;

  if (x * n <= k - abs(broiZadni))
    return true;
  return false;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    cin >> redica[i];
  }
  sort(redica, redica + n);
  LL l = 1, r = redica[0], ans = 0;
  while (l <= r) {
    LL mid = l + (r - l) / 2;
    if (ok(mid)) {
      ans = mid;
      l = mid + 1;
    } else
      r = mid - 1;
  }
  cout << ans << endl;
  return 0;
}
/*
1
5
4 3 3 4 4
*/
