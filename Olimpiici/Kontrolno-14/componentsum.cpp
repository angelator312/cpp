#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
using LL = long long;
const int N = 1e3 + 1;
const int M = 1e3 + 1;

bool zastrihovani[N][M];
int chisla[N][M];
int plusI[] = {0, 0, 1, -1};
int plusJ[] = {1, -1, 0, 0};
int n, m;
int maxSum = 0;
int pogledni(int i, int j)
{

  if (zastrihovani[i][j]) {
    return 0;
  }
  //cerr << "    [" << i << "][" << j << "]" << endl;
  zastrihovani[i][j] = true;
  int sum = chisla[i][j];
  for(int p=0;p<4;++p)
  {
    int ni = i + plusI[p];
    int nj = j + plusJ[p];
    if(ni>=0 && ni<n && nj>=0 && nj<m)
    {
      sum+=pogledni(ni,nj);
    }
  }
  
  return sum;
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> chisla[i][j];
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> zastrihovani[i][j];
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
       //cerr<<"["<<i<<"]["<<j<<"]"<<endl;
       int sum=pogledni(i,j);
       //cerr<<sum<<endl;
       maxSum=max(maxSum, sum);
    }
  }
  cout<<maxSum<<endl;
}