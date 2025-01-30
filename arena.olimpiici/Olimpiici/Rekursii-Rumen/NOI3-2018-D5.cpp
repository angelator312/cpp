#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
using LL = long long;
const int K = 1e2 + 1; //Lupov pravilo
int n,k;
int sum=0,br=0,maxBr=-1;
int sibiraemi[K];

void backtracing() {
  if(sum>n)return;
  //cerr<<sum<<endl;
  if(sum==n)
  {
    maxBr=max(maxBr,br);
    return;
  }
  for(int i=0;i<k;i++)
  {
    ++br;
    sum+=sibiraemi[i];
    backtracing();
    --br;
    sum-=sibiraemi[i];
  }
  return;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n>>k;
  for(int i=0;i<k;i++)
   cin>>sibiraemi[i];

  backtracing();
  cout<<maxBr<<endl;
}