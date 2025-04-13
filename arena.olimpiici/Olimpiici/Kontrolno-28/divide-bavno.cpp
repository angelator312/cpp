#include <iostream>
#include <vector>
using namespace std;
using LL = long long;
const int A = 2e6 + 2, N = 1e5 + 2; // Lupi pravilo
int min_div[A];

vector<int> prosti;
int redica[N];
inline void eratostenFill() {
  prosti.push_back(2);
  for (int i = 4; i <= A; i += 2) {
    min_div[i] = false;
  }
  for (int i = 3; i <= 1409; i += 2) {
    if (min_div[i])
      continue;
    prosti.push_back(i);
    // cerr<<i<<endl;
    for (int j = i * i; j <= A; j += i) {
      min_div[j] = i;
    }
  }
  for (int i = 1423; i <= A; i += 2) {
    if (min_div[i])
      continue;
    prosti.push_back(i);
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
  for (auto e : prosti) {
    if (e > mxChislo)
      break;
    int i = 0;
    while (i < n) {
      if (redica[i] % e > 0) {
        ++i;
        continue;
      }
      // povtorenie = true;
      int j = i;
      while (j < n && redica[j] % e == 0) {
        redica[j] /= e;
        ++j;
      }
      ++br;
      if (redica[i] % e > 0)
        ++i;
    }
  }
  printf("%d", br);
  printf("\n");
}