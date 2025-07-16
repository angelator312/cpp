#include <iostream>
using namespace std;
const int N = 51;
int m, n, br = 0;
int dp[N][N];
inline int nachini(int dilzhina, int posl) {
  if (dp[dilzhina][posl])
    return dp[dilzhina][posl];
  if (dilzhina == n) {
    ++br;
    return 1;
  }
  int brSega = 0;
  for (int i = posl + 1; i <= m; ++i) {
    brSega += nachini(dilzhina + 1, i);
  }
  return dp[dilzhina][posl] = brSega;
}
int main() {
  cin >> m >> n;
  cout << nachini(0, 0) << endl;
}
