#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
  ll n = 0;
  string out = "";
  char b;
  cin >> b;
  while (b != '.') {
    if (b == '0') {
      n++;
    } else {
      char c='a' + n;
      out +=c;
      n = 0;
    }
    cin >> b;
  }
  cout << out << endl;
}