#include <algorithm>
#include <iostream>
#define endl "\n"
using namespace std;
using LL = long long;
const int N = 1e5 + 2;
int n,k;
int redica[N];
inline bool ok(LL time) {
  LL disks = 0;
  for (int i = 0; i < n && disks < k; ++i) {
    disks += time / redica[i];
  }
  return disks >= k;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> k >> n;
  for (int i = 0; i < n; ++i) {
    cin >> redica[i];
  }
  LL l = 1, r = 1e10, ans = 0;
  while (l <= r) {
    LL mid = (r + l) / 2;
    if (ok(mid)) {
      ans = mid;
      r = mid - 1;
    } else
      l = mid + 1;
  }
  cout<<ans<<endl;
  return 0;
}
/*
1
5
4 3 3 4 4
*/
