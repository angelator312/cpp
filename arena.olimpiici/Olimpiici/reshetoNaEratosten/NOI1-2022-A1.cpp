#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
using LL = long long;
const int N = 3e6 + 2; // Lupi Pravilo
int cnt1[N];
int cnt2[N];
set<int> mas;
int br[N];
void init() {}
int main() {
  init();
  int n, maxA = 0;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    maxA = max(a, maxA);
    ++br[a];
    if (br[a] == 1)
      mas.insert(a);
  }
  for (auto a : mas) {
    for (int b = 2 * a; b <= maxA; b += a) {
      if (br[b] > 0) {
        cnt2[b] += br[b];
        cnt1[a] += br[b];
      }
    }
  }
  int brMain = 0;
  for (auto a : mas) {
    brMain += cnt1[a] * cnt2[a];
  }
  cout << brMain << endl;
  return 0;
}