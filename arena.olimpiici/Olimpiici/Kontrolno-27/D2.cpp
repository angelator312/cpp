#include <algorithm>
#include <iostream>
#include <vector>
#define krai()                                                                 \
  out_points[points[i].second] = 0;                                            \
  continue
using namespace std;
using pI = pair<int, int>;
const int N = 3e5 + 2;
const int Q = N;
int n, q;
vector<pI> points;
vector<pI> intervalsLeft;
vector<pI> intervalsRight;

int out_points[N];
int out_intervals[Q];

inline void read() {
  cin >> n >> q;
  points.resize(n);
  intervalsLeft.resize(q);
  intervalsRight.resize(q);
  for (int i = 0; i < n; ++i)
    cin >> points[i].first;
  for (int i = 0; i < q; ++i)
    cin >> intervalsLeft[i].first;
  for (int i = 0; i < q; ++i)
    cin >> intervalsRight[i].first;
  for (int i = 0; i < n; ++i) {
    points[i].second = i;
  }
  for (int i = 0; i < q; ++i) {
    intervalsLeft[i].second = i;
    intervalsRight[i].second = i;
  }

  sort(intervalsLeft.begin(), intervalsLeft.end());
  sort(intervalsRight.begin(), intervalsRight.end());
  sort(points.begin(), points.end());
}
// Function is used to get the index of lower bound
// @param where the vector of pairs
// @param sz the vector's size
// @param search_val value for search in first of pairs
inline int my_lower_bound(const vector<pI> &where, const int &sz,
                          const int &search_val) {
  int ans = sz, l = 0, r = sz, mid;
  while (l <= r) {
    mid = (l + r) / 2;
    if (where[mid].first >= search_val) {
      ans = mid;
      r = mid - 1;
    } else
      l = mid + 1;
  }
  return ans;
}
inline int my_upper_bound(const vector<pI> &where, const int &sz,
                          const int &search_val) {
  int ans = sz, l = 0, r = sz, mid;
  while (l <= r) {
    mid = (l + r) / 2;
    if (where[mid].first > search_val) {
      ans = mid;
      r = mid - 1;
    } else
      l = mid + 1;
  }
  return ans;
}
// ----------------------------------------------------------------
inline int my_ravno_bound(const vector<int> &where, const int &sz,
                          const int &search_val) {
  int ans = -1, l = 0, r = sz, mid;
  while (l <= r) {
    mid = (l + r) / 2;
    if (where[mid] >= search_val) {
      ans = mid;
      r = mid - 1;
    } else
      l = mid + 1;
  }
  if (where[ans] != search_val)
    return -1;
  return ans;
}
// ----------------------------------------------------------------
inline int my_lower2_bound(const vector<pI> &where, const int &sz,
                           const int &search_val) {
  int ans = sz, l = 0, r = sz, mid;
  while (l <= r) {
    mid = (l + r) / 2;
    if (where[mid].first <= search_val) {
      ans = mid;
      r = mid - 1;
    } else
      l = mid + 1;
  }
  return ans;
}
int main() {
  read();
  for (int i = 0; i < n; ++i) {
    int fs1 = my_lower2_bound(intervalsLeft, q, points[i].first);
    int sc1 = my_upper_bound(intervalsLeft, q, points[i].first);
    if(fs1>sc1)
    {
        krai();
    }

    vector<int> maybeIntervals;
    for (int j = fs1; j < sc1; ++j) {
      maybeIntervals.push_back(intervalsLeft[j].second);
    }
    sort(maybeIntervals.begin(), maybeIntervals.end());
    int fs2 = my_lower_bound(intervalsRight, q, points[i].first);
    int sc2 = q; // my_upper_bound(intervalsRight, q, points[i].first);
    int br = 0;
    // cerr << points[i].second << ":" << fs1 << " " << sc1 << endl;
    // cerr << points[i].second << ":" << fs2 << " " << sc2 << endl;
    if (sc1 ==fs1) {
      krai();
    }
    for (int j = fs2; j < sc2; ++j) {
      int rv =
          my_ravno_bound(maybeIntervals, sc1 - fs1, intervalsRight[j].second);
      //   if (points[i].second == 1) {
      //     cerr << rv << " " << j << " " << intervalsRight[j].second << endl;
      //   }
      br += (rv > -1);
    }

    out_points[points[i].second] = br;
  }
  // intervals
  for (int i = 0; i < q; ++i) {
    int fs = my_lower_bound(points, n, intervalsLeft[i].first);
    out_intervals[intervalsLeft[i].second] = fs;
  }
  for (int i = 0; i < q; ++i) {
    int sc = my_upper_bound(points, n, intervalsRight[i].first);
    // cerr << intervalsLeft[i].second << " "
    //      << out_intervals[intervalsRight[i].second] << " " << sc << endl;
    out_intervals[intervalsRight[i].second] =
        sc - out_intervals[intervalsRight[i].second];
  }
  // print points
  for (int i = 0; i < n; ++i) {
    cout << out_points[i] << " ";
  }
  cout << endl;

  // print intervals
  for (int i = 0; i < q; ++i) {
    cout << out_intervals[i] << " ";
  }
  cout << endl;
}