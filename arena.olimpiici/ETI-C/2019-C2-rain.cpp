//0
#include <algorithm>
#include <cstddef>
#include <cstdio>
#include <iostream>
#include <stack>
#include <vector>
#if 0
#define eprintf(args...) fprintf(stderr, args)
#else
#define eprintf(args...)
#endif
using namespace std;

using num = int;
using big_num = long long;
using idx_t = int;

const int MAX_BARRIERS = 1e6 + 1;

size_t barriersSize;

num barriersHeights[MAX_BARRIERS];
bool isAddedHeight[MAX_BARRIERS];

void Read() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> barriersSize;
  for (idx_t i = 0; i < barriersSize; ++i)
    cin >> barriersHeights[i];
  size_t heightAddings;
  cin >> heightAddings;
  num idx, plusHeight;
  for (idx_t i = 0; i < heightAddings; ++i) {
    cin >> idx >> plusHeight;
    isAddedHeight[idx] = true;
    eprintf("[%d]add height:%d\n", idx, plusHeight);
    barriersHeights[idx] += plusHeight;
  }
  eprintf("barriers:");
  for (idx_t i = 0; i < barriersSize; ++i)
    eprintf("%d ", barriersHeights[i]);
  eprintf("\n");
}
stack<int> s;

void FillStack() {
  for (int i = 0; i < barriersSize; ++i) {
    while (!s.empty() && barriersHeights[s.top()] < barriersHeights[i])
      s.pop();
    s.push(i);
  }
}

vector<int> stackElements;

big_num CalculateWaterBeforeFirstStackElement(int end) {
  num sum = 0;
  for (int i = 0; i < end; ++i) {
    sum += barriersHeights[i];
  }
  return sum;
}

void FillStackElements() {
  while (!s.empty()) {
    stackElements.push_back(s.top());
    s.pop();
  }
  reverse(stackElements.begin(), stackElements.end());
  for (int e : stackElements)
    eprintf("%d ", e);
  eprintf("\n");
}

size_t CalculateMinimalBarriers() {
  size_t minBarriers = 0;
  for (int idxOfBarrier : stackElements)
    minBarriers += isAddedHeight[idxOfBarrier];

  eprintf("minBarriers:%ld\n", minBarriers);
  return minBarriers;
}

big_num CalculateMaxWater() {
  big_num sum = CalculateWaterBeforeFirstStackElement(stackElements[0]);
  for (int i = 1; i < stackElements.size(); ++i) {
    num waterLevel = min(barriersHeights[stackElements[i - 1]],
                         barriersHeights[stackElements[i]]);
    num intervalSize = stackElements[i] - stackElements[i - 1];
    sum += intervalSize * waterLevel;
  }
  return sum;
}

int main() {
  Read();
  FillStack();
  FillStackElements();
  size_t minimalBarriers = CalculateMinimalBarriers();
  big_num maxWater = CalculateMaxWater();

  printf("%ld %lld\n", minimalBarriers, maxWater);
  return 0;
}
