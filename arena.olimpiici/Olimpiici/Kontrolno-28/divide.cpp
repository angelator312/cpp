#include <iostream>
#include <vector>
using namespace std;
using LL = long long;
const int A = 2e6 + 2, N = 1e5 + 2; // Lupi pravilo
int min_div[A];

int redica[N];
inline void eratostenFill() {
  min_div[0] = 1;
  min_div[1] = 1;
  for (int i = 2; i <= A; i += 2) {
    min_div[i] = 2;
  }
  for (int i = 3; i <= 1409; i += 2) {
    if (min_div[i])
      continue;
    min_div[i] = i;
    // cerr<<i<<endl;
    for (int j = i * i; j <= A; j += i) {
      min_div[j] = i;
    }
  }
  for (int i = 1423; i <= A; i += 2) {
    if (min_div[i])
      continue;
    min_div[i] = i;
  }
}

int main() {
  int n, mxChislo = 0;
  eratostenFill();
  scanf("%d", &n);
  for (int i = 0, e; i < n; ++i) {
    scanf("%d", &redica[i]);
    mxChislo = max(redica[i], mxChislo);
  }
  int br = 0;
  for (int i = 0; i < n; ++i) {
    while (redica[i] > 1) {
      int e = min_div[redica[i]];
      int j = i+1;
      while (j < n && redica[j] % e == 0) {
        redica[j] /= e;
        ++j;
      }
      // cerr << i << " " <<j<<" "<< e << endl;
      ++br;
      redica[i] /= e;
    }
  }
  printf("%d", br);
  printf("\n");
}
