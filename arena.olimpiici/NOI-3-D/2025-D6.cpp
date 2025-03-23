#include <cmath>
#include <iostream>
using namespace std;
using LL = int;
const int N = 1e7 + 4;
int redica[N];
int idxM[N];
inline LL min(LL a, LL b) { return a < b ? a : b; }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  LL n, x, y, z, m,k;
  cin >> n >> k;
  cin >> redica[1] >> redica[2] >> x >> y >> z >> m;
  for (int i = 3; i <= n; ++i) {
    redica[i] = (x * redica[i - 2] + y * redica[i - 1] + z) % m;
  }
  for (int i = 0,j=0,sum=0; i < n;) {
    while (j+1<=n&&sum<k)
    {
      sum += redica[j++];
    }
    if(sum>=k)
    {
      idxM[i] = j;
    }else idxM[i] = n+1;
    sum -= redica[i++];
  }
  idxM[n + 1] = idxM[n + 2] = n + 1;
  int out=0;
  for (int l = 1; l <=n ; ++l)
  {
    int m=idxM[l];
    int r=idxM[m+1];
    out+=n-r+1;
  }
  
  cout << out << endl;
  return 0;
}