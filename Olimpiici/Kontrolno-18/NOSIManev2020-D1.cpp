#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using pI = pair<int, int>;
vector<pI> v;
int main() {
  int n, br = 0;
  cin >> n;
  --n;
  //   cerr<<n<<endl;
  for (int i = 0; i <= n; ++i) {
    int e, e2;
    cin >> e >> e2;
    // cerr << e + e2<<":\n";
    if ((e + e2 == n) && (e >= 0 && e2 >= 0)) {
      v.push_back(make_pair(e, e2));
      ++br;
    }
  }
  sort(v.begin(), v.end());
  pI posl(-1, -1);
  for (auto e : v) {
    if (e == posl)
      --br;
  }

  cout << br << endl;
  return 0;
}