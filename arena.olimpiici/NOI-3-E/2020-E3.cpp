#include <bits/stdc++.h>
#include <algorithm>
#define endl "\n"
using namespace std;
using LL = long long;
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n;
    cin >> m;
    bool port[m+3]{};

    for (int i = 0; i < n; i++)
    {
        int e;
        cin >> e;
        port[e]=1;
        port[e-1]=1;
    }

    int br = 0;
    
    for (int i = 1; i < m; i++)
    {
        if(!port[i])br++;        
    }

    cout << br << endl;

    return 0;
}