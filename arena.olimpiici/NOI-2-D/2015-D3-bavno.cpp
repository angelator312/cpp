#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  LL n, br = 0;
  char k;

  cin >> k >> n;

  if (n >= k - '0')
    br++;
  // cout<<br<<endl;

  for (int i = 1; i <= (n / 10) - 1; i++) {
    string s = to_string(i);
    for (char x : s)
      if (x == k)
        br += 10;
    br++;
  }
  // cout<<br<<endl;
  if (n>10&&n % 10 >= k - '0')
    br++;
  // cout<<br<<endl;
  string s = to_string(n / 10);
  for (char x : s)
    if (x == k)
      br += n % 10 + 1;
  cout << br << endl;
  return 0;
}