#include <algorithm>
#include <iostream>
using namespace std;
int main() {
  int x, y;
  int x2, y2, r;
  cin >> x >> y;
  cin >> x2 >> y2;
  swap(x, x2);
  int n;
  cin >> n;
  char z;
  for (int i = 0; i < n; i++) {
    cin >> z >> r;
    if (z == 'H') // Horizontalno
    {
      cin >> z;
      if (z == 'T') {
        y2 = r;
      } else if (z == 'B') {
        y = r;
      }
    } else if (z == 'V') // Verticalno
    {
      cin >> z;
      if (z == 'L') {
        x2 = r;
      } else if (z == 'R') {
        x = r;
      }
    }
    cerr << x << " " << y << endl;
    cerr << x2 << " " << y2 << endl;
  }
  cout << 1LL * abs(y - y2) * abs(x - x2) << endl;
}