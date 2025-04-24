#include <cmath>
#include <iostream>
using namespace std;
using LL = long long;
const LL A=1e18+1;
int main() {
  LL n;
  cin >> n;
  LL ans = 0,r=1e9+2,l=0,mid=0 ;
  while (l<=r) {
    mid=l+(r-l)/2;
    if(mid*mid<=n) {
      ans=mid;
      l=mid+1;
    } else {
      r=mid-1;
    }
  }
  cout << (ans * ans == n ? ans : 0) << endl;
  return 0;
}