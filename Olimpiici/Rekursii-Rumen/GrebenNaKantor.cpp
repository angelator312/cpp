#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
using LL = long long;
const int N = 1e8 + 1;
const int P = 255 + 1;
int n, p;

void rekursia(const int& a,const int& offset)
{
  if(a==1)
  {
    cout<<string(offset+1,'*')<<endl;
    return;
  }
  rekursia(a-1,offset+1);
  string s=string(offset+1,'*');
  for(int i=0;i<pow(3,a-2);i++)
  {
    cout<<s<<endl;
  }
  rekursia(a-1,offset+1);  
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n;
  rekursia(n,0);
  //cout<<endl;
}