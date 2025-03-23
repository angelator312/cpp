#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
LL n, br = 0;
int k = 0;

int fillBr(const LL &doI, const LL &stepen10) {
  cerr << doI << " " << stepen10 << endl;
  if (doI < 10) {
    return doI >= k;
  } else if (doI - stepen10 == 0) {
    return fillBr(doI - 1, stepen10 / 10) + 1 == k;
  } else if (doI % stepen10 == 0) {
    return fillBr(doI - 1, stepen10) + doI / stepen10 == k;
  } else if (doI / stepen10 == k) {
    LL ch = doI % stepen10;
    return fillBr(k * stepen10, stepen10) + fillBr(ch, stepen10 / 10) + ch;
  } else {
    LL ch = doI % stepen10;
    return fillBr(doI - ch, stepen10) + fillBr(ch, stepen10 / 10);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> k >> n;
  LL stepen10 = 1 ;
  LL n2 = n;
  while (n2 > 1) {
    stepen10 *= 10;
    n2 /= 10;
    cerr<<n2<<" "<<stepen10<<"\n";
  }
  stepen10/=10;

  br = fillBr(n, stepen10);

  cout << br << endl;
  return 0;
}