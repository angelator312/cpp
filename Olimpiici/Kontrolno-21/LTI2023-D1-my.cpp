#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;
using LL = unsigned long long;
using pI = pair<LL, int>;
const int N = 52;
const int Q = 1e5 + 2;
const LL X = 1e18;
int n, q, br = 0;
int zaiavki[Q];
LL sum = 0, x;
LL s[N];
vector<int> sums;
vector<pI> zv;
int vzSz = 0;
void rekursia(int i) {
  if (i == n + 1) {\
    sums.push_back(sum);
    ++vzSz;

    return;
  }
  if (sum > X)
    return;
  sum += s[i];
  rekursia(i + 1);
  sum -= s[i];
  rekursia(i + 1);
}
void read() {
  cin >> n >> q;
  LL e;
  s[0] = 1;
  for (int i = 1; i <= n; ++i) {
    cin >> e;
    s[i] = e;
    s[i] *= s[i - 1];
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(nullptr);
  cin.tie(nullptr);
  read();
  rekursia(1);
  sort(sums.begin(), sums.end());
  int allBr = 0;
  
  for (int i = 0; i < q; ++i) {
    cin >> x;
    zv.push_back({x,i});
  }
  sort(zv.begin(), zv.end());

  // for (int i = 0; i < vzSz; ++i)
  // {
  //   cerr<<sums[i]<<" ";
  // }
  // cerr<<endl;

  int ptr_a=0;
  for (int ptr_q = 0; ptr_q < q; ++ptr_q)
  {
    LL fr = zv[ptr_q].first;
    while(ptr_a<vzSz&&sums[ptr_a]<=fr)
    {
      ++ptr_a;
    }
    zaiavki[zv[ptr_q].second]=ptr_a;
    // cerr << zv[ptr_q].first << " " << ptr_a << endl;
  }
  for (int i = 0; i < q; ++i)
  {
    cout << zaiavki[i] << " ";
  }
  cout << endl;
  return 0;
}
/*
2 1
10 10
100
1,2,1+2,0
otg=4
*/