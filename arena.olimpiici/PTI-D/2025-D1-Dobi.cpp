#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
using LL = long long;
const int A = 1e6 + 2;
LL delitels[A];
vector<int> primes;
int cnt[A];
int lp[A];
void LineenErat(const int &mx) {
  for (int i = 2; i < mx; ++i) {
    if (lp[i] == 0) {
      lp[i] = i;
      cnt[i] = 1;
      primes.push_back(i);
    }
    for (int j = 0;
         j < primes.size() && primes[j] <= lp[i] && i * primes[j] <= mx; ++j) {
      lp[i * primes[j]] = primes[j];
      if (cnt[primes[j] * i] == 0)
        cnt[primes[j] * i] = cnt[i] + 1;
    }
  }
}
inline void init(const int &mx) {
  LineenErat(mx);
  for (int i = 0; i < n; ++i) {
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  init();
  /*
  for(int i=2;i<1000;++i)
  {
      cerr<<i<<":"<<delitels[i]<<endl;
  }
  */
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    cout << delitels[b] - delitels[a - 1] << endl;
  }
}

/*
1
1 10
*/