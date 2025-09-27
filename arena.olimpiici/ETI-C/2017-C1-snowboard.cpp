// 0
#include <algorithm>
#include <iostream>
#if 1
#define eprintf(args...) fprintf(stderr, args)
#else
#define eprintf(args...)
#endif
using namespace std;

using num = unsigned long long;
using idx_t = int;

const int MAXN = 2e2 + 1;
const int MAXM = 2e2 + 1;
const int MAX_FLAGS = MAXM + MAXN;

const num MOD = 1LL << 62;

num dp[MAXN][MAXM][MAX_FLAGS];
bool calculated[MAXN][MAXM][MAX_FLAGS];

int columns, rows, flags;

bool isOutOfBounds(idx_t x, idx_t y) {
  return x < 0 || y < 0 || x >= columns || y >= rows;
}

num DP(idx_t x, idx_t y, int flags) {
  flags;
  if (x == columns - 1 && y == rows - 1 && flags == 1)
    return 1;
  if (isOutOfBounds(x, y))
    return 0;
  if (flags <= 0)
    return 0;
  if (calculated[x][y][flags])
    return dp[x][y][flags];
  --flags;
  num sum = 0;
  sum += DP(x + 1, y, flags);
  sum += DP(x - 1, y + 1, flags);
  sum += DP(x, y + 1, flags);
  sum += DP(x + 1, y + 1, flags);
  return dp[x][y][flags + 1] = sum;
}

void Read() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> columns >> rows >> flags;
}

int main() {
  Read();

  for (int x = 0; x < rows; ++x)
    for (int y = 0; y < rows; ++y)

      cout << DP(0, 0, flags) << endl;
  return 0;
}
