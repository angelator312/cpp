#include <algorithm>
#include <iostream>
#include <set>
#define endl "\n"
using namespace std;
const int N = 1e5 + 1;
int a[N];
int b[N];
int imali[N];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
    a[i] = n - b[i];
    int br = 0;
    for (int j = a[i] + 1; j <= n; ++j) {
      br += !imali[j];
    }
    bool bl = true;
    cerr << i << " " << br << " " << a[i] << endl;
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
    cerr << i << " " << br << " " << a[i] << endl;
    imali[a[i]] = 1;
  }
  for (int i = 0; i < n; ++i) {
    cout << a[i] << " ";
  }
  cout << endl;
}