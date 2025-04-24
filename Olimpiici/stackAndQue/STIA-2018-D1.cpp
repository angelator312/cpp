#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#define endl "\n"
using namespace std;
const int N = 1e6 + 1;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s;
  cin >> s;
  int n = s.size();
  int kab = 0, mehurcheta = 0;
  stack<char> neshta;
  for (int i = 0; i < n; ++i) {
    char e = s[i];
    if (e == 'O') {
      if (!neshta.empty()) {
        if (neshta.top() == 'L')
          ;
        else {
          neshta.push('O');
          ++mehurcheta;
        }
      } else {
        neshta.push('O');
        ++mehurcheta;
      }
    } else if (e == 'L') {
      neshta.push('L');
      ++kab;
    } else {
      while (!neshta.empty() && neshta.top() == 'O') {
        // cerr<<neshta.top()<<"\n";
        neshta.pop();
        mehurcheta--;
      }
      ++kab;
      neshta.push('T');
    }
  }
  cout << kab + mehurcheta << " " << mehurcheta << endl;
}