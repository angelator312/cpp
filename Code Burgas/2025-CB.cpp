#include <iostream>
using namespace std;
using LL = long long;

int main() {
  int a, b, c, d, x;
  cin >> a >> b >> c >> d >> x;
  double znamenatel = (c*x + d);
  if(znamenatel==0)
  {
    cout << "ZERO ERROR\n";
    return 0;
  }
  double velocity = (a*x + b) / znamenatel;
  // cerr<<znamenatel<<endl;
  // cerr<<fixed<<velocity<<endl;
  if(velocity!=int(velocity))
  {
    cout << "NAN ERROR\n";
    return 0;
  }
  cout<<velocity<<" km/h\n";
  return 0;
}