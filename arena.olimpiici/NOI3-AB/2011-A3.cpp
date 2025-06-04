#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
using pI = pair<int, int>;
const int N = 1e3 + 2;
const int M = 1e4 + 2;
vector<pI> edges[N];
vector<int> out;
int vzeti[N];
int sz_edges[N];
int n, m, radiation = 0;

void Read() {
  cin >> n >> m;
  for (int i = 0, e, e2, e3; i < m; ++i) {
    cin >> e >> e2 >> e3;
    edges[e2].push_back({e, e3});
    ++sz_edges[e];
    cerr << e << "++\n";
  }
}
void dfs(const int &i) {
  if (vzeti[i])
    return;
  // cerr << "in:" << i << endl;
  out.push_back(i);
  vzeti[i] = true;
  sort(edges[i].begin(), edges[i].end());
  for (pI e : edges[i]) {
    dfs(e.first);
  }
  // cerr << "out:" << i << endl;
}
int main() {
  Read();
  for (int i = 1; i <= n; ++i)
    if (sz_edges[i] == 0) {
      dfs(i);
    }

  int outSz = out.size();
  cout << (radiation == 0 ? -1 : radiation) << endl;
  if (outSz == n) {
    for (int e : out) {
      cout << e << " ";
    }
    cout << endl;
  }
  return 0;
}