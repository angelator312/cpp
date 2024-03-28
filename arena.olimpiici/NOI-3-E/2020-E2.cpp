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

    int d;
    cin >> d;
    int ost[d]{};
    int n, m;

    cin >> n;


    for (int i = 0; i < n; i++)
    {
        int e;
        cin >> e;
        e %= d;
        ost[e]++;
    }

    cin >> m;

    int br = 0;
    for (int i = 0; i < m; i++)
    {
        int e;
        cin >> e;
        e %= d;
        if (e == 0)
            br += ost[0];
        else
        {
            br += ost[d - e];
        }
    }

    cout << br << endl;

    return 0;
}