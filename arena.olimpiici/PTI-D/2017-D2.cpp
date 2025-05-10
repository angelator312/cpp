#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using pI = pair<int, int>;
vector<int> chisla;
vector<pI> prs;
int n;
int sz = 0;
inline void read() {
  cin >> n;
  chisla.resize(n);
  for (int i = 0; i < n; ++i) {
    cin >> chisla[i];
  }
  sort(chisla.begin(), chisla.end());
  prs.push_back({chisla[0], 1});
  for (int i = 1; i < n; ++i) {
    if (prs[sz].first == chisla[i])
      ++prs[sz].second;
    else {
      prs.push_back({chisla[i], 1});
      ++sz;
    }
  }
  ++sz;
}
int main() {
  read();
  if (sz > 3) {
    cout << "No\n";
    return 0;
  }
  if (sz == 1) {
    cout << "Yes\n1\n";
    return 0;
  }
  int out = prs[1].first - prs[0].first;
  if (sz == 2) {
    cout << "Yes\n" << out << "\n";
    return 0;
  }
  if (out != prs[2].first - prs[1].first) { /* code */
    cout << "No\n";
    return 0;
  }
  cout << "Yes\n" << out << "\n";
  return 0;
}