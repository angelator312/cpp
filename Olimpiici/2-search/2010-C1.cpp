#include <algorithm>
#include <iostream>
#define endl "\n"
using namespace std;
using LL = unsigned long long;
const int N = 1e5 + 2;
int k, n, s, min_popcorn;
int redica[N];
inline bool ok(int x) {
  bool redica2[N]{};
  int i = 0, j = 0, sum = 0;
  //cerr << "x = " << x << endl;
  for (int p = 0; p < k; ++p) {
    sum = 0;
    j=i;
    for (;j < n;++j) {
      if(redica2[j])continue;
      sum += redica[j];
      if (sum > x) {
        sum -= redica[j];
      }else redica2[j]=1;
      
    }
    //cerr << "  " << i << " " << j << endl;
    while(i<n&&redica2[i])++i;
    if (i == n)
      break;
  }
  for(int i=0;i<n;++i)if(!redica2[i])return false;
  return true;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n >> k ;
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    cin >> redica[i];
    sum += redica[i];
  }
  sort(redica, redica + n,greater<int>());
  int l = redica[0], r = sum, ans = 0;
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
