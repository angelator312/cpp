#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
typedef unsigned long long ul;
typedef vector<int> Vi;
Vi dells(ul A, ul B) {
  Vi out;
  out.push_back(1);
  for (ul i = 2; i <= gcd(A, B); i++) {
    //cout << (A % i + B % i) << endl;
    if ((A % i + B % i) == 0)
      out.push_back(i);
  }
  return out;
}
int main() {
  ul A, B;
  cin >> A >> B;
  Vi d = dells(A, B);
  //cout << gcd(A, B) << d.size() << endl;
  for (long long i = 0; i < d.size(); i++)
    cout << d[i] << " " << A / d[i] << " " << B / d[i] << endl;
}