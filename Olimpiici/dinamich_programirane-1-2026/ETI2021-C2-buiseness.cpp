#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#if 1
#define eprintf(args...) fprintf(stderr, args)
#else
#define eprintf(args...)
#endif
// ₳₦₲ɆⱠ₳₮ØⱤ312 𝕨𝕒𝕤 hêrê
using namespace std;
const int MAX_X = 5e5 + 1;
const int MAX_K = 101;
using num = int;
using big_num = long long;
using idx_t = int;

const big_num INF = 1e18;

idx_t maxX, k;
num chisla[MAX_X];

void Read() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> maxX >> k;
  for (idx_t x = 1; x <= maxX; ++x)
    cin >> chisla[x];
}

int main() {
  Read();
  vector<big_num> old_dp(k + 1, INF);
  old_dp[0] = 0;
  for (idx_t i = 1; i <= maxX; ++i) {
    vector<big_num> new_dp(k + 1, INF);
    for (idx_t j = 0; j <= k; ++j) {
      if (j > 0)
        new_dp[j] = min(new_dp[j],
                        old_dp[j - 1] + (j % 2 == 0 ? chisla[i] : -chisla[i]));
      new_dp[j] =
          min(new_dp[j], old_dp[j] + (j % 2 == 0 ? chisla[i] : -chisla[i]));
    }
    old_dp = new_dp;
  }
  big_num mn = INF;
  for (idx_t j = 0; j <= k; ++j)
    mn = min(mn, old_dp[j]);
  printf("%lld\n", mn);
  return 0;
}
