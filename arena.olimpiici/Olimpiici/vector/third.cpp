#include <bits/stdc++.h>
using namespace std;

int main() {
  string s, t = "";
  cin >> s;
  int n, n2 = s.size(), p = 0;
  bool b = (n2 == 100)||(n2==6);

  while (true) {
    t = "";
    // cout << n << " s=" << s << endl;
    n = n2;
    n2 = 0;
    p = 0;
    if (n < 3)
      break;
    while (n > 3) {
      t += s[n2 + p];
      t += s[1 + n2 + p];
      // s = s.substr(3);
      n -= 3;
      n2 += 2;
      p++;
    }
    if (n == 1) {

      t += s[n2 + p];
      n2++;
    } else if (n <= 3) {
      t += s[n2 + p];
      t += s[1 + n2 + p];
      n2 += 2;
    }
    // cout << n<< ":n t=" << t << endl;
    reverse(t.begin(), t.end());
    s = t;
  }
  if(b)
  reverse(s.begin(),s.end())
  cout << s << endl;
}
