#include <iostream>
#include <vector>
using namespace std;
const int N = 100l;
vector<int> edges[N];
int depth[N];
void dfs(const int &edge, const int &nom) {
  depth[edge] = nom;
  for (int e : edges[edge]) {
    if (!depth[e])
      dfs(e, nom + 1);
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0, a, b; i < m; ++i) {
    cin >> a >> b;
    if (a > b)
      swap(a, b);
    edges[a].push_back(b);
  }
  dfs(0, 0);
  int q;
  for (int i = 0; i < n; ++i)
    cerr<<i<<" "<<depth[i]<<endl;
  cin >> q;

  for (int i = 0, a, b; i < q; ++i) {
    cin >> a >> b;
    cout <<( (depth[b] > depth[a] )? "YES!" : "NO!") << endl;
  }
}