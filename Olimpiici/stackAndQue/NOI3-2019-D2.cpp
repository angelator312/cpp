#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
using pI = pair<int, int>;
const int N = 1e5;
int a[N];
vector<pI> v;
int main() {
  int n, q, br = 0;
  cin >> n >> q;
  // if (q == 1) {
  stack<int> s;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    while (!s.empty() && a[s.top()] < a[i]) {
      s.pop();
    }
    if (!s.empty()) {
      if (a[s.top()] == a[i]) {
        ++br;
        v.push_back(make_pair(s.top(), i));
        s.pop();
      }
    }
    s.push(i);
  }

  if (q == 2) {
    br=0;
    for (int i = 1; i < v.size(); i++) {
      if (v[i].first < v[i - 1].second && v[i - 1].second < v[i].second)
        ++br;
      // cerr << v[i].first << " " << v[i].second << endl;
    }
  }

  // cout << br << endl;
  cout << br << endl;
}