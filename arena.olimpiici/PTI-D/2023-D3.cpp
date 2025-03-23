#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
using namespace std;
using LL=long long;
using pI=pair<int,int>;
const LL MOD = 1e9 + 7;
const int N = 1e5 + 2;
int redica[N];
LL otg = 0;
int cnt[N];
vector<int> vdM;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, m, n2 = 0, a;
  cin >> n >> m;
  for (int i = m; i <=n; i+=m)
  {
    vdM.push_back(i);
  }
  
  for (int i = 0; i < n; ++i) {
    cin >> a;
    if (a % m == 0) {
      for (auto x : vdM) {
        if (__gcd(x, a) == m)
          otg += cnt[x];
      }
      for (int j = 0; j < n2; ++j) {
        ++cnt[__gcd(redica[j], a)];
      }

      redica[n2] = a;
      ++n2;
    }
  }
  cout << otg%MOD << endl;
  return 0;
}