#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>
#include <string>
#include <utility>
#include <vector>
using namespace std;
char pr = '*';
int num, broiNula, broiEdno;
string s, a;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> s;

  for (char e : s) {
    if (pr != e) {
      if (e == '0')
        ++broiNula;
      else if (e == '1')
        ++broiEdno;
    }
    pr = e;
  }
  cerr << broiNula << " " << broiEdno << endl;
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a >> num;
    // //cerr << a << endl;
    if (a == "Inv") {
      --num;
      char a = s[num];
      if (a == '1')
        s[num] = '0';
      else
        s[num] = '1';
      // //cerr<<num<<endl;
      // //cerr<<s[num-1]<<a<<s[num+1]<<endl;
      if (num == 0) {
        if (a == s[num + 1]) {
          if (a == '1') {
            // s[num+1]=='1'
            ++broiNula;
          }
          if (a == '0')
            ++broiEdno;
        } else {
          if (a == '1') {
            // s[num+1]=='0'
            --broiEdno;
          }
          if (a == '0')
            --broiNula;
        }
      } else {
        if (s[num - 1] == s[num + 1]) {
          if (a == s[num + 1]) {
            // s[num+1]=='1'
            ++broiNula;
            ++broiEdno;
          } else {
            --broiEdno;
            --broiNula;
          }
        } else {
          // nothing
        }
      }
      cerr << s << endl;
      cerr << broiNula << " " << broiEdno << endl;

    } else {
      // cerr << num << endl;
      if (num == 0)
        cout << broiNula << endl;
      if (num == 1)
        cout << broiEdno << endl;
    }
  }

  return 0;
}
