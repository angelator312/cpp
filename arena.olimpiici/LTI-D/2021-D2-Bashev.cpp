#include <iostream>
#include <queue>
using namespace std;

const int N = 1003;

int n, m;
pair<int, int> s, t;
char a[N][N];
int dist[N][N];
int cnt[N][N];

int dir[4][2] = {{+1, 0}, {-1, 0}, {0, +1}, {0, -1}};

void bfs() {
  queue<pair<int, int>> q;
  dist[s.first][s.second] = 1;
  q.push(s);
  while (!q.empty()) {
    pair<int, int> v = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      pair<int, int> u = v;
      u.first += dir[i][0];
      u.second += dir[i][1];
      if (!(u.first <= n && u.second <= m and u.first > 0 && u.second > 0) ||
          a[u.first][u.second] == 'x')
        continue;
      if (dist[u.first][u.second] == 0 ||
          (dist[v.first][v.second] + 1 == dist[u.first][u.second] &&
           cnt[v.first][v.second] > cnt[u.first][u.second])) {
        dist[u.first][u.second] = dist[v.first][v.second] + 1;
        if (dist[u.first])
          q.push(u);
      }
    }
  }
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
      if (a[i][j] == 'S')
        s = {i, j};
      if (a[i][j] == 'T')
        t = {i, j};
    }
  }
  bfs();
  cout << dist[t.first][t.second] - 1 << ' ' << 0 << endl;

  return 0;
}