#include <iostream>

using namespace std;
inline int chis(int a, int b, int c) { return a * 100 + b * 10 + c; }
int main() {
  int n;
  cin >> n;
  int a = n / 100, b = n / 10 % 10, c = n % 10;
  if (a < b)
    swap(a, b);
  if (c > b)
    swap(c, b);
  if (a < b)
    swap(a, b);
  if (c > b)
    swap(c, b);
  if (c == 0) {
    cout << chis(a, b, c) - chis(a, c, b) << endl;
  } else
    cout << chis(a, b, c) - chis(c, b, a) << endl;
  return 0;
}
