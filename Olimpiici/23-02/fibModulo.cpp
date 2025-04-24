#include <iostream>
#include <vector>
using namespace std;
const int N = 400;
vector<int> fib;
int main() {
  int a = 1, b = 1, c, k, n;
  cin >> n >> k;

  fib.push_back(1);
  fib.push_back(1);
  for (int i = 2; i <= 1e8+1; i++) {
    swap(a, b);
    b += a;
    b %= k;
    // cerr << b << " ";
    fib.push_back(b);
    if (fib[i] == 1 && fib[i - 1] == 1) {
      c = i;
      break;
    }
  }
  //   for (int i = 3; i <= n; i++) {
  //     swap(a, b);
  //     b += a;
  //     b %= k;
  //     // fib.push_back(b);
  //     // if (fib[i] == 1 && fib[i - 1] == 1) {
  //     // }
  //   }
  --n;
//   c -= 2;
  --c;
//   cerr << endl << c << endl;
  cout << fib[n % c] << endl;
}