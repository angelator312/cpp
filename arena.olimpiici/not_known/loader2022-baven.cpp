#include <iostream>
using namespace std;

int search(int ts[], int n, int max, int min,int igni) {
  int _max = 0, maxi = -1;
  for (int i = 0; i < n; i++) {
    if (ts[i] <= max && ts[i] > _max && ts[i] > min && igni != i) {
      _max = ts[i];
      maxi = i;
    }
  }
  return maxi;
}
int main() {
  int n, a, b, m, br = 0;
  cin >> a >> b >> n;
  int ts[n];
  for (int i = 0; i < n; i++) {
    int xi;
    cin >> xi;
    ts[i] = xi;
  }

  do {
    int s = search(ts, n, 10000, b,-1);
    if (s != -1) {
      br++;
      ts[s] = 0;
    } else {
      int sb = search(ts, n, b, 0,-1);
      int sa = search(ts, n, a, 0,sb);
      if (sb != -1 && sa != -1) {
        br++;
        ts[sb] = 0;
        ts[sa] = 0;
      } else {
        if (sb == -1) {
          if (sa == -1) {
            break;
          } else {
            br++;
            ts[sa] = 0;
          }
        } else {
          br++;
          ts[sb] = 0;
        }
      }
    }
    // 123=A+b
    // a=21 b=45
    // b=50
  } while (true);
  cout << br << endl;
  return 0;
}