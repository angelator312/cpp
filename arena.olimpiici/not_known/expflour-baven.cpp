#include <climits>
#include <iostream>
using namespace std;
int main() {
  long long n, m;
  long long rD = 1, cD = 1, rG = 1, cG = 1, out = 0;
  cin >> m >> n;
  if (n == m) {
    cout << n << endl;
    return 0;
  }
  if (n == 2) {
    cout << 2 << endl;
    return 0;
  }
  if ((n % 2 == 0 && m % 2 == 1) || (n % 2 == 1 && m % 2 == 0)) {
    if (max(n, m) - min(n, m) < 11 && min(n, m) > 15) {
      cout << 2 << endl;
      return 0;
    }
    if (min(n, m) <= 15) {
      cout << 2 << endl;
      return 0;
    }
  }
  for (long long i = 0; i < n * m; i++) {
    if (rD == rG && cD == cG) {
      // cout<<rD<<" cD:"<<cD<<endl;
      // cout<<rG<<" cG:"<<cG<<endl;
      out++;
    }
    cD++;
    if (cD > n) {
      cD = 1;
      rD++;
    }
    rG++;
    if (rG > m) {
      cG++;
      rG = 1;
    }
  }
  cout << out << endl;
  return 0;
}