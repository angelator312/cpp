#include <algorithm>
#include <climits>
#include <iostream>
#include <stack>
#include <vector>
#define jOk nJ < m &&nJ >= 0
#define iOk nI < n &&nI >= 0
using namespace std;
using pI=pair<int,int>;
const int N = 2e2 + 2;
const int M = 2e2 + 2;
int tochki[N][M];
int br = 0;
int n, a, b;
int maxX, maxY;
vector<pI> pairs;
int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(nullptr);
  cin.tie(nullptr);
  cin >> n >> a >> b;
  int x, y;
  for (int i = 0; i < n; ++i) {
    cin >> x >> y;
    tochki[y][x]++;
    maxX = max(maxX, x);
    maxY = max(maxY, y);
    pairs.push_back(make_pair(y,x));
  }

  for (int i = 0; i <=maxY+b; ++i)
  {
    for (int j = 0; j < maxX+a; ++j) {
      tochki[i][j]+=tochki[i-1][j]+tochki[i][j-1]-tochki[i-1][j-1];
      //cerr<<tochki[i][j]<<" ";
    }
    //cerr<<endl;
  }
  
  for (auto e:pairs)
  {
    int i = e.first;
    int j = e.second;
    int ch = tochki[i+b][j+a] - tochki[i-1][j+a] - tochki[i+b][j-1]+tochki[i-1][j-1];
    //cerr<<i<<" "<<j<<" "<<ch<<endl;
    br = max(br, ch);
  }
  
  
  cout << br << endl;
}

/*

2 4
0 1 1 0
0 0 1 1

*/