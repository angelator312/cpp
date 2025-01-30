#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
using LL = long long;
const int N = 1e8 + 1;
const int P = 255 + 1;
int n, p;

void rekursia(const int &a) {
  if (a == 0)
  {
    cout<<"X";
    return ;
  }
   
  rekursia(a - 1);
  cout<<string(pow(3,a-1),'O');
  rekursia(a - 1);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n;
  rekursia(n);
  cout<<endl;
}