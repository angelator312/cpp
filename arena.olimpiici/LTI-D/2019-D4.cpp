#include <algorithm>
#include <array>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
using pB = pair<int, bool>;
using pI = pair<int, int>;
using LL = long long;
const int N = 5e4 + 1;
const int N2 = 2 * N;
vector<pB> chisla;
vector<array<int, 3>> intervals;
vector<int> edges[N]; // tree-graph
LL colors[N];
int n, n2, k;
stack<int> st, roots;
stack<array<int, 4>> intervals2;
inline void read() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n;
  n2 = n << 1;
  bool e;
  for (int i = 0, p; i < n2; ++i) {
    cin >> e >> p;
    chisla.push_back({p, e});
  }
  sort(chisla.begin(), chisla.end());
}
inline void print() {
  LL ch = 0;
  for (int i = 1; i <= k; ++i)
    ch += colors[i];
  cout << k << " " << ch << "\n";
  for (int i = 1; i <= k; ++i) {
    cout << colors[i] << " ";
  }
  cout << endl;
}

inline int dfs(const int edge) {
  // cerr << "onEdge:" << edge << endl;
  int doSega = 0;
  for (int e : edges[edge]) {
    doSega += dfs(e);
  }
  int lice =
      chisla[intervals[edge][1]].first - chisla[intervals[edge][0]].first;
  lice *= intervals[edge][2];
  colors[intervals[edge][2]] += lice - doSega;
  // cerr << "outEdge:" << edge << " " << lice << endl;
  return lice;
}

int main() {
  read();
  int h = 1, lastL = -1, lastR = -1;
  for (int i = 0; i < n2; ++i) {
    if (chisla[i].second) {
      st.push(i);
    } else {
      intervals.push_back({st.top(), i, 0});
      st.pop();
    }
  }
  int lastH = -1;
  for (int i = 0; i < n; ++i) {
    int mx = 0;
    int l = intervals[i][0], r = intervals[i][1];
    while (!intervals2.empty()) {
      array<int, 4> e = intervals2.top();
      if (!((l <= e[0] && e[0] <= r) && e[1] <= r)) {
        break;
      }
      edges[i].push_back(e[3]);
      mx = max(e[2], mx);
      intervals2.pop();
    }
    intervals[i][2] = ++mx;
    intervals2.push({l, r, mx, i});
    // cerr << intervals[i][0] << " " << intervals[i][1] << " " <<
    // intervals[i][2]  << endl;
    // if (lastH > mx) {
    //   roots.push(i - 1);
    //   // intervals2.pop();
    // }
    k = max(mx, k);
    lastH = mx;
  }
  while (!intervals2.empty()) {
    roots.push(intervals2.top()[3]);
    intervals2.pop();
  }

  while (!roots.empty()) {
    dfs(roots.top());
    roots.pop();
  }

  print();
}
/*
9
1 1
1 2
1 3
1 4
1 5
0 6
0 7
1 8
0 9
0 10
1 11
1 12
0 13
1 14
0 15
0 16
0 17
0 18
*/