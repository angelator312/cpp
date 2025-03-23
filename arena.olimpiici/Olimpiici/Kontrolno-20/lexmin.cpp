#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int N = 26;
string s, t;
bool izp[N];
int n, ptr_a = 0;
void init() {
  cin >> s;
  n = s.size();
  for (int i = 0; i <= n; ++i) {
    t += i + 'a';
  }
}
int main() {
  init();
  // cout << t << endl;
  for (int i = 0; i < n;) {
    if (s[i] == 'u')
      ++i;
    int j = i;
    while (s[i] == s[j]) {
      ++j;
    }
    reverse(t.begin() + i, t.begin() + j + 1);
    i = j;
  }
  cout << t << endl;

  return 0;
}