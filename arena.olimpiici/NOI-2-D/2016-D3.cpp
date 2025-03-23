#include <algorithm>
#include <climits>
#include <iostream>
#include <stack>
#include <vector>
#define jOk nJ < m &&nJ >= 0
#define iOk nI < n &&nI >= 0
using namespace std;
const int N = 2e2 + 2;
const int M = 2e2 + 2;
bool used[N][M];
int br = 0;
int n, m;
int plusI[] = {0, 0, -1, 1};
int plusJ[] = {-1, 1, 0, 0};

void drawOn(int i, int j) {
  if (used[i][j])
    return;
  used[i][j] = true;
  for (int p = 0; p < 4; ++p) {
    int nI = plusI[p] + i;
    int nJ = plusJ[p] + j;
    if((jOk)&&(iOk))
      drawOn(nI, nJ);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(nullptr);
  cin.tie(nullptr);
  cin >> n >> m;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
      cin >> used[i][j];
    }

  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
      if (!used[i][j]) {
        ++br;
        drawOn(i, j);
      }
    }
  cout << br << endl;
}

/*

2 4
0 1 1 0
0 0 1 1

*/