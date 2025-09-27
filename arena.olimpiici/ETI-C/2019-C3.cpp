#include <algorithm>
#include <cstdio>
#include <iostream>
#if 1
#define eprintf(args...) fprintf(stderr, args)
#else
#define eprintf(args...)
#endif
using namespace std;

using num = int;
using idx_t = int;

const int MAX_ROW_SIZE = 1e5 + 1;
const int MAX_MOVES_SIZE = 1e5 + 1;

num rowSize, movesSize;

int row[MAX_ROW_SIZE];
int moves[MAX_MOVES_SIZE];
bool usedMoves[MAX_MOVES_SIZE];
void Read() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> rowSize >> movesSize;
  for (idx_t i = 0; i < rowSize; ++i)
    cin >> row[i];
  for (idx_t i = 0; i < movesSize; ++i)
    cin >> moves[i];
}

inline int MaxRightDP(int idx) {
  if (idx < 0)
    return 0;
  if (idx >= rowSize - 1)
    return 0;
  num maxPrevious = -10;
  for (int i = 0; i < movesSize; ++i) {
    maxPrevious = max(maxPrevious, MaxRightDP(idx - moves[i]));
  }
  if(maxPrevious==-10)
  {

  }
  return maxPrevious + row[idx];
}
inline int MaxLeftDP(int idx, bool usedMoves[]) {
  if (idx <= 0)
    return 0;
  num maxPrevious = 0;
  for (int i = 0; i < movesSize; ++i) {
    if (!usedMoves[i]) {
      usedMoves[i] = true;
      maxPrevious = max(maxPrevious, MaxLeftDP(idx - moves[i], usedMoves));
      usedMoves[i] = false;
    }
  }
  return maxPrevious + row[idx];
}

int main() {
  Read();
  num maxLeftDP = MaxRightDP(0);
  eprintf("Max Left DP:%d\n", maxLeftDP);
  num maxRightDP = MaxLeftDP(rowSize - 1, usedMoves) + row[0];
  eprintf("Max Right DP:%d\n", maxRightDP);
  printf("%d\n", max(maxLeftDP, maxRightDP));
  return 0;
}

/*
9 2
3 2 6 6 0 2 4 5 5
3 2

6 2
1 4 7 2 5 1
3 4
*/
