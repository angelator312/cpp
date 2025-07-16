#include <iostream>
using namespace std;
const int A = 1e5;
int dp[A];
int main() {
  int n;
  cin >> n;
  for (int x = 1; x <= n; ++x) {
    int l = max(1, x - 6);
    int r = x - 1;
    for (int i = 1; i <= 6; ++i)
      dp[x] += dp[x - i];
  }
  cout << dp[n] << endl;
}
