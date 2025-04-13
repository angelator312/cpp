#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
typedef long long ll;
int main() {
  ll n, d, p = 1, po = 9, br = 0;
  cin >> n >> d;
  vector<ll> nt;
  p = 1 * pow(10, n - 1);
  for (int i = 0; i <= n - 2; i++) {
    po = po * 10 + 9;
  }
  po--;
  for (int i = p; i <= po; i++) {
    if (i % d == 0) {
      p = i;
    //   cout << p << endl;
      break;
    }
  }

  for (int i = p; i <= po; i += d) {
    string nbt = to_string(i);
    if (i % 10 == 0)
      continue;
    for (int j = 0; j < n / 2; j++) {
      swap(nbt[j], nbt[n - (j + 1)]);
    }
    int nb = stoi(nbt);
    if (nb % d == 0 && nb != i) {
      bool c = 0;
    //   cout << i << " obratno:" << nbt << endl;
      for (auto j = nt.begin(); j != nt.end(); j++) {
        if (i == *j || nb == *j) {
          c = 1;
          break;
        }
      }
      if(c)continue;
      nt.push_back(i);
      nt.push_back(nb);
      br++;
    }
  }
  cout << br << endl;
}