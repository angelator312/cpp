#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
using LL = long long;
using pI = pair<int, int>;
const int N = 1e7 + 2;
// bool eratosten[N];
int min_div[N];
int power(int x, int y) {
  if (y == 0)
    return 1;
  if (y % 2 == 0) {
    int z = pow(x, y / 2);
    return z * z;
  } else
    return x * pow(x, y - 1);
}
void eratostenFill() {
  min_div[0] = 1;
  min_div[1] = 1;
  for (int j = 2; j <= N; j += 2) {
    min_div[j] = 2;
  }
  for (int i = 3; i <= N; i += 2) {
    if (min_div[i] > 0)
      continue;
    for (int j = i; j <= N; j += i) {
      if (min_div[j] == 0)
        min_div[j] = i;
    }
  }
}
int main() {
  eratostenFill();
  int n, q, a, b;
  cin >> n >> q;
  for (int i = 0; i < q; ++i) {
    cin >> a >> b;
    vector<int> v;
    while (a > 1) {
      v.push_back(min_div[a]);
      a /= min_div[a];
    }
    while (b > 1) {
      v.push_back(min_div[b]);
      b /= min_div[b];
    }
    sort(v.begin(), v.end());
    int last = 1;
    int lastBr = 0;
    int ans = 1;
    for (auto x : v) {
      if (last != x) {
        ans *= power(last, floor(lastBr / 2));
        lastBr = 0;
      }
      ++lastBr;
      last = x;
    }

    ans *= power(last, floor(lastBr / 2));
    // cerr<<endl<<a<<" "<<b<<endl;
    cout << ans << " ";
  }
  cout << endl;
  return 0;
}