#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int A = 1e6 + 2;

int n, m, k;
int m2;
vector<int> points;
vector<int> koshari;
vector<int> used;
// int redica[A];

inline int my_lower_bound(const int &sz, const int &val) {
  int l = 0, r = sz, ans = sz, mid;
  while (l <= r) {
    mid = (l + r) / 2;
    if (koshari[mid] >= val) {
      ans = mid;
      r = mid - 1;
    } else
      l = mid + 1;
  }
  return ans;
}
inline bool ok(int time) {
  for (int j = 0; j < m; ++j)
    for (int i = 0; i < n; ++i) {
      if (points[i]<koshari[j])
      {
        if(koshari[j]-points[i])
        {
          
        }
      }
    }
}
int main() {
  cin >> n >> m >> k;
  points.resize(n);
  for (int i = 0; i < n; ++i) {
    cin >> points[i];
    // ++redica[e];
  }
  for (int i = 0, e; i < m; ++i) {
    cin >> koshari[i];
    int j = my_lower_bound()
    // redica[e] -= k;
  }
  if (n > m * k) {
    cout << -1 << endl;
    return 0;
  }
  sort(points.begin(), points.end());
  sort(koshari.begin(), koshari.end());
  int l = 0, r = 1e5, ans = 1e5, mid = 0;
  while (l <= r) {
    mid = (l + r) / 2;
    if (ok(mid)) {
      ans = mid;
      r = mid - 1;
    } else
      l = mid + 1;
  }
  cout << mnTime << endl;
}