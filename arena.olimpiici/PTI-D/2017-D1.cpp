#include <iostream>
#include<algorithm>
using namespace std;
using LL = long long;
const int A = 1e7;
int firstInd[A];
int lastInd[A];
int n;
string s;
int main() {
  cin >> s;
  LL br = 1;
  reverse(s.begin(),s.end());
  for (char e : s) {
    cerr << e;
    br *= min(e - '0', 1);
    ++br;
  }
  --br;
  cout << br << endl;
  return 0;
}