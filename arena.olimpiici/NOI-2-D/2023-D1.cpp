#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
using pI = pair<int, int>;
using vS = vector<string>;
vector<pI> v;
int vSize = 0;
string s;
bool bl = 0;
string without(string s, int nom) {
  cerr << s << endl;
  int e = v[nom].first - nom;
  int e2 = v[nom].second - nom;
  cerr << e << " " << e2 << endl;
  string out = "";
  if (e > 0)
    out += s.substr(0, e - 1);
  out += s.substr(e + 1, e2 - e - 1);
  if (bl) {
    if (nom != 0)
      out += s.substr(e2 + 1);
  } else
    out += s.substr(e2 + 1);
  cerr << "to:" << out << endl;
  return out;
}
vS fillVectorWithIzrazi(const vS &a, int nomInV) {
  vS b = a;
  if (nomInV == vSize - 1) {
    int n = a.size();
    for (int i = 0; i < n; ++i) {
      b.push_back(without(a[i], nomInV));
    }
  } else {
    int n = a.size();
    for (int i = 0; i < n; ++i) {
      b.push_back(without(a[i], nomInV));
    }
    b = fillVectorWithIzrazi(b, nomInV + 1);
  }
  return b;
}
int main() {
  cin >> s;
  int n = s.size();
  stack<int> openBrackets;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '(') {
      openBrackets.push(i);
    } else if (s[i] == ')') {
      v.push_back(make_pair(openBrackets.top(), i));
      openBrackets.pop();
      ++vSize;
    }
  }
  reverse(v.begin(), v.end());
  if (v[vSize - 1].second == n)
    bl = true;
  for (int i = 0; i < vSize; i++) {
    cerr << v[i].first << " " << v[i].second << endl;
  }

  vS vec;
  vec.push_back(s);
  vec = fillVectorWithIzrazi(vec, 0);
  for (auto e : vec) {
    cout << e << endl;
  }
}
