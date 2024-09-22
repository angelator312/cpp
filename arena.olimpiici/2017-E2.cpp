#include <iostream>

using namespace std;
void podmen(int &a) {
  if (a == 6) {
    a = 9;
  }
}
int main() {
  int a, b, k, e;

  cin >> a >> b;
  podmen(a);
  podmen(b);
  if (a > b) {
    cout << a << b << endl;
  } else
    cout << b << a << endl;

  return 0;
}