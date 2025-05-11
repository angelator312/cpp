#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int N = 1001;
const int M = N;
using pI = pair<int, int>;
int n, m, startI, startJ;
int endI, endJ, k;
int plusI[] = {0, 0, 1, -1};
int plusJ[] = {1, -1, 0, 0};
char matrix[N][M];
vector<pI> edges[N][M];
queue<pI> q;
// bool visited[N][M];
int dist[N][M];
inline void read() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j)
      cin >> matrix[i][j];
  }
}
inline void init() {
  read();
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (matrix[i][j] == 'S') {
        startI = i;
        startJ = j;
      }
      if (matrix[i][j] == 'T') {
        endI = i;
        endJ = j;
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      for (int p = 0; p < 4; ++p) {
        int nI = i + plusI[p];
        int nJ = j + plusJ[p];
        if ((0 <= nI && nI < n) && (0 <= nJ && nJ < m)) {
          if (matrix[nI][nJ] == 'x')
            continue;
          edges[i][j].push_back({nI, nJ});
        }
      }
    }
  }
}
void bfs(const int i, const int j) {
  // visited[i][j] = true;
  dist[i][j] = 0;
  q.push({i, j});
  while (!q.empty()) {
    pI s = q.front();
    q.pop();
    // process node s
    for (pI e : edges[s.first][s.second]) {
      if (visited[e.first][e.second])
        continue;
      // visited[e.first][e.second] = true;
      dist[e.first][e.second] = dist[s.first][s.second] + 1;
      if(e.first)
      // cerr << e.first << " " << e.second<<" "<<dist[e.first][e.second] <<
      // endl;
      q.push(e);
    }
  }
}
int main() {
  init();
  bfs(startI, startJ);
  cout << dist[endI][endJ]-1 << " " << k << endl;
  return 0;
}