#include <algorithm>
#include <iostream>
#include <set>
using namespace std;

const int N = 1e5 + 1;

int n;
int a[N];
set<pair<int, int>> dp;

int f(int idx) {
  int mx = 0;
  auto end = dp.lower_bound(make_pair(a[idx], 0));
  // cerr << "end " << end->first << endl;
  for (auto e = dp.begin(); e != end; ++e) {
    // cerr << a[idx] << " [" << e->first << "," << e->second << "]\n";
    mx = max(e->second, mx);
  }
  dp.insert({a[idx], mx + 1});
  return mx + 1;
}

int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  int mx = 0;
  for (int i = 0; i < n; ++i) {
    mx = max(f(i), mx);
  }
  cout << mx << endl;
  return 0;
}
