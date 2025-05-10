#include <iostream>
using namespace std;
using LL = long long;
int n;
int main() {
  cin >> n;
  LL mazh, br = 1, i, e;
  cin >> mazh;
  for (i = 1; i < n; ++i) {
    cin >> e;
    if (e == mazh)
      ++br;
    else
      --br;
    if (br == 0)
      mazh = e;
  }
  br = 0;
  for (i = 0; i < n; ++i) {
    cin >> e;
    if (e == mazh)
      ++br;
  }
  // cerr << mazh << endl;
  cout << min((n - br) * 2, n - 1LL) << endl;
  return 0;
}