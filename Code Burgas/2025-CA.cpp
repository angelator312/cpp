#include <iostream>
using namespace std;
using LL = long long;

int main() {
  LL n, i = 2;
  cin >> n;
  if (n % i == 0) {
    cout << i << endl;
    return 0;
  }
  ++i;
  while (i * i <= n) {
    if (n % i == 0) {
      cout << i << endl;
      return 0;
    }
    i += 2;
  }
  cout<<n<<endl;
  return 0;
}