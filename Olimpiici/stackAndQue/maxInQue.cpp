#include <algorithm>
#include <iostream>
#include <queue>
// #include <priority_queue>

using namespace std;
const int N = 3e5 + 2;
bool used[N];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);
  deque<pair<int, int>> dq;
  int n, ptr_l = 0, ptr_r = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    if (t == 1) {
      int x;
      cin >> x;
      while (!dq.empty() && dq.back().first < x) {
        dq.pop_back();
      }
      dq.push_back(make_pair(x, ptr_r));
      ++ptr_r;
    } else {
      if (dq.front().second == ptr_l) {
        dq.pop_front();
      }
      ++ptr_l;
    }
    if (!dq.empty())
      cout << dq.front().first << " ";
    else
      cout << -1 << " ";
  }
  cout << "\n";
  return 0;
}