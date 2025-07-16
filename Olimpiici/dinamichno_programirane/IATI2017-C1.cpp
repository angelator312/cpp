#include <iostream>
using namespace std;
const int N = 51;
const int K = 51;
int m, n, k;
long long br = 0;
long long dp[N][N][K];
int main() {
  cin >> n >> m >> k;
  dp[0][0][1] = 1;
  for (int len = 0; len <= n; ++len)
    for (int lst = 0; lst <= m; ++lst)
      for (int krt = 0; krt <= k; ++krt) {
        if(len!=0&&lst!=0)dp[len + 1][lst][krt + 1] += dp[len][lst][krt];
        for (int sled = lst + 1; sled <= m; ++sled) {
          dp[len + 1][sled][1] += dp[len][lst][krt];
        }
      }
  for (int i = 1; i <= m; ++i)
    for (int j = 1; j <= k; ++j)
      br += dp[n][i][j];
  cout << br << endl;
}
