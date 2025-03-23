#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
using pI = pair<int, int>; // del,broi
using vI = vector<pI>;
using LL = long long;
const int N = 1e4 + 1;
const int A = 45;
int deliteli[A];
int min_dev[A];
vI dels[A];
set<int> koiDeliteli;
vI getDels(int a) {
  vI out;
  int k, br = 0;
  while (a > 1) {
    k = min_dev[a];
    br = 0;
    while (min_dev[a] == k) {
      a /= min_dev[a];
      ++br;
    }
    out.push_back(make_pair(k, br));
    // cerr<<a<<endl;
  }
  return out;
}
void fillMin_dev() {
  min_dev[0] = 1;
  min_dev[1] = 1;
  for (int i = 2; i < A; ++i) {
    if (min_dev[i])
      continue;
    for (int j = i; j < A; j += i) {
      if (!min_dev[j])
        min_dev[j] = i;
    }
  }
}
void fillDels() {
  fillMin_dev();
  for (int i = 1; i < 43; ++i) {
    // cerr<<i<<endl;
    dels[i] = getDels(i);
  }
}
LL pow(int a, int pw) {
  if (pw == 0)
    return 1;
  if (pw % 2 == 0) {
    LL res = pow(a, pw / 2);
    return res * res;
  } else {
    return a * pow(a, pw - 1);
  }
}
int main() {
  fillDels();
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    for (auto e : dels[a]) {
      if (deliteli[e.first] < e.second)
        deliteli[e.first] = e.second;
      //   cerr << e.first << " " << e.second << endl;
      koiDeliteli.insert(e.first);
    }
  }
  LL out = 1;
  for (auto e : koiDeliteli) {
    // cerr << e << " " << deliteli[e] << endl;
    out *= pow(e, (deliteli[e] + 1) / 2);
  }
  cout << out << endl;
}