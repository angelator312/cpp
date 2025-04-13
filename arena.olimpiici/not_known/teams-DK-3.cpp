#include <iostream>
using namespace std;

int main ()
{ long long m,n;
  cin >> m >> n;

  if(m>n) swap(m,n);
  cout << min(m,(m+n)/3) << endl;

  return 0;
}








