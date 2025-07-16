// Дяволчетата - 100t
#include <algorithm>
#include <iostream>
using namespace std;
int n, m;
int main() {
  cin >> n;
  char c;
  int lastSedalka = 0;
  int i = 0;
  int len = 0;
  bool first = true;
  for (; i < n || cin.good(); ++i) {
    cin >> c;
    if (!(c == '0' || c == '1')) {
      --i;
      break;
    }
    if (c == '1') {
      if (first) {
        len = max(len, i - 1);
        first = false;
      } else
        len = max((i - lastSedalka - 2) / 2, len);
      lastSedalka = i;
    }
  }
  n = i-1;
  cerr<<n<<endl;
  len = max(len, n - 1 - lastSedalka - 1);
  cout << len << endl;
  return 0;
}
/*
13
1001000000100c

 */
