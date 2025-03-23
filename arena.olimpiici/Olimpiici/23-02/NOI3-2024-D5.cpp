#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(nullptr);
  cin.tie(nullptr);
  int n, k;
  int br = 0;
  cin >> n >> k;
  if (k % 2 == 0) {
    cout << 0 << endl;
    return 0;
  }
  if (k == 1) {
    v.push_back(0);
  }
  int posl = 1;
  for (int i = 2; i < n; ++i) {
    posl += 2;
    posl = posl > i ? posl - i : posl;
    // cerr<<posl<<endl;
    if (posl == k)
      v.push_back(i - 1);
  }
  cout << v.size() << endl;
  for (int e : v) {
    cout << e << " ";
  }
  cout << endl;
  return 0;
}