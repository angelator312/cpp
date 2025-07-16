#include <iostream>
using namespace std;
const int K = 20;
const int N = 1e6 + 2;
const int A = 1e6 + 3;
int money[K];
int memorization[N];
int k;
int f(int n) {
  if (n < 0)
    return -1;
  if (n == 0) {
    return 0;
  }
  if (memorization[n]) {
    return memorization[n];
  }
  int coins = A;
  for (int i = 0; i < k; ++i) {
    if (f(n - money[i]) > -1) {
      coins = min(coins, f(n - money[i]));
    }
  }
  // cerr<<n<<":"<<coins<<endl;
  if (coins == A) {
    return -1;
  }
  return memorization[n] = coins + 1;
}
int main() {
  int n;
  cin >> n >> k;
  for (int i = 0; i < k; ++i) {
    cin >> money[i];
  }
  cout << f(n) << endl;
  return 0;
}
