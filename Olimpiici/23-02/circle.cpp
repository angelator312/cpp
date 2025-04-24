#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using pI = pair<int, int>;
vector<pI> qu;
int n, k, br = 0;
void read() {
  cin >> n >> k;
  for (int i = 1; i < n; ++i) {
    qu.push_back(make_pair(i, i));
  }
  qu.push_back(make_pair(n, 0));
  br = n;
}
int main() {
  read();
  --k;
  int i = 0;
  while (br > 1) {
    for (int brToK = 0; brToK < k; ++brToK) {
      i = qu[i].second;
    }
    if (i == 0) {
      qu[n].second = qu[i].second;
    } else if (i == n) {
      qu[n - 1].second = qu[n].second;
    } else {
      qu[i - 1].second = qu[i].second;
    }
    cerr << qu[i].first << " " << qu[i-1].second << endl;
    i=qu[i].second;
    --br;
  }
  cerr<<endl;
  for (int i = 0; i < n; ++i) {
    cerr << qu[i].first << " " << qu[i].second << endl;
  }

  cout << qu.back().first << endl;
}