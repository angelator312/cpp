#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using pI = pair<int, int>;
const int A = 3e5 + 2;
const int N = 5e5 + 2;
int n, mn = 0;
int indOf[A]; // indexes from 1
int redica[N];
// vector<pI> podRedici;
inline void Init() {
  for (n = 1; cin.good(); ++n) {
    cin >> redica[n];
    indOf[redica[n]] = n;
  }
  sort(redica + 1, redica + n);
  --n;
  //*
  for (int i = 1; i <= n; ++i) {
    cerr << redica[i] << " ";
  }
  cerr << endl;
  //*/
}
int main() {
  Init();
  int len = 0, l = 1, poslCh = redica[1] - 1;
  int maxLen = 0, maxL = 0, maxR = 0;
  for (int i = 1; i <= n; ++i) {
    if (poslCh == redica[i])
      continue;
    ++poslCh;
    if (poslCh == redica[i])
      ++len;
    else {
      if (len > maxLen) {
        maxLen = len;
        // maxL = l;
        maxR = i;
      }
      len = 1;
      l = i;
      poslCh = redica[i];
    }
  }

  if (len > maxLen) {
    maxLen = len;
    // maxL = l;
    maxR = n + 1;
  }
  // cerr << maxLen << " " << maxL << " " << maxR << endl;

  cout << maxLen << " " << redica[maxR - 1] << " " << indOf[redica[maxR - 1]]
       << endl;
  return 0;
}