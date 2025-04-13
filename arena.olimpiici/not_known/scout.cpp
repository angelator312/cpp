#include <iostream>
#include <vector>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int sc[n], sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> sc[i];
    sum += sc[i];
  }
  bool ok = 0;
  int d = sum / k, ost = 0,subr=0;
  for (int i = 0; i <= n - 2; i++) {
    int e = sc[i], f = (e + ost) / d;
    if (f > 0 && !ok) {
      if (subr + f < k) {
        subr += f;
      } else if (subr + f == k) {
        subr += f;
        ok = 1;
      } else {
        f = k - subr;
        subr = k;
        ok = 1;
      }
    } else if (f > 0 && ok) {
      f = 0;
    }
    cout << e - f << " ";
    ost = (e + ost) % d;
  }
  int e = sc[n - 1],f = (e + ost) / d;
  if (ok) {
    cout << e << endl;
  }else{
    if (f > 0) {
      if (subr + f < k) {
        subr += f;
      } else if (subr + f == k) {
        subr += f;
        ok = 1;
      } else {
        f = k - subr;
        subr = k;
        ok = 1;
      }
    }
    cout<<e-f<<endl;
  }
}