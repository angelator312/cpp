#include <iostream>
using namespace std;
using num = int;
using idx_t = int;
const int N = 501;
const int M = 501;

num matrix[N][M];
num dp[N][M];
bool isCalculatedDP[N][M];
num n, m;

num MaxSweetsFromCell(num x, num y) {
  if (x >= m)
    return 0;
  if (y < 0)
    return 0;
  if (isCalculatedDP[x][y])
    return dp[x][y];
  dp[x][y] = max(MaxSweetsFromCell(x + 1, y), MaxSweetsFromCell(x, y - 1));
  // cerr << x << " " << y << " " << MaxSweetsFromCell(x + 1, y) << " "
  //      << MaxSweetsFromCell(x, y - 1) << "->" << dp[x][y];
  dp[x][y] += matrix[x][y];
  // cerr << "+" << matrix[x][y] << "-->" << dp[x][y] << endl;
  isCalculatedDP[x][y] = true;

  return dp[x][y];
}

void Read() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n >> m;
  for (idx_t y = 0; y < n; ++y)
    for (idx_t x = 0; x < m; ++x)
      cin >> matrix[x][y];
}

int main() {
  Read();
  num sum = 0;
  for (idx_t y = 0; y < n; ++y) {
    for (idx_t x = m - 1; x >= 0; --x) {
      sum += MaxSweetsFromCell(x, y);
    }
  }
  for (idx_t y = 0; y < n; ++y) {
    for (idx_t x = 0; x < m; ++x) {
      cerr << MaxSweetsFromCell(x, y) << " ";
    }
    cerr << endl;
  }

  cout << sum << endl;
  return 0;
}
/*
 4 3
 1 2 3
 -2 -3 0
 -1 4 -2
 3 -1 -1
 */
