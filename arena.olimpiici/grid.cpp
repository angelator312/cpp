#include <iostream>
using namespace std;
// int countDots(int x, int y, int r, int c, int st, string s[]) {
//   int br = 0, stars = 0;
//   for (int i = x; i <= r; i++) {
//     for (int j = y; j <= c; j++) {
//       if (s[i][j] == '.') {
//         br++;
//       } else {
//         stars++;
//       }
//     }
//   }
//   //   cout << " stars: " << stars << endl;
//   if (st > stars) {
//     return 99999;
//   }
//   return br;
// }
int main() {
  int w, h, sx = 999999, sy = 999999, x = 0, y = 0;
  cin >> h >> w;
  string s[h];
  for (int i = 0; i < h; i++) {
    cin >> s[i];
    for (int j = 0; j < w; j++) {
      if (s[i][j] == '*') {
        sx = min(sx, j);
        x = max(x, j);
        y = max(y, i);
        sy = min(sy, y);
      }
    }
  }
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (i >= sy && i <= y && j >= sx && j <= x) {
        cout << "*";
      } else {
        cout << ".";
      }
    }
    cout << endl;
  }

  //   cout << m << endl;
  return 0;
}