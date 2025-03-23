#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
const int N = 201;
vector<short> v[N];
int ptr_left[N];
int n;
short maxV() {
  short mn = 1e3, iG = 0;
  for (int i = 0; i < n; ++i) {
    int e = v[i][ptr_left[i]];
    if (ptr_left[i] < n && e < mn) {
      iG = i;
      mn = e;
    }
  }

  ++ptr_left[iG];
  return mn;
}
int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      int e;
      cin >> e;
      v[i].push_back(e);
    }
    sort(v[i].begin(), v[i].end(), greater<int>());
    // for (auto e : v[i]) {
    //   cerr << e << " ";
    // }
    // cerr << endl;
  }
  //   cerr << endl;
  bool bl = 0;
  int ogn = 0, ros = 0;
  int e = maxV();
  while (e < 1e3) {
    // cerr << e << " " << bl << endl;
    if (bl)
      ogn += e;
    else
      ros += e;
    bl = !bl;
    e = maxV();
  }
  cout << ogn << " " << ros << endl;
}