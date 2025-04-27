#include <algorithm>
#include <iostream>
using namespace std;
const int N = 302, M = 302;
int n, m, promJ = 1, promI = 1;
int i, j, br = 0;
int nomWhite[N][M];
int nomBlack[N][M];
inline bool nextWhite() {
  j += promJ;
  if (j == m || j == -1) {
    ++i;
    promJ *= -1;
    j += promJ;
  }
  return i < n;
}
inline bool nextBlack() {
  i += promI;
  if (i == n || i == -1) {
    ++j;
    promI *= -1;
    i += promI;
  }
  return j < m;
}
int main() {
  cin >> n >> m;
  int k = 0;
  while (nextWhite())
    nomWhite[i][j] = ++k;
//   for (int i = 0; i < n; ++i) {
//     for (int j = 0; j < m; ++j) {
//       cerr << nomWhite[i][j] << " ";
//     }
//     cerr << endl;
//   }
  i = 0;
  j = 0;
  k = 0;
  while (nextBlack())
    // nomBlack[i][j] = ++k;
    br+=(nomWhite[i][j] == ++k);
  /*
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cerr << nomBlack[i][j] << " ";
    }
    cerr << endl;
  }
  // */
  cout << br << endl;
}