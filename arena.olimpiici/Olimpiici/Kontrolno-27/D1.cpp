#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using pI = pair<int, int>;
const int N = 3e5 + 2;
const int A = 1e5 + 2, Q = N;
int out_intervals[Q];
int out_points[N];
vector<pI> points;
vector<pI> intervalsLeft;
vector<pI> intervalsRight;
inline int my_upper_bound(const vector<pI> &v, const int &sz, const int &val) {
  int l = 0, r = sz, ans = sz, mid;
  while (l <= r) {
    mid = (l + r) / 2;
    if (v[mid].first > val) {
      ans = mid;
      r = mid - 1;
    } else
      l = mid + 1;
  }

  return ans;
}
inline int my_lower_bound(const vector<pI> &v, const int &sz, const int &val) {
  int l = 0, r = sz, ans = sz, mid;
  while (l <= r) {
    mid = (l + r) / 2;
    if (v[mid].first >= val) {
      ans = mid;
      r = mid - 1;
    } else
      l = mid + 1;
  }

  return ans;
}
int main() {
  int n, q, max_number = 0;
  cin >> n;
  points.resize(n);
  for (int i = 0, e; i < n; ++i) {
    cin >> e;
    points[i] = {e, i};
  }
  cin >> q;
  intervalsLeft.resize(q);
  intervalsRight.resize(q);
  for (int i = 0, e; i < q; ++i) {
    cin >> e;
    intervalsLeft[i] = {e, i};
    cin >> e;
    intervalsRight[i] = {e, i};
  }
  sort(points.begin(), points.end());
  sort(intervalsLeft.begin(), intervalsLeft.end());
  sort(intervalsRight.begin(), intervalsRight.end());
  for (int i = 0; i < q; ++i) {
    int lwr = my_lower_bound(points, n, intervalsLeft[i].first);
    out_intervals[intervalsLeft[i].second] = -lwr;
  }
  for (int i = 0; i < q; ++i) {
    int upp = my_upper_bound(points, n, intervalsRight[i].first);
    out_intervals[intervalsRight[i].second] += upp;
  }

  for (int i = 0; i < q; ++i)
    cout << out_intervals[i] << "\n";
  return 0;
}