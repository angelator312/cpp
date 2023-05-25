#include <iostream>
using namespace std;
int main() {
  string n;
  int c, f = 0, ch[10];
  bool o = true;
  cin >> c;
  cin >> n;
  if (c == 1) {
    cout << "yes " << n << endl;
    return 0;
  }
  for (int i = 0; i <= 9; i++) {
    bool b = true;
    int p = 0;
    for (int j = 0; j < c; j++)
      if (n[j] == to_string(i)[0]) {
        b = !b;
        p++;
      }
    if ((!b) && p > 0)
      f++;
    if (f == 2) {
      o = false;
      break;
    }
  }
  if (!o)
    cout << "no" << endl;
  else {
    int sum = 0;
    for (int i = 0; i < c; i++)
      sum += n[i] - '0';
    cout << "yes " << sum << endl;
  }
  return 0;
}