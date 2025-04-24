#include <cmath>
#include <iostream>
using namespace std;
using LL = long long;
const int A = 1e6 + 2;
LL delitels[A];
inline int logi2(int a) {
  int br = 0;
  while (a % 2 == 0) {
    a /= 2;
    ++br;
  }
  return br;
}
inline int logx(int a, const int &osn) {
  int br = 0;
  while (a % osn == 0) {
    a /= osn;
    ++br;
  }
  return br;
}
inline void eratosten() {
  delitels[0] = delitels[1] = 0;
  LL stepen = -1, sledv = 2;
  for (int i = 2; i <= A; i += 2) {
    delitels[i] += logi2(i);
  }
  for (int j = 3; j <= A; j += 2) {
    if (delitels[j])
      continue;
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