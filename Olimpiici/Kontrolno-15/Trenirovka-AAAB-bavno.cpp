#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#define F first.first
#define S first.second
#define T second

using namespace std;
using LL = long long;
using p3I = pair<pair<int, int>, int>;
using v3PI = vector<p3I>;
int n, sz = 0, br = 0, sum = 0;
string s = "";
void backtracing() {
  if (sz == n) {
    // cerr << s<<" "<<sum << endl;
    br += (sum % 3 == 0);
    return;
  }
  if (s.back() == 'a') {
    sum++;
  }
  ++sz;
  s += "a";
  backtracing();
  s.pop_back();
  s += "b";
  backtracing();
  s.pop_back();
  --sz;
  if (s.back() == 'a') {
    --sum;
  }
  return;
}
void firstBacktracing() {
  ++sz;
  s += "a";
  backtracing();
  s.pop_back();
  s += "b";
  backtracing();
  s.pop_back();
}
int main() {
  cin >> n;
  firstBacktracing();
  if (n == 1) {
    cout << 0 << endl;
  } else
    cout << br << endl;
}