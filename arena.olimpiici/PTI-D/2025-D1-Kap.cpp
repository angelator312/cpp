#include <cmath>
#include <iostream>
using namespace std;
using LL = long long;
const int A = 1e6 + 2;
LL delitels[A];

inline void eratosten() {
  for (int j = 2; j <= A; ++j ) {
    if (delitels[j])
    {
      if(p)
    }
    for (int i = j; i <= A; i += j) {
      delitels[i] += logx(i, j);
    }
  }
}
inline void init() {
  eratosten();
  for (int i = 1; i <= A; ++i)
    delitels[i] += delitels[i - 1];
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