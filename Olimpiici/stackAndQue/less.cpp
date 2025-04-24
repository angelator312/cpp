#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define endl "\n"
using namespace std;
const int N=1e6+1;
int a[N];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    stack<int> indexes;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
        while (!indexes.empty()&& a[indexes.top()] >= a[i])
        {
            // cerr<<indexes.top()<<"\n";
            indexes.pop();
        }
        if (!indexes.empty())
            cout<<indexes.top()+1<<" ";
        else
            cout<<-1<<" ";
        indexes.push(i);
    }
    cout<<endl;

}