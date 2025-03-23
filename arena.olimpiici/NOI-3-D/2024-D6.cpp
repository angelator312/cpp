#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
using namespace std;
int br=1,a;
vector<int> ins;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, k;
  cin >> n >> k;
  ins.resize(n+1);
  ins[n]=-1;
  for (int i = 0; i < n; i++) {
    cin>>ins[i];
  }
  sort(ins.begin(),ins.end(),greater<int>());
  for (int i = 0; i < n;)
  {
    int j=i;
    while(ins[j] ==ins[i])
    {
      ++j;
    }
    if(br==k ||j==n)
    {
      // cerr<<i<<" "<<j<<endl;
      cout<<ins[i]<<endl;
      return 0;
    }
    i=j;
    ++br;
  }
  
  cout<<ins[n-1]<<endl;
  return 0;
}
