#include <algorithm>
#include <iostream>

using namespace std;
using LL=long long;

int main() {
  LL n,m,k;
  cin >> n >> m >> k;
  k*=1024;
  m+=60*n;
  m*=16;
  if (k>=m)
  {
    cout << "YES" << endl;
  }else
    cout<<"NO\n"<<m-k<<endl;

  return 0;
}
