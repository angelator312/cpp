#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        int e;
        cin>>e;
        q.push(e);
    }
    for (int i = 0; i < n; i++)
    {
        cout <<q.front()<< " ";
        q.pop();
    }
    
    cout << endl;
}