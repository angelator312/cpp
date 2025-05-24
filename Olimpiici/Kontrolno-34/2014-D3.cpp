#include <iostream>
using namespace std;
const int N = 200;
const int M = 200;
const int GOLEMINA = N * M;
bool hrasti[N][M];
bool used[N][M];
int br_s_golemina[GOLEMINA];
int n, m;
int distI[] = {1, -1, 0, 0};
int distJ[] = {0, 0, 1, -1};
void read() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> hrasti[i][j];
    }
  }
}
int rekursia(int i, int j) {
  if (used[i][j] ||hrasti[i][j])
    return 0;
//   cerr << "in: " << i << " " << j << endl;
  used[i][j] = true;
  int sum = 0;
  for (int p = 0; p < 4; ++p) {
    int nI = i + distI[p];
    int nJ = j + distJ[p];
    if (!(nI > -1 && nJ > -1 and nI < n && nJ < m))
      continue;
    sum += rekursia(nI, nJ);
  }
  ++sum;
//   cerr << "out: " << i << " " << j<<" "<<sum << endl;
  return sum;
}
void init() {
  read();
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int a = rekursia(i, j);
      if (a > 0)
        ++br_s_golemina[a];
    }
  }
}
int main() {
  init();
  int poslGolemina = 0, broi = 0;
  for (int i = 1; i < GOLEMINA; ++i) {
    if (br_s_golemina[i] > 0) {
      poslGolemina = i;
      broi = br_s_golemina[i];
    }
  }
  cout << poslGolemina << " " << broi << endl;
  return 0;
}
/*
6 7
0 0 1 0 0 0 1
1 0 1 1 1 1 1
0 1 1 0 1 0 1
1 0 0 1 0 1 1
0 1 1 0 1 0 1
1 0 1 0 0 1 1
*/