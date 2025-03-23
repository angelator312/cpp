#include <iostream>
#include <vector>
using namespace std;
using pI = pair<int, int>;
const int BR1 = 1e9 + 1;
const int BRL = 1e9 + 1;
const int L = 10;
vector<pI> vPairs;
int main() {
  double br1, brL, L;
  cin >> br1 >> brL >> L;
  for (int x = L; x <= brL * L; ++x) {
    double brEd = (br1 + brL * L) / x - brL;
    cerr<<x<<" "<<brEd<<endl;
    if (brEd < 0) {
      continue;
    } else if (brEd == int(brEd)) {
      int y = brEd + brL;
      vPairs.push_back({x, y});
    }
  }
  if (brL == 0) {
    vPairs.push_back({1, br1});
  }

  cout << vPairs.size() << '\n';
  for (auto [x, y] : vPairs)
    cout << x << ' ' << y << '\n';
}