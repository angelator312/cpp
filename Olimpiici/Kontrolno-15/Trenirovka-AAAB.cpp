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
int firstFunction() {
  if (n == 1) {
    return 0;
  } else if (n % 3 == 1) {
    --n;
    return firstFunction() * 2;
  } else if (n > 4 && (n - 4) % 6 == 0)
    return firstFunction() * 2 + 2;
  else if (n > 7 && (n - 7) % 6 == 0)
    return firstFunction() * 2 - 2;
  firstBacktracing();
  return br;
}
int main() {
  cin >> n;
  cout << firstFunction() << endl;
}