#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
using pI = pair<int, int>;
using sPI = stack<pI>;
vector<pI> vec;
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
        br2 += vec.back().second - 1;
        vec.pop_back();
      }
      br += br2;
    }
    vec.push_back(make_pair(e, br));
    st.push(e);
  }
  int sum = 0;
  // for (auto e : vec) {
  //   cerr << e.first << " " << e.second << endl;
  // }
  int vSize = vec.size();
  for (int i = 0; i <= vSize - 2; i++) {
    int e = vec[i].first;
    int e2 = vec[i + 1].first;
    int a2 = vec[i + 1].second;
    int s = min(e, e2) * u * v * a2;
    // cerr << e << " " << e2 << " " << s << endl;
    sum += s;
  }

  cout << sum << endl;
  return 0;
}