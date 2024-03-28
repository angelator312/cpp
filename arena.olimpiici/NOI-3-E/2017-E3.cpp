#include <bits/stdc++.h>
#include <algorithm>
#define endl "\n"
using namespace std;
using LL = long long;
int main()
{

    int n;

    cin >> n;
    int doTuk[n][5]{};
    for (int i = 1; i <= n; i++)
    {
        int e, e2, c;
        cin >> e >> e2 >> c;
        if (i > 0)
            doTuk[i][c - 1] = doTuk[i - 1][c - 1] + e * e2;
        else
            doTuk[i][c - 1] = e * e2;
        cout << doTuk[i][c - 1] << endl;
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; i++)
    {
        int e, j, c;
        cin >> e >> j >> c;
        cout << doTuk[j][c - 1] << endl;
        cout << doTuk[e][c - 1] << endl;
    }

    // cout << n << endl;

    return 0;
}