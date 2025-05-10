#include <iostream>
using namespace std;
int main() {
  int n, k, br = 0;
  cin >> n >> k;
  for (int i = 2; i <= k; ++i) {
    br += n - i+1;
  }
  cout << br << endl;
  return 0;
}