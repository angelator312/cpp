// 0
#include <iostream>
using namespace std;

using num = unsigned long long;
using idx_t = int;

const int MAXN = 2e2 + 1;
const int MAXM = 2e2 + 1;
const num MOD = 1LL << 62;

num dp[MAXN][MAXM];

int columns, rows, flags;

bool isOutOfBounds(idx_t x, idx_t y) {
  return x < 0 || y < 0 || x >= columns || y >= rows;
}

num DP(idx_t x, idx_t y, int flags) {
  if (x == columns - 1 && y == rows - 1 && flags == 0)
    return 1;
  if (x == columns - 1 && y == rows - 1 && flags > 0)
    return 0;
  if (flags == 0)
    return 0;
  if (isOutOfBounds(x, y))
    return 0;
  --flags;
  num sum = DP(x + 1, y, flags);
  sum = (sum + DP(x, y, flags)) % MOD;
  if (x == columns - 1 && y == rows - 1)
    cerr << sum << endl;
  sum = (sum + DP(x + 1, y + 1, flags)) % MOD;
  sum = (sum + DP(x - 1, y + 1, flags)) % MOD;
  return sum;
}

void Read() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> columns >> rows >> flags;
}

int main() {
  Read();
  for (idx_t y = 0; y < rows; ++y) {
    for (idx_t x = 0; x < columns; ++x)
      cerr << DP(x, y, flags) << " ";
    cerr << "\n";
  }
  cout << DP(columns - 1, rows - 1, 2) << endl;
  return 0;
}
