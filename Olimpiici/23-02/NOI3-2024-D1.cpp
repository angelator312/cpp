#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
const int N = 5e3 + 5;
const int M = 5e3 + 5;
bool stv[N];
int n, m, br = 1;
int brL = 0, brStv = 0;

int brNaRed(double red) {
  int redI=red;
  brL = 0;
  brStv = 0;
  for (int i = 0; i < redI; ++i) {
    stv[i] = (__gcd(i, redI) == 1);
    brStv += stv[i];
  }
  if (red <= m) {
    double del = m / red;
    int delI = del;
    brL += delI * brStv;
    // cerr<<fixed<<del<<" "<<delI<<endl;
    if (del != delI) {
      for (int i = 0; i < m - delI * red; ++i) {
        brL += stv[i];
      }
    }
  } else {
    for (int i = 0; i < m; i++) {
      brL += stv[i];
    }
  }
//   cerr << red << " " << brL << endl;
  return brL;
}
int main() {
  cin >> n >> m;
  for (double i = 1.0; i < n; ++i) {
    br += brNaRed(i);
  }
  cout << br << endl;
}