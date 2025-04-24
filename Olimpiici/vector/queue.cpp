#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, q;
  vector<int> a;
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    int e;
    cin >> e;
    a.push_back(e);
  }
  int plusPos = -1;
  for (int i = 0; i < q; i++) {
    int e;
    cin >> e;
    if (e == 1)
      plusPos++;
    else if (e == 3) {
      int b;
      cin >> b;
      cout << a.at(b + plusPos) << endl;
    } else {
      int b;
      cin >> b;
      a.push_back(b);
    }
  }
  return 0;
}
