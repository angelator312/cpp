#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;
using LL=long long;
queue<LL> v;
int main() {
  LL a, b;
  cin >> a >> b;
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    LL e;
    cin >> e;
    v.push(e);
    // cerr << endl;
  }
  //   cerr << endl;
  LL pos = a;
  LL br = 0;
  while (pos < b) {
    while (!v.empty() && v.front() < pos) {
      v.pop();
    }
    if (v.front() == pos + 2) {
      ++pos;
      ++br;
    } else {
      pos += 2;
      ++br;
    }
  }
  cout << br << endl;
}