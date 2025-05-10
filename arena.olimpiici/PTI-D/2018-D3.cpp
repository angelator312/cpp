#include <algorithm>
#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;
int nach = 0, krai = 0;
int br = 0;
string sNach="0", sEnd; // reversed
vector<int> outs;
int outSz = 0;
inline int lower_bound(const int &a) {
  int l = 0, r = outSz, ans = 0, mid = 0;
  while (l <= r) {
    mid = (l + r) / 2;
    if (outs[mid] >= a) {
      r = mid - 1;
      ans = mid;
    } else
      l = mid + 1;
  }
  return ans;
}
inline void operator++(string &a) {
  auto it = a.rbegin();
  for (; it != a.rend() && (*it) == '1'; ++it) {
    *it = '0';
  }
  if (it != a.rend()) {
    *it = '1';
  } else {
    a = '1' + a;
  }
}

constexpr void fill_outs() {
  int nach2 = 0;
  int krai2 = 1 << 21 - 1;
  while (nach2 <= krai2) {
    if (stoull(sNach) % nach2 == 0) {
      outs.push_back(nach2);
    }
    // cerr << sNach << " " << nach2 << endl;
    ++sNach;
    ++nach2;
  }
}

inline void Init() {
  fill_outs();
  outSz = outs.size();
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> sNach >> sEnd;
  int chNaSt = 1;
  for (auto it = sNach.rbegin(); it != sNach.rend(); ++it) {
    nach += chNaSt * (*it - '0');
    chNaSt <<= 1;
  }
  chNaSt = 1;
  for (auto it = sEnd.rbegin(); it != sEnd.rend(); ++it) {
    krai += chNaSt * (*it - '0');
    chNaSt <<= 1;
  }
}

int main() {
  Init();
  int l = 0, r = 0;
  for (int i = l; i < r; ++i) {
    cout << e << endl;
  }

  if (r - l == 0) {
    cout << -1 << endl;
  }
  return 0;
}