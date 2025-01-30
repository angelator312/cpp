#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#define F first.first
#define S first.second
#define T second

using namespace std;
using LL = long long;
using p3I = pair<pair<int, int>, int>;
using v3PI = vector<p3I>;
int n, posetiteli,maxPosetiteli=1;
v3PI pIn, pOut;
int e, e1, e2;
char forIn;
void printOut(const p3I &forPairs) {
    cerr<<forPairs.F<<":"<<forPairs.S<<":"<<forPairs.T;
}

void getIn(v3PI &forPairs) {
  cin >> e;
  cin >> forIn;
  cin >> e1;
  cin >> forIn;
  cin >> e2;
  p3I a;
  a.F = e;
  a.S = e1;
  a.T = e2;
  forPairs.push_back(a);
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    getIn(pIn);
    getIn(pOut);
  }
  sort(pOut.begin(), pOut.end());
  sort(pIn.begin(), pIn.end());
  int pokazalkaIn = 0;
  int pokazalkaOut = 0;
  while (pokazalkaIn < n && pokazalkaOut < n)
  {
    if(pIn[pokazalkaIn]>pOut[pokazalkaOut])
    {
        pokazalkaOut++;
        posetiteli--;
    }

    else if (pIn[pokazalkaIn] < pOut[pokazalkaOut]) {
      pokazalkaIn++;
      posetiteli++;
      maxPosetiteli=max(maxPosetiteli,posetiteli);
    }
    else
    {
        pokazalkaIn++;
        pokazalkaOut++;
    }
  }
  maxPosetiteli=max(maxPosetiteli,posetiteli);
  
  cout<<maxPosetiteli<<endl;
}