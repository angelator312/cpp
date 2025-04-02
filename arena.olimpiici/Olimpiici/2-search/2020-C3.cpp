#include <algorithm>
#include <iostream>
#define endl "\n"
using namespace std;
using LL = unsigned long long;
const int N = 1e5 + 2;
int k, n, s, min_popcorn;
int redica[N];
inline bool ok(int x) {
  int i = 0, j = 0, sum = 0;
  //cerr << "x = " << x << endl;
  for (int p = 0; p < k; ++p) {
    sum = 0;
    while (j < n) {
      sum += redica[j];
      if ((sum + s - 1) / s > x) {
        sum -= redica[j];
        break;
      }
      ++j;
    }
    if (j == n)
      break;
    //cerr << "  " << i << " " << j << endl;
    i = j;
  }
  return (j == n);
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n >> k >> s;
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    cin >> redica[i];
    min_popcorn = min(redica[i], min_popcorn);
    sum += redica[i];
  }
  int l = 1, r = sum, ans = 0;
  while (l <= r) {
    int mid = l + (r - l) / 2;
    if (ok(mid)) {
      ans = mid;
      r = mid - 1;
    } else
      l = mid + 1;
  }
  cout << ans << endl;
  return 0;
}
/*
1
5
4 3 3 4 4
*/
