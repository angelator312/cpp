#include <iostream>
#include <queue>
#include <vector>
using namespace std;
using pI = pair<int, int>;
const int N = 250;
const int M = 250;
char matrix[N][M];
int breadth[N][M];
int n, m;
pI st_pos, end_pos;
vector<pI> last_water_blocks;
vector<pI> new_water_blocks;
queue<pI> q;
int distI[] = {1, -1, 0, 0};
int distJ[] = {0, 0, 1, -1};

void read() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> matrix[i][j];
      if (matrix[i][j] == '*')
        last_water_blocks.push_back({i, j});
      else if (matrix[i][j] == 'S') {
        matrix[i][j] = '.';
        st_pos = {i, j};
      } else if (matrix[i][j] == 'D')
        end_pos = {i, j};
    }
  }
}
void new_layer_water() {
//   cerr << "new layer\n";
  for (auto [i, j] : last_water_blocks) {
    for (int p = 0; p < 4; ++p) {
      int nI = i + distI[p], nJ = j + distJ[p];
      if (!(nI > -1 && nJ > -1 and nI < n && nJ < m))
        continue;
      if (matrix[nI][nJ] != '.')
        continue;
      matrix[nI][nJ] = '*';
      breadth[nI][nJ] = -1;
      new_water_blocks.push_back({nI, nJ});
    }
  }
  swap(new_water_blocks, last_water_blocks);
  new_water_blocks.clear();
}

int main() {
  read();
  int last_time = 1;
  q.push(st_pos);
  breadth[st_pos.first][st_pos.second] = 1;
  while (!q.empty()) {
    pI u = q.front();
    q.pop();
    // cerr << "in:" << u.first << " " << u.second << endl;
    if (breadth[u.first][u.second] > last_time)
      new_layer_water();
    last_time = breadth[u.first][u.second];
    for (int p = 0; p < 4; ++p) {
      int nI = u.first + distI[p];
      int nJ = u.second + distJ[p];
      if (!(nI > -1 && nJ > -1 and nI < n && nJ < m))
        continue;

      if (matrix[nI][nJ] == '*' || matrix[nI][nJ] == 'X')
        continue;
      if (breadth[nI][nJ] > 0)
        continue;
      breadth[nI][nJ] = breadth[u.first][u.second] + 1;
      q.push({nI, nJ});
    }
  }
  //   for (int i = 0; i < n; ++i) {
  //     for (int j = 0; j < m; ++j) {
  //       cerr << breadth[i][j] << " ";
  //     }
  //     cerr << endl;
  //   }
  int out = breadth[end_pos.first][end_pos.second] - 1;
  if(out>0)
  cout << out<< endl;
  else 
  cout<<"Impossible\n";
  return 0;
}