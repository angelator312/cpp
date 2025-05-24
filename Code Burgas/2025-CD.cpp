#include <array>
#include <iostream>
#include <vector>
using namespace std;
using LL = long long;
using pI = pair<int, int>;
vector<pI> minati;
const int N = 1e4;
vector<vector<int>> visited;
int minatiSZ = 0;
int nn, n;
array<int, 2> divs[8] = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1},
                         {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};
inline void dfs(const int &i, const int &j) {
  visited[i][j] = true;
  ++minatiSZ;
  minati.push_back({i,j});
  if (minatiSZ == nn) {
    // TODO:Print
    for(auto e:minati)
    {
      cout<<e.first<<" "<<e.second<<endl;
    }
    exit(0);
  }
  for (int p = 0; p < 8; ++p) {
    int nI = i + divs[p][0];
    int nJ = j + divs[p][1];
    if (!(nI >= 0 && nJ >= 0 and nI < n && nJ < n))
      continue;
    if (visited[nI][nJ])continue;
    dfs(nI,nJ);
  }
  minati.pop_back();
  --minatiSZ;
  visited[i][j] = false;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n;
  visited.resize(n);
  for (int i = 0; i < n; ++i)
    visited[i].resize(n);
    
  nn = n * n;
  int i, j;
  cin >> j >>i;
  dfs(i, j);
  cout << "NO SOLUTION\n";
  return 0;
}