#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
LL ch(LL a) {
  a = a % 9;
  if (a == 0)
    return 9;
  else
    return a;
}
int doCh2(int a) { return (1 + a) * a / 2; }
LL doCh(LL a) { return ((int)(a / 9)) * 45 + doCh2(a % 9); }
int main() {
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    LL e, e2;
    cin >> e >> e2;
    e2 -= e;
    e %= 9;
    e2 += e;
    // cerr << e << " " << e2 << endl;
    LL sum = 0;
    sum = doCh(e2);
    // cerr << sum << endl;
    if (e == 0)
      sum += 9;
    if (e > 1)
      sum -= doCh(e - 1);

    cout << sum << endl;
  }
  return 0;
}
/*

*/