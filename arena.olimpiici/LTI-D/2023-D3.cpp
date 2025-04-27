#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using LL = long long;
using pL = pair<int, LL>;
int n;
LL br = 0;
vector<pL> st;

int main() {
  cin >> n;
  int e;
  int mazhurant = -1, br = 1;
  cin >> mazhurant;
  for (int i = 1; i < n; ++i) {
    cin >> e;
    if (e == mazhurant)
      ++br;
    else
      --br;
    if (br <= 0) {
      mazhurant = e;
      br = 1;
    }
  }
  br=0;
  for (int i = 0; i < n; ++i) {
    cin >> e;
    if(e==mazhurant)++br;
  }
  if(br>n/2)
    cout << 2 * (n - br) << endl;
  else cout << min(2 * (n - br),n-1) << endl;
  return 0;
}