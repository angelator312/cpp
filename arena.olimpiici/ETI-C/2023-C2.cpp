#include <iostream>
using namespace std;
using num = int;

const int MAX_TREE_COUNT = 2e5 + 2;

int trees[MAX_TREE_COUNT];
num treeCount;

inline num GetSignOfNum(num a) { return a == 0 ? 0 : (a < 0 ? -1 : 1); }

inline void Read() noexcept {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> treeCount;
  for (int i = 0; i < treeCount; ++i)
    cin >> trees[i];
}

int main() {
  Read();
  num minimalTreeHumidityBelowZero = 0;
  num minActions = 0;

  while (true) {
    num i = 0;

    while (i < treeCount && trees[i] == 0)
      ++i;

    if (i == treeCount)
      break;

    num startInd = i;
    num signOfFirstTree = GetSignOfNum(trees[i]);
    num minHumidity = trees[i];

    while (i < treeCount && GetSignOfNum(trees[i]) == signOfFirstTree) {
      minHumidity = min(minHumidity, trees[i]);
      ++i;
    }
    // cerr << startInd << " " << i << " min:" << minHumidity
    //      << " sign:" << signOfFirstTree << endl;
    for (; startInd < i; ++startInd)
      trees[startInd] -= minHumidity;

    minActions += abs(minHumidity);
  }

  cout << minActions << endl;
  return 0;
}
