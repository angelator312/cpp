#include <iostream>
#include <queue>
using namespace std;
using pI = pair<int, int>;
const int N = 1e4 + 2;
const int M = N;
char matrix[N][M];
int n, m;
pI st, nd;
int breadth[N][M];
int cnt[N][M];
queue<pI> q;
int dir[][2] = {
    {0, 1},
    {1, 0},
    {0, -1},
    {-1, 0},
};
inline void init() {
  ios_base::sync_with_stdio();
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> matrix[i][j];
      if (matrix[i][j] == 'S')
        st = {i, j};
      if (matrix[i][j] == 'T')
        nd = {i, j};
    }
  }
}
void bfs() {
  breadth[st.first][st.second] = 1;
  q.push(st);
  while (!q.empty()) {
    pI v = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      pI u = v;
      u.first += dir[i][0];
      u.second += dir[i][1];
      if (!(u.first < n && u.second < m and u.first >= 0 && u.second >= 0))
        continue;
      if (matrix[u.first][u.second] == 'x')
        continue;
      int cnt2 = cnt[v.first][v.second] + (int)(matrix[u.first][u.second] == '+');
      if (breadth[u.first][u.second]) {
        if (breadth[u.first][u.second] == breadth[v.first][v.second] + 1) {
          cnt[u.first][u.second] = max(cnt2, cnt[u.first][u.second]);
        }
        continue;
      }
      // cerr<<u.first<<" "<<u.second<<endl;
      // cerr << cnt2 << endl;
      q.push(u);
      breadth[u.first][u.second] = breadth[v.first][v.second] + 1;
      cnt[u.first][u.second] = cnt2;
    }
  }
}
int main() {
  init();
  bfs();
  cout << breadth[nd.first][nd.second] - 1 << " " << cnt[nd.first][nd.second]
       << endl;
}

/*
10 8
. x . . . . . .
. . . . x . . .
. . . x . S . .
. x x . x . . .
. . . . . x x .
. . x x . . . .
. . . x x . . x
. F . x . x . x
. . x . . x . .
. . . . . . . .

*/
