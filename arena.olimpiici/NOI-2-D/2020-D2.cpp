#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
using pI = pair<int, int>;
using sPI = stack<pI>;
vector<pI> points;
int main() {
  stack<int> st;
  int n, u, v;
  cin >> n >> u >> v;
  for (int i = 0; i < n; ++i) {
    int e;
    cin >> e;
    int br = 1;
    while (!st.empty() && st.top() < e) {
      ++br;
      st.pop();
    }
    if (st.empty()) {
      br = 1;
    } else {
      int br2 = 0;
      for (int j = 1; j < br; j++) {
        br2 += points.back().second - 1;
        points.pop_back();
      }
      br += br2;
    }
    points.push_back(make_pair(e, br));
    st.push(e);
  }
  int sum = 0;
  // for (auto e : vec) {
  //   cerr << e.first << " " << e.second << endl;
  // }
  int vSize = points.size();
  for (int i = 0; i <= vSize - 2; i++) {
    int e = points[i].first;
    int e2 = points[i + 1].first;
    int a2 = points[i + 1].second;
    int s = min(e, e2) * u * v * a2;
    // cerr << e << " " << e2 << " " << s << endl;
    sum += s;
  }

  cout << sum << endl;
  return 0;
}