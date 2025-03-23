#include <algorithm>
#include <iostream>
#include <set>
#define endl "\n"
using namespace std;
const int N = 1e5 + 1;
int a[N];
int b[N];
int imali[N];
set<int, greater<int>> st;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
    a[i] = n - b[i];
    int br = i == 0 ? b[i] : 0;
    int m = n;
    for (auto e : st) {
      // cerr << e<<" "<<a[i] << endl;
      if (e <= a[i]) {
        break;
      }
      br += m - e;
      m = e - 1;
    }
    br += m - a[i];

    // cerr << i << " " << br << endl;
    // cerr << i << " " << br << " " << a[i] << endl;
    while (imali[a[i]] || b[i] > br) {
      while (imali[a[i]]) {
        br += !imali[a[i]];
        --a[i];
      }
      while (b[i] > br) {
        br += !imali[a[i]];
        --a[i];
      }
    }
    // cerr << i << " " << br << endl;
    // cerr << i << " " << br << " " << a[i] << endl;
    st.insert(a[i]);
    imali[a[i]] = 1;
  }
  for (int i = 0; i < n; ++i) {
    cout << a[i] << " ";
  }
  cout << endl;
}