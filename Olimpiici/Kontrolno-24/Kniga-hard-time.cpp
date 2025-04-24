#include <algorithm>
#include <chrono>
#include <cmath>
#include <iostream>
#include <map>
#define endl "\n"
#define int LL
using namespace std;
using LL = unsigned long long;
using pI = pair<int, int>;
const int N = 1e5 + 1;
int n2, n, max_gol = 0;
int a[N];
inline bool check1(int t) {
  if (t < max_gol)
    return false;
  int i = 0, j = 0, sum = 0;
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
inline bool check2(int t) {
  for (int i = 0; i < n; ++i) {
    if (a[i] > t) {
      return false;
    }
  }
  int i = 0, j = 0, sum = 0;
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
  auto ct = chrono::steady_clock::now();
  for (int p = 0; p < 100; ++p) {
    int l = max_gol, r = 1e14, ans = 0;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (check1(mid)) {
        ans = mid;
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
  }
  auto ct2 = chrono::steady_clock::now();
  auto duration = ct2 - ct;
  cout << "Time taken for check1: " << duration.count() << endl;
  ct = chrono::steady_clock::now();
  for (int p = 0; p < 100; ++p) {
    int l = max_gol, r = 1e14, ans = 0;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (check2(mid)) {
        ans = mid;
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
  }
  ct2 = chrono::steady_clock::now();
  duration = (ct2 - ct);
  cout << "Time taken for check2: " << duration.count() << endl;

  // cout << ans << endl;
  return 0;
}
/*
1
5
4 3 3 4 4
*/
