#include <algorithm>
#include <climits>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
const int N = 1e6;
const int A = 1e9;
int redica[N];
stack<int> redStack;
stack<int> outs;
int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(nullptr);
  cin.tie(nullptr);
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i)
  {
    cin>>redica[i];
  }
  for (int i = n-1; i >=0; --i)
  {
    while (!redStack.empty() && redStack.top()<=redica[i])
    {
      redStack.pop();
    }
    if(redStack.empty())
    {
      outs.push(redica[i]);
    }
    redStack.push(redica[i]);
  }
  
  while (!outs.empty())
  {
    cout<< outs.top()<<" ";
    outs.pop();
  }
  cout<< endl;
  
  
}