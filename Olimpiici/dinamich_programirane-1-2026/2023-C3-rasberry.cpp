#include <climits>
#include <cstdio>
#include <iostream>
#if 1
#define eprintf(args...) fprintf(stderr, args)
#else
#define eprintf(args...)
#endif
using namespace std;
// ₳₦₲ɆⱠ₳₮ØⱤ312 𝕨𝕒𝕤 hêrê

using num = long long;
using idx_t = int;

const idx_t MAX_X = 1e3;
const idx_t MAX_Y = 1e3;

bool calclulated[MAX_X][MAX_Y];
num matrix[MAX_X][MAX_Y];
num opt[MAX_X][MAX_Y];
num dp[MAX_X][MAX_Y];
int maxX, maxY;

inline void Read() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> maxY >> maxX;
  for (idx_t y = 0; y < maxY; ++y)
    for (idx_t x = 0; x < maxX; ++x)
      cin >> matrix[x][y];
}
inline int GetMaxPleasure(const int &x, const int &y) {
  return (x < maxX || y < maxY) ? opt[x][y] : 0;
}

inline num DP(const num x, const num y) {
  opt[x][y] = max(GetMaxPleasure(x + 1, y), GetMaxPleasure(x, y + 1));
  dp[x][y] = opt[x][y] + matrix[x][y];
  opt[x][y] = max(opt[x][y], dp[x][y]);
  return dp[x][y];
}

int main() {
  Read();
  num sum = 0;
  for (idx_t y = maxY - 1; y >= 0; --y) {
    for (idx_t x = maxX - 1; x >= 0; --x) {
      sum += DP(x, y);
    }
  }
  printf("%lld\n", sum);
  return 0;
}
