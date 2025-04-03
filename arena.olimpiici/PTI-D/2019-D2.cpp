#include <iostream>
#include <vector>
using namespace std;
int n,k;
inline string del(string a)
{

}
int main() {
  cin >> n >>k;
  string s;
  cin>>s;
  cout << del(s.substr(0, n));
  cout << del(s.substr(n, n));
  cout << del(s.substr(2*n, n));
  cout<<endl;
}