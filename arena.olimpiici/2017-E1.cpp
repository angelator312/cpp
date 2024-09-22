#include <iostream>

using namespace std;

int main() {
  char f;
  int a,b,k,e;

  cin >> e >> f;
  if (f=='A')
  {
    a=e;
  }else
  {
    b=e;
  }
  
  cin >> e >> f;
  if (f == 'A') {
    a = e;
    f = 'B';
  } else {
    b = e;
    f = 'A';
  }
  cin>>k;
  if (f=='A')
  {
    if (k>a)
    {
      cout << a << endl;
    }else
      cout << k << endl;
    
  }else
  {
    if (k > b) {
      cout << min(k-b,a) << endl;
    } else
      cout << 0 << endl;
  }
  
  return 0;
}
