#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using pIB = pair<int, bool>;
const int N = 1e5 + 2; // Lupi pravilo
pIB a[N];
// vector<pIB> greshki;

int main() {
  int greshkiBroi = 0;
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].first;
    if (a[i].first < a[i - 1].first) {
      // cerr << i << endl;
      a[i].second = 1;
      ++greshkiBroi;
    }
  }
  char z;
  int j = 0;
  for (int broiNeshto = 0; broiNeshto < m; broiNeshto++) {
    cin >> z;
    if (z == '!') {
      cin >> j >> a[j].first;
      if (a[j].first < a[j - 1].first) {
        // cerr << j << endl;
        a[j].second = 1;
        a[j - 1].second = 1;
        ++greshkiBroi;
      }
      if (j != n && a[j + 1].first < a[j].first) {
        // cerr << j << endl;
        ++greshkiBroi;
        a[j].second = 1;
        a[j + 1].second = 1;
      }
      if (a[j].second) {
        // cerr << "a[" << j - 1 << "].second: " << a[j - 1].second
        //      << " first: " << a[j - 1].first << endl;
        if (a[j - 1].second && a[j].first >= a[j - 1].first) {
          // cerr << j << endl;
          --greshkiBroi;
          a[j].second = 0;
          a[j - 1].second = 0;
        }
        // cerr << "a[" << j + 1 << "].second: " << a[j + 1].second
        //      << " first: " << a[j + 1].first << endl;
        if (j != n && a[j + 1].second && a[j + 1].first >= a[j].first) {
          // cerr << j << endl;
          --greshkiBroi;
          a[j].second = 0;
          a[j + 1].second = 0;
        }
      }
      // cerr << greshkiBroi << endl;

    } else if (z == '?') {
      if (greshkiBroi == 0) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    }
  }
  return 0;
}