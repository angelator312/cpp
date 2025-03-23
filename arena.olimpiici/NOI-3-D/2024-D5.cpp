#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
using namespace std;
int br;
vector<int> outs;
queue<int> queueMain,q;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, m;
  cin >> n >> m;
  if (m % 2 == 0) {
    cout << 0 << endl;
    return 0;
  }
  for (int i = 1; i < m; i++) {
    queueMain.push(i);
  }
  for (int i = m; i <= n + 1; i++) {
    queueMain.push(i);
    q = queueMain;

    while (1) {
      int a = q.front();
      q.pop();
      if (q.empty()) {
        // cerr << i << " " << a << endl;
        if (a == m) {
          ++br;
          outs.push_back(i-1);
        }
        break;
      } else
        q.pop();
      q.push(a);
    }
  }
  cout<<br<<endl;
  for (auto e:outs) 
  {
    cout<<e<<" ";
  }
  cout<<endl;
  return 0;
}
