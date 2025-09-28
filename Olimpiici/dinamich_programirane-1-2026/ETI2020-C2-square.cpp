#include <algorithm>
#include <cstdio>
#include <iostream>
#if 1
#define eprintf(args...) fprintf(stderr, args)
#else
#define eprintf(args...)
#endif
// ₳₦₲ɆⱠ₳₮ØⱤ312 𝕨𝕒𝕤 hêrê
using namespace std;

using num = int;
using idx_t = int;

const num MAX_X = 3e3 + 1;
const num MAX_Y = 3e3 + 1;
const num INF = 1e5;

num maxX, maxY;
bool matrix[MAX_X][MAX_Y];
num pref[4][MAX_X][MAX_Y];

inline void Read() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> maxY >> maxX;
  string s;
  for (idx_t y = 0; y < maxY; ++y) {
    cin >> s;
    for (idx_t x = 0; x < maxX; ++x)
      matrix[x][y] = s[x] - '0';
  }
}

inline bool IsInBounds(const idx_t x, const idx_t y) {
  return (x >= 0 && y >= 0 && x < maxX && y < maxY);
}

inline void Set(const int x, const int y, const int x2, const int y2,
                const int n) {
  if (matrix[x][y])
    pref[n][x][y] = (IsInBounds(x2, y2) ? pref[n][x2][y2] : 0) + 1;
  else
    pref[n][x][y] = 0;
}

inline num GetMaxSquare(const idx_t centerX, const idx_t centerY) {
  num mn = INF;
  for (idx_t i = 0; i < 4; ++i)
    mn = min(mn, pref[i][centerX][centerY]);
  return mn * 2 - 1;
}

inline void printPrefAt(const idx_t x, const idx_t y, const idx_t z) {
  eprintf("%d ", pref[z][x][y]);
}

int main() {
  Read();
  for (idx_t y = 0; y < maxY; ++y)
    for (idx_t x = 0; x < maxX; ++x)
      Set(x, y, x - 1, y - 1, 0);

  for (idx_t y = maxY - 1; y >= 0; --y)
    for (idx_t x = 0; x < maxX; ++x)
      Set(x, y, x - 1, y + 1, 1);

  for (idx_t y = 0; y < maxY; ++y)
    for (idx_t x = maxX - 1; x >= 0; --x)
      Set(x, y, x + 1, y - 1, 2);

  for (idx_t y = maxY - 1; y >= 0; --y)
    for (idx_t x = maxX - 1; x >= 0; --x)
      Set(x, y, x + 1, y + 1, 3);


  int mx = 0;
  for (idx_t y = 0; y < maxY; ++y)
    for (idx_t x = 0; x < maxX; ++x)
      mx = max(mx, GetMaxSquare(x, y));

  printf("%d\n", mx);
  return 0;
}
