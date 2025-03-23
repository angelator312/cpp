#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using pI = pair<int, int>;
const int N = 1e5 + 2;
const int A = 1e5 + 2;
vector<int> ch[A];
int a[N];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    ch[a[i]].push_back(i);
  }
  int q;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    int e;
    cin >> e;
    int ind = e - 1;
    e = a[ind];

    int posl = -1;
    int n = ch[e].size();
    for (int j = 0; j < n; ++j) {
      if (ind == ch[e][j]) {
        cout << posl + 1 << " ";
        if (j + 1 == n)
          cout << 0;
        else
          cout << ch[e][j + 1] + 1;
        cout << endl;
      }
      posl = ch[e][j];
    }
  }
  return 0;
}

/*
8
2 4 5 4 4 2 7 4
3
1 8 4
*/