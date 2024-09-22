#include <iostream>
using namespace std;
int countDots(int x, int y, int r, int c, int st, string s[]) {
  int br = 0, stars = 0;
  for (int i = x; i <= r; i++) {
    for (int j = y; j <= c; j++) {
      if (s[i][j] == '.') {
        br++;
      } else {
        stars++;
      }
    }
  }
//   cout << " stars: " << stars << endl;
  if (st > stars) {
    return 99999;
  }
  return br;
}
int main() {
  int w, h, m = 999999, st = 0, sx, sy, x, y;
  cin >> h >> w;
  string s[h];
  for (int i = 0; i < h; i++) {
    cin >> s[i];
    for (int j = 0; j < w; j++) {
      if (s[i][j] == '*')
        st++;
    }
  }
//   cout << st << endl;
  for (int i = 0; i < w; i++) {
    // cout << "i" << endl;
    for (int j = 0; j < h; j++) {
      //   cout << "j" << endl;
      for (int r = j; r < h; r++) {
        // cout << "r" << endl;
        for (int c = i; c < w; c++) {
          int count = countDots(i, j, r, c, st, s);
        //   cout << "x:" << i << " y:" << j << " x:" << c << " y:" << r << endl;
          if (m > count) {
            sx = i;
            sy = j;
            x = c;
            y = r;
            m = count;
          }
        //   cout << " dots: " << count << endl;
        }
      }
    }
  }
  for (int i=0;i<h;i++) {
    for (int j = 0; j < w; j++)
    {
        if(i>=sy&&i<=y && j>=sx&&j<=x){
            cout<<"*";
        }
        else {
            cout<<".";
        }
    }
    cout<<endl;
  }
//   cout << m << endl;
  return 0;
}