#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using pS = pair<string, int>;
vector<pS> v;
vector<pS> v2;

int e;
string a;
int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> a >> e;
    v.push_back({a, e});
  }
  int q;
  cin >> q;
  int otg[q];
  sort(v.begin(), v.end());
  for (int i = 0; i < q; ++i) {
    cin >> a;
    v2.push_back({a, i});
  }
  sort(v2.begin(), v2.end());
  int ptr_a = 0, promiana = 0;
  for (int i = 0; i < n; ++i) {
    promiana += v[i].second;
    if (i == n - 1 || v[i].first != v[i + 1].first) {
      if (v2[ptr_a].first == v[i].first) {
        otg[v2[ptr_a].second] = promiana;
        ++ptr_a;
        // cerr << v[i].first << " " << promiana << endl;
      }
      promiana = 0;
    }
  }
  for (int i = 0; i < q; ++i) {
    cout << otg[i] << endl;
  }
}