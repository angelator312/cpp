#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;
using LL = unsigned long long;
using pI = pair<LL, int>;
const int N = 52;
const int Q = 1e5 + 2;
const LL X = 1e18;
int n, q, br = 0;
int zaiavki[Q];
LL sum = 0, x;
LL b[N], ans = 0;
void read() {
  cin >> n >> q;
  LL e;
  b[0] = 1;
  for (int i = 1; i <= n; ++i) {
    cin >> e;
    b[i] = e;
    b[i] *= b[i - 1];
  }
}
LL tmp = 1;
LL pow2(int x) {
  if (x == 0)
    return 1;
  if (x % 2 == 0) {
    tmp = pow2(x / 2);
    return tmp * tmp;
  }
  return pow2(x - 1) << 1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(nullptr);
  cin.tie(nullptr);
  read();
  // cerr << pow2(5) << endl;
  for (int j = 0; j < q; ++j) {
    cin >> x;
    ans = 0;
    for (int i = n; i > 0; --i) {
      if (x < b[i])
        continue;
      x -= b[i];
      ans += pow2(i - 1);
    }
    cout<<ans+1<< " ";
  }

  return 0;
}
/*
2 1
10 10
100
1,2,1+2,0
otg=4
*/