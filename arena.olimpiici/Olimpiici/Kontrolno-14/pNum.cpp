#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
using LL = long long;
const int N = 1e8 + 1;
const int P = 255 + 1;
int n, p;
vector<string> now;

LL toDesetichna(const string &s) {
  LL res = 0;
  for (int i = 0; i < s.size(); ++i) {
    res = res * p + s[i] - '0';
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n >> p;
  now.push_back("0");
  now.push_back("1");
  if (n > 1) {
    cout << "1\n";
  }
  int gol = 1;
  while (1) {
    bool stp = true;
    int sz = now.size();
    for (int i = 0; i < sz; i++) {
      string s;
      if (stp && now[i].size() < gol) {
        now[i] = "0" + now[i];
      } else
        stp = false;
      s = "1" + now[i];
      LL dS = toDesetichna(s);
      if (dS > n) {
        return 0;
      } else {
        cerr << s << " ";
        cout << dS << "\n";
      }
      now.push_back(s);
    }
    gol++;
  }
}