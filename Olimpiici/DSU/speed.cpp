#include <algorithm>
#include <cstdio>
#include <iostream>
#include <utility>
#if 1
#define eprintf(args...) fprintf(stderr, args)
#else
#define eprintf(args...)
#endif
using namespace std;

using num = int;
using idx_t = int;

const int MAX_POPULATED_AREAS = 1e5;

num countOfPopulatedAreas, countOfPaths;
enum TypeOfRequest {
  Adding,
  Asking,
};

struct Info {
  int maxSpeed;
  int minSpeed;
  void AddInfo(const Info &newInfo) {
    maxSpeed = max(maxSpeed, newInfo.maxSpeed);
    minSpeed = min(minSpeed, newInfo.minSpeed);
  }
};

struct DSU {
  int parent[MAX_POPULATED_AREAS];
  int size[MAX_POPULATED_AREAS];
  Info moreInfo[MAX_POPULATED_AREAS];

  void Init(int countOFPopulatedAreas) {
    for (idx_t i = 0; i < countOFPopulatedAreas;)
      parent[i] = ++i;
  }

  int Find(int i) {
    // if (parent[i] == i)
    //   return i;
    return (parent[i] == i) ? i : parent[i] = Find(parent[i]);
  }

  void Union(int i, int j, Info info) {
    i = Find(i);
    j = Find(j);
    if (i == j)
      return;
    size[i] = size[i] ? size[i] : 1;
    size[j] = size[j] ? size[j] : 1;
    if (size[i] < size[j])
      swap(i, j);

    if (moreInfo[i].minSpeed == 0 && moreInfo[j].minSpeed == 0) {
      moreInfo[i] = moreInfo[j] = info;
    } else if (moreInfo[i].minSpeed == 0)
      moreInfo[i] = info;
    else if (moreInfo[j].minSpeed == 0)
      moreInfo[j] = info;

    moreInfo[i].AddInfo(moreInfo[j]);
    moreInfo[i].AddInfo(info);
    eprintf("[%d][%d]new info:{%d,%d}\n", i, j, moreInfo[i].minSpeed,
            moreInfo[i].maxSpeed);
    size[i] += size[j];
    parent[j] = i;
  }
};

DSU dsu;

void SolveRequest(int x, int y, int optimalSpeed) {
  // eprintf("[%d][%d]isAdding:%d\n", x, y, type == TypeOfRequest::Adding);
  dsu.Union(x, y, {optimalSpeed, optimalSpeed});
}
void Read() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> countOfPopulatedAreas >> countOfPaths;
  dsu.Init(countOfPopulatedAreas);
}

int main() {
  Read();
  for (int i = 0, x, y, optSpeed; i < countOfPaths; ++i) {
    cin >> x >> y >> optSpeed;

    SolveRequest(x, y, optSpeed);
  }
  return 0;
}
