#include <algorithm>
#include <iostream>
#include <vector>
#define print()                                                                \
  cout << d2 / 10 << d2 % 10 << ".";                                           \
  cout << m2 / 10 << m2 % 10 << ".";                                           \
  cout << y << endl;

using namespace std;

void next(int &d, int &m, int &y) {
  int months[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if (y % 100 == 0 && y % 400 == 0) {
    ++months[2];
  } else if (y % 4 == 0)
    ++months[2];
  if (d == months[m]) {
    d = 1;
    if (m == 12) {
      m = 1;
      ++y;
    } else
      ++m;
  } else
    ++d;
}

int main() {
  int d, m, y, n;
  int d2 = 31, m2 = 12, y2 = 2018;
  char z;
  cin >> d >> z >> m >> z >> y >> n;
  int koiDen = 1;
  while (!(d2 == d && m2 == m && y2 == y)) {
    ++koiDen;
    next(d2, m2, y2);
  }
  while (n > 0) {
    ++koiDen;
    koiDen %= 7;
    if (koiDen > 0 && koiDen < 6) {
      --n;
    }
    // print();
    // cerr << koiDen << endl;
    next(d2, m2, y2);
  }
  while (koiDen == 0 || koiDen == 6) {
    ++koiDen;
    koiDen %= 7;
    next(d2, m2, y2);
  }
  // koiDen==1 Ponedelnick
  print();
    // cerr << koiDen % 7 << endl;
}