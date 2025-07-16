#include <bitset>
#include <ios>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;
const int N = 2e4 + 1;
set<int> edges_that_I_lock[N];
int br_for_me[N];
bool in_queue[N];
bitset<N + 3> ima_gi;
int out_br;
int m, k, mx_n = 0, br_razl = 0;

void Init() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> k;
  for (int i = 0; i < k; ++i) {
    cin >> m;
    vector<int> do_sega;
    for (int i = 0, b; i < m; ++i) {
      cin >> b;
      ima_gi.set(b);
      mx_n = max(mx_n, b);
      for (int e : do_sega) {
        if (e == b ||
            edges_that_I_lock[e].find(b) != edges_that_I_lock[e].end())
          continue;

        edges_that_I_lock[e].insert(b);
        ++br_for_me[b];
      }
      do_sega.push_back(b);
    }
  }
  for (int i = 1; i <= mx_n; ++i)
    br_razl += ima_gi[i];
}
void bfs() {
  queue<int> q;
  for (int i = 1; i <= mx_n; ++i)
    if (!br_for_me[i] && ima_gi[i]) {
      in_queue[i] = true;
      q.push(i);
    }
  while (!q.empty()) {
    int now = q.front();
    q.pop();
    // cerr << "now:" << now << endl;
    ++out_br;
    for (int e : edges_that_I_lock[now]) {
      if (in_queue[e])
        continue;
      if (--br_for_me[e] <= 0) {
        in_queue[e] = true;
        q.push(e);
      }
    }
  }
}
int main() {
  Init();
  /*

  for (int i = 0; i <= mx_n; ++i) {
    if (edges_that_I_lock[i].empty())
      continue;
    // cerr << i << "[" << br_for_me[i] << "]" << ":";
    for (int e : edges_that_I_lock[i]) {
      // cerr << e << " ";
    }
    // cerr << endl;
  }
   //*/
  bfs();
  // cerr << br_razl << " " << out_br << endl;
  cout << (br_razl == out_br) << "\n";
}
/*

2
3 1 2 3
4 1 3 5 6

3
3 5 1 4
3 4 201 150
4 150 1 20 55

2
4 1 5 6 2
3 2 1 6

4
5 100 20 45 10 3
3 20 300 400
4 500 100 80 10
3 400 500 1000

3
3 1 80 5
5 90 1 4 8 80
5 90 1 8 100 5
*/
