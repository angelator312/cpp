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
int main() {
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    LL e, e2;
    cin >> e >> e2;
    LL sum = 0;
    for (LL j = e; j <= e2; j++) {
      //   LL e = ch(j);
      //   sum += e;
      sum += ch(j);
      //   cerr << j << ":" << e << endl;
    }
    cout << sum << endl;
  }
  return 0;
}
/*

*/