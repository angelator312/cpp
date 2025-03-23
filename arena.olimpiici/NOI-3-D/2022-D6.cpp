#include <iostream>
#define isOk                                                                   \
  matrix[i - 1][j] > 0 && matrix[i + 1][j] > 0 && matrix[i][j + 1] > 0 &&      \
      matrix[i][j - 1] > 0
using namespace std;
using LL = long long;
const int N = 502;
const int M = 502;
int matrix[N][M];
int plusI[] = {0, 0, 1, -1};
int plusJ[] = {1, -1, 0, 0};
int n, m, br = 0;

void init() {
  for (int i = 0; i <= n; ++i) {
    matrix[i][0] = -1;
    matrix[i][m + 1] = -1;
  }
  for (int i = 0; i <= m; ++i) {
    matrix[0][i] = -1;
    matrix[n + 1][i] = -1;
  }
}

//-----------------------------------------------------

bool isUsable0(int i, int j, int otk) {
  if (matrix[i][j] != 0)
    return false;
  int br = 0;
  // cerr << i << " " << j << endl;
  matrix[i][j] = 6;
  if (otk != 1)
    if (matrix[i - 1][j] > 0)
      ++br;
    else {
      if (matrix[i - 1][j] == 0)
        br += isUsable0(i - 1, j, 2);
    }
  if (otk != 2)
    if (matrix[i + 1][j] > 0)
      ++br;
    else {
      if (matrix[i + 1][j] == 0)
        br += isUsable0(i + 1, j, 1);
    }
  if (otk != 3)
    if (matrix[i][j - 1] > 0)
      ++br;
    else {
      if (matrix[i][j - 1] == 0)
        br += isUsable0(i, j - 1, 4);
    }
  if (otk != 4)
    if (matrix[i][j + 1] > 0)
      ++br;
    else {
      if (matrix[i][j + 1] == 0)
        br += isUsable0(i, j + 1, 3);
    }
  if (br == 4 - (otk > 0) && (isOk)) {
    matrix[i][j] = 5;
    return true;
  }
  matrix[i][j] = -1;
  return false;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);
  ///////cerr.tie(nullptr);
  cin >> n >> m;
  init();
  int pSum = 0, Litce = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> matrix[i][j];
      pSum += matrix[i][j];
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (matrix[i][j] > 0)
        ++Litce;
      else {
        if (isUsable0(i, j, -1)) {
          ++Litce;
          matrix[i][j] = 5;
        } else {
          matrix[i][j] = -1;
        }
      }
    }
  }
  cout << Litce << endl;
  // cout<<1<<endl;
  cout << pSum << endl;
  cout << 1 << endl;
  cout << 1 << endl;
  //*
  //        if(useMiasto(i,j,-1,-1))++br;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (matrix[i][j] < 0)
        cerr << matrix[i][j] << " ";
      else
        cerr << "*" << matrix[i][j] << " ";
    }
    cerr << endl;
  }
  //*/
  // cout<<br<<endl;
}

/*
6 7
0 0 0 0 0 0 0
0 3 2 2 0 0 0
0 0 0 1 2 0 0
0 0 3 1 0 3 0
0 0 0 0 3 0 0
0 0 0 0 0 0 0
otg=10\n20\n10\n6\n
*/