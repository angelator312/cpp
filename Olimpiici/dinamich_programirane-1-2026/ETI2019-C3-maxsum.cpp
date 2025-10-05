// 32
#include <algorithm>
#include <cstdio>
#include <iostream>

#if 0
#define eprintf(args...)
#else
#define eprintf(args...) fprintf(stderr, args)
#endif

using namespace std;
using num = int;
using idx_t = int;

using namespace std;

const int MAX_SIZE = 1e5 + 1;
const int MAX_HODOVE = 1e3 + 1;
const int MIN_INT = -2002;

num bestLeftToI[MAX_SIZE];
bool calculatedLeft[MAX_SIZE];
num bestRightToI[MAX_SIZE];
bool calculatedRight[MAX_SIZE];
num chisla[MAX_SIZE];
idx_t hodove[MAX_SIZE];

idx_t sizeNow;
idx_t hodoveSize;

num DPLeft(idx_t idx) {
  if (idx < 0)
    return MIN_INT;
  if (calculatedLeft[idx])
    return bestLeftToI[idx];
  num mx = 0;
  for (idx_t i = 0; i < hodoveSize; ++i)
    mx = max(mx, DPLeft(idx - hodove[i]) + chisla[idx]);
  calculatedLeft[idx] = 1;
  return bestLeftToI[idx] = max(mx, DPLeft(idx - 1));
}

num DPRight(idx_t idx) {
  if (idx >= sizeNow)
    return MIN_INT;
  if (calculatedRight[idx])
    return bestRightToI[idx];
  num mx = 0;
  for (idx_t i = 0; i < hodoveSize; ++i)
    mx = max(mx, DPRight(idx + hodove[i]) + chisla[idx]);
  calculatedRight[idx] = true;
  return bestRightToI[idx] = max(mx, DPRight(idx + 1));
}

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
  calculatedLeft[0] = 1;
  bestLeftToI[0] = chisla[0];
  calculatedRight[sizeNow - 1] = 1;
  bestRightToI[sizeNow - 1] = chisla[sizeNow - 1];
  for (idx_t i = 0; i < sizeNow; ++i)
    eprintf("%d ", DPLeft(i));
  eprintf("\n");
  for (idx_t i = 0; i < sizeNow; ++i)
    eprintf("%d ", DPRight(i));
  eprintf("\n");
  int mx = 0;
  for (idx_t i = 0; i <= sizeNow - 2; ++i)
    mx = max(mx, DPLeft(i) + DPRight(i + 1));
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
