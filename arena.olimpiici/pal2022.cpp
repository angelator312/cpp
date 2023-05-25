#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> Vi;

bool pal(int n){
      int i = n;
      int r=0;
      while (n != 0)
      {
        int d = n % 10;
		    r = (r * 10) + d;
		    n = n / 10;
      }
      return i == r;
}

bool pal_bavna(int n) {
  int ds[8], dsl = 0;

  for (long i = 0, d = 1;; d = d * 10, i++) {
    int x = n / d;
    if (x == 0) {
      break;
    }
    ds[dsl] = x % 10;
    dsl++;
  }
  bool nechetno = dsl % 2 == 1;
  int sr = dsl / 2;
  for (size_t i = 0; i < dsl; i++) {
    if (ds[i] != ds[dsl - i - 1]) {
      return false;
    }
    if ((nechetno && i == sr) || i == sr) {
      return true;
    }
  }
  cerr << "Error in pall function" << endl;
}
int rpall(int a, int b, int c) {
  // cin >> a >> b >> c;
  int ps = 0;
  int ppal = -1, rmin = 50000002, rmax = -1;
  for (int i = a; i <= b; i = i + c) {
    if (pal(i)) {
      ps++;
      if (ppal != -1) {
        int d=i - ppal;
        if (d > rmax) {
          rmax = d;
        }
        if ( d < rmin) {
          rmin = d;
        }
      }
      ppal = i;
      //   cout << ppal << endl;
    }
  }
  if (ps == 0) {
    cout << 0 << endl;
  } else if (ps == 1) {
    cout << 1 << endl;
  } else {
    cout << ps << " ";
    cout << rmin - 1 << " ";
    cout << rmax - 1 << endl;
  }
  return 0;
}
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    rpall(a, b, c);
  }
}