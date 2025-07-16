#include <iostream>
using namespace std;
const int A=1e5;
int dp[A];
int rec(int t) {
  if (t < 0)
    return 0;
  if (t == 0)
    return 1;
  if (dp[t])
    return dp[t];
  for (int i = 1; i <= 6; ++i)
    dp[t] += rec(t - i);
  return dp[t];
}
int main() {
  int n;
  cin >> n;
  cout << rec(n) << endl;
}
