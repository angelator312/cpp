#include <iostream>
#include <sys/types.h>
#if 1
#define eprintf(args...) fprintf(stderr, args)
#else
#define eprintf(args...)
#endif
// ₳₦₲ɆⱠ₳₮ØⱤ312 𝕨𝕒𝕤 hêrê
using namespace std;

using num = long long;
using idx_t = int;

const int MAX_X = 201;
const int MAX_Y = 201;
const long long MOD = 1LL << 62;

idx_t maxX, maxY, flags;
num memoization[MAX_X][MAX_Y];

inline void Read() noexcept {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> maxY >> maxX >> flags;
}

inline num DP(const num x, const num y, idx_t flags) noexcept {
  if (x < 0 || y < 0)
    return 0;
  if (flags == 1 && x == maxX - 1 && y == maxY - 1)
    return 1;
  if (x >= maxX || y >= maxY) {
    return 0;
  }
  eprintf("x:%lld;y:%lld;flags:%d\n", x, y, flags);
  num chances = 0;
  --flags;
  chances = (chances + DP(x, y + 1, flags)) % MOD;
  chances = (chances + DP(x + 1, y + 1, flags)) & MOD;
  chances = (chances + DP(x + 1, y, flags)) % MOD;
  return chances;
}

int main() {
  Read();
  cout << DP(0, 0, flags) << endl;
  return 0;
}
