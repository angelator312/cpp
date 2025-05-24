#include <iostream>
using namespace std;
int n, m;
const int N = 100;
const int M = 100;
bool zemia[N][M];
int plusI[] = {0, 0, 1, 1, 1, -1, -1, -1};
int plusJ[] = {1, -1, 0, 1, -1, 0, 1, -1};
inline bool dfs(const int &i, const int &j) {
  if (!zemia[i][j])
    return false;
  zemia[i][j] = false;
  for (int p = 0; p < 8; ++p) {
    int nI = plusI[p] + i;
    int nJ = plusJ[p] + j;
    dfs(nI, nJ);
  }
  return true;
}
void Read() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> zemia[i][j];
    }
  }
  ++m;
  fill_n(zemia[0] + 0, m, false);
  fill_n(zemia[n + 1] + 0, m, false);
  for (int i = 0; i <= n + 1; ++i) {
    zemia[i][0] = false;
    zemia[i][m] = false;
  }
  --m;
}
int main() {
  Read();
  for (int j = 0; j <= m + 1; ++j) {
    dfs(1, j);
    dfs(n, j);
  }
  for (int i = 0; i <= n + 1; ++i) {
    dfs(i, 1);
    dfs(i, m);
  }
  // for (int i = 0; i <= n + 1; ++i) {
  //   for (int j = 0; j <= m + 1; ++j) {
  //     cerr << zemia[i][j];
  //   }
  //   cerr << endl;
  // }
  int br = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      br += dfs(i, j);
    }
  }
  cout << br << endl;
  return 0;
}