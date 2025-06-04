#include <iostream>
#include <queue>
#include <vector>
using namespace std;
using pB = pair<int, bool>;
int n, m, q, nowNom = 0;
const int N = 15e3 + 2;
vector<pB> edges[N];
int visited[N];
void ReadFirst() {
  cin >> n >> m;
  for (int i = 0, e, e2; i < m; ++i) {
    cin >> e >> e2;
    edges[e].push_back({e2, true});
    edges[e2].push_back({e, true});
  }
}
bool bfs(int st, int end) {
  queue<int> q;
  if (st == end)
    return true;
  q.push(st);
  // cerr << "in:" << start << endl;a
  while (!q.empty()) {
    int start = q.front();
    q.pop();
    visited[start] = nowNom;
    for (auto &[e,e2] : edges[start]) {
      if (visited[e] < nowNom and e2) {
        if (e == end)
          return true;
        q.push(e);
      }
    }
  }
  // cerr << "out:" << start << endl;
  return false;
}
void block(int x, int y) {
  // for (pB &e : edges[x]) {
  //   if (e.first == y) {
  //     e.second = false;
  //     return;
  //   }
  // }
  // edges[x].push_back({y, false});
  // edges[y].push_back({x, false});
}
// void unblock(int x, int y) {
//   for (pB &e : edges[x]) {
//     if (e.first == y) {
//       e.second = true;
//       return;
//     }
//   }
//   edges[x].push_back({y, true});
// }
int main() {
  ReadFirst();
  cin >> q;
  int t;
  for (int i = 0, x, y; i < q; ++i) {
    // cerr << i << " " << t << endl;
    cin >> t >> x >> y;
    if (t == 1) {
      ++nowNom;
      cout << int(bfs(x, y));
    } else if (t == 2) {
      // block(x, y);
    } else {
      // unblock(x, y);
    }
  }
  cout << endl;
  return 0;
}