#include <cstdint>
#include <iostream>
using namespace std;
using LL = long long;



int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  LL out = 1 + n;
  for (int i = 2; i < n; ++i) {
    out = out + n/i;
  }

  cout << out << endl;
  return 0;
}