#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <vector>
#define endl "\n"
#define int LL
using namespace std;
using LL = unsigned long long;
using pI = pair<int, int>;
const int N = 1e5 + 1;
int n2, n,max_gol=0;
int a[N];
inline bool check(int t) {
  if(t<max_gol) return false;
  int i=0, j=0, sum = 0;
  for (int broi = 0; broi < n2; ++broi) {
    sum = 0;
    while (j < n) {
      sum += a[j];
      if (sum > t) {
        break;
      }
      ++j;
    }
    i = j;
  }
  return j == n;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n2 >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    max_gol = max(max_gol, a[i]);
  }
  int l = max_gol, r = 1e14,ans=0;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (check(mid)) {
      ans = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  cout << ans << endl;
  return 0;
}
/*
1
5
4 3 3 4 4
*/
