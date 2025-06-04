#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;
const int N = 1e4;
int n, m, components = 0;
int broi_edges[N + 2];
int component[N + 2];
int componentN[N + 2];
vector<int> edges[N + 2];
void dfs(const int &st) {
  for (auto e : edges[st]) {
    if (component[e] == 0) {
      component[e] = component[st];
      dfs(e);
    }
  }
}
int main() {
  cin >> n >> m;
  for (int i = 0, a, b; i < m; ++i) {
    cin >> a >> b;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }
  int n2 = 0;
  for (int i = 1; i <= n; ++i) {
    if (component[i] == 0) {
      component[i] = ++components;
      dfs(i);
    }
  }
  for (int i = 1; i <= n; ++i) {
    broi_edges[i] = edges[i].size();
    componentN[component[i]] += (broi_edges[i] > 0);
  }

  for (int i = 0; i < n; ++i) {
    if (broi_edges[i] > 0 && broi_edges[i] != componentN[component[i]] - 1) {
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";
  return 0;
}
