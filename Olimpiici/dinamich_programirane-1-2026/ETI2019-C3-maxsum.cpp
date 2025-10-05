#include <algorithm>
#include <cstdio>
#include <iostream>
#if 0
#define eprintf(args...) fprintf(stderr, args)
#else
#define eprintf(args...)
#endif
// ₳₦₲ɆⱠ₳₮ØⱤ312 𝕨𝕒𝕤 hêrê
using namespace std;

using num = int;
using idx_t = int;

const int MAX_SIZE = 1e5 + 1;
const int MAX_HODOVE = 1e3 + 1;
const int MIN_INT = -1e9;

num prefixToRight[MAX_SIZE];
num dpToRight[MAX_SIZE];
num sufixToLeft[MAX_SIZE];
num dpToLeft[MAX_SIZE];
num hodove[MAX_SIZE];
num chisla[MAX_SIZE];
bool jumpedOn[MAX_SIZE];
bool jumpedOn2[MAX_SIZE];

idx_t sizeNow, hodoveSize;

void Read() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> sizeNow >> hodoveSize;
  for (idx_t i = 0; i < sizeNow; ++i)
    cin >> chisla[i];
  for (idx_t i = 0; i < hodoveSize; ++i)
    cin >> hodove[i];
}

int main() {
  Read();
  fill(dpToLeft, dpToLeft + sizeNow, MIN_INT);
  fill(dpToRight, dpToRight + sizeNow, MIN_INT);
  dpToRight[0] = chisla[0];
  jumpedOn[0] = true;
  for (int i = 0; i < sizeNow - 1; ++i) {
    if (!jumpedOn[i])
      continue;
    for (int j = 0; j < hodoveSize; ++j) {
      num newPos = hodove[j] + i;
      if (newPos < sizeNow - 1) {
        jumpedOn[newPos] = true;
        dpToRight[newPos] =
            max(dpToRight[i] + chisla[newPos], dpToRight[newPos]);
      }
    }
  }

  for (int i = 0; i < sizeNow; ++i)
    eprintf("%d ", dpToRight[i]);
  eprintf("\n");

  prefixToRight[0] = dpToRight[0];
  for (int i = 1; i < sizeNow; ++i)
    prefixToRight[i] = max(prefixToRight[i - 1], dpToRight[i]);

  dpToLeft[sizeNow - 1] = chisla[sizeNow - 1];
  jumpedOn2[sizeNow - 1] = true;
  for (int i = sizeNow - 1; i >= 0; --i) {
    if (!jumpedOn2[i])
      continue;
    for (int j = 0; j < hodoveSize; ++j) {
      num newPos = i - hodove[j];
      if (newPos >= 0) {
        jumpedOn2[newPos] = true;
        dpToLeft[newPos] = max(dpToLeft[i] + chisla[newPos], dpToLeft[newPos]);
      }
    }
  }
  for (int i = 0; i < sizeNow; ++i)
    eprintf("%d ", dpToLeft[i]);
  eprintf("\n");

  sufixToLeft[sizeNow - 1] = dpToLeft[sizeNow - 1];
  for (int i = sizeNow - 2; i >= 0; --i)
    sufixToLeft[i] = max(sufixToLeft[i + 1], dpToLeft[i]);

  int mx = MIN_INT;
  for (int i = 0; i < sizeNow - 1; ++i)
    mx = max(mx, prefixToRight[i] + sufixToLeft[i + 1]);
  printf("%d\n", mx);
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
