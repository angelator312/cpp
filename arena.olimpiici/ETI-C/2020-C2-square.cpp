//100
#include <cstdio>
#include <ios>
#include <iostream>

#if 1
#define eprintf(args...)
#else
#define eprintf(args...) fprintf(stderr, args)
#endif
using namespace std;
using num = int;
using idx_t = int;

const int MAX_X = 3e3 + 1;
const int MAX_Y = 3e3 + 1;

num maxY, maxX;
num matrix[MAX_X][MAX_Y];
num toKvadrant1[MAX_X][MAX_Y];
num toKvadrant2[MAX_X][MAX_Y];
num toKvadrant3[MAX_X][MAX_Y];
num toKvadrant4[MAX_X][MAX_Y];

inline bool isInBounds(int x, int y) {
  return x >= 0 && y >= 0 && x < maxX && y < maxY;
}

inline void Read() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> maxY >> maxX;
  for (int y = 0; y < maxY; ++y) {
    string s;
    cin >> s;
    for (int x = 0; x < maxX; ++x)
      matrix[x][y] = s[x] - '0';
  }
}

inline int minQuadrant(const int x, const int y) {
  return min(min(toKvadrant1[x][y], toKvadrant2[x][y]),
             min(toKvadrant3[x][y], toKvadrant4[x][y]));
}

inline int SizeOfSquareWithCenter(int x, int y) {
  return minQuadrant(x, y) * 2 - 1;
}

int main() {
  Read();

  for (int y = 0; y < maxY; ++y)
    for (int x = 0; x < maxX; ++x)
      if (matrix[x][y]) {
        toKvadrant4[x][y] =
            isInBounds(x - 1, y - 1) ? toKvadrant4[x - 1][y - 1] + 1 : 1;
      }

  for (int y = 0; y < maxY; ++y)
    for (int x = maxX - 1; x >= 0; --x)
      if (matrix[x][y]) {
        toKvadrant3[x][y] =
            isInBounds(x + 1, y - 1) ? toKvadrant3[x + 1][y - 1] + 1 : 1;
      }

  for (int y = maxY - 1; y >= 0; --y)
    for (int x = 0; x < maxX; ++x)
      if (matrix[x][y]) {
        toKvadrant2[x][y] =
            isInBounds(x - 1, y + 1) ? toKvadrant2[x - 1][y + 1] + 1 : 1;
      }

  for (int y = maxY - 1; y >= 0; --y)
    for (int x = maxX - 1; x >= 0; --x)
      if (matrix[x][y])
        toKvadrant1[x][y] =
            isInBounds(x + 1, y + 1) ? toKvadrant1[x + 1][y + 1] + 1 : 1;
  int maxSize = 1;
  for (int y = 0; y < maxY; ++y) {
    for (int x = 0; x < maxX; ++x) {
      // eprintf("%d ", SizeOfSquareWithCenter(x, y));
      maxSize = max(maxSize, SizeOfSquareWithCenter(x, y));
    }
    // eprintf("\n");
  }
  printf("%d\n", maxSize);
  return 0;
}
