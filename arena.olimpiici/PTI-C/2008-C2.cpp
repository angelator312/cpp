#include <iostream>
#include <queue>
#include <vector>
using namespace std;
using pI = pair<int, int>;
using pB = pair<int, bool>;
int n, a, b, razlika;
const bool ATOCHKA = true;
const bool BTOCHKA = true;
queue<pB> tochkiA;
vector<pI> intervals;
int main() {
  cin >> n >> a >> b >> razlika;
  int firstB = n % b;
  for (int i = 0; i < n; ++i) {
    if (!(i % a))
      tochkiA.push({i, ATOCHKA});
    if ((i - firstB) % b == 0)
      tochkiA.push({i, BTOCHKA});
  }

  for (auto e : intervals) {
    cerr << e.first << " " << e.second << endl;
  }
}