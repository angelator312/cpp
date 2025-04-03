#include <iostream>
#include <vector>
#define proverka()                                                             \
  min_distance = min(min_distance, abs(xIndexes[ptr_x] - yIndexes[ptr_y]))
using namespace std;
int n, x, y;
vector<int> xIndexes, yIndexes;
int main() {
  cin >> n >> x >> y;
  for (int i = 0, e; i < n; ++i) {
    cin >> e;
    if (e == x)
      xIndexes.push_back(i);
    if (e == y)
      yIndexes.push_back(i);
  }
  int min_distance = n;
  int xBr = xIndexes.size();
  int yBr = yIndexes.size();
  int ptr_x = 0, ptr_y = 0;
  while (ptr_x < xBr && ptr_y < yBr) {
    if (xIndexes[ptr_x] <= yIndexes[ptr_y]) {
      proverka();
      ++ptr_x;
    } else {
      proverka();
      ++ptr_y;
    }
  }
  cout << min_distance << endl;
}