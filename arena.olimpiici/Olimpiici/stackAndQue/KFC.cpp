#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;
const int X = 3e5 + 2;
int used[X];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);
  queue<int> q;
  int n;
  cin >> n;
  while(n-->0)
  {
    int t;
    cin >> t;
    if(t==1)
    {
      int x;
      cin >> x;
      q.push(x);
    }
    else if(t==2)
    {
      int x;
      cin >> x;
      used[x] = 1;
    }
    while (!q.empty()&& used[q.front()])
    {
      q.pop();
    }
    if(!q.empty())
    {
      cout << q.front() << " ";
    }
    else
    {
      cout << "-1 ";
    }

  }
  
  cout << endl;
}