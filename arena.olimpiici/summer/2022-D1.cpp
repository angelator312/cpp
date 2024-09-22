#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int plusM[n+1][2]{}; // plus[i][0] - on left ; plus[i][1] - on right;
    int a[m+1][2]{};     // a[i][0] - on left ; a[i][1] - on right;
    int mxLeft = 0, mxRight = 0;

    for (int i = 1; i <= n; i++)
    {
        plusM[i][0] = 0;
        plusM[i][1] = 0;
        // cout<<plusM[i][1]<<endl;
    }

    for (int i = 0; i < m; i++)
    {
        int e;
        char e2;
        cin >> e >> e2;
        // cout << plusM[e][1] << endl;
        // a[i][0]=0;
        // a[i][1]=0;
        if (e2 == 'l')
        {
            // cout<<1<<endl;
            // a[i][0]=0;
            plusM[e][1] = max(2, plusM[e][1]);
            for (int j = 1; j < e; j++)
            {
                // cout<<" "<<j<<endl;
                plusM[j][1] = max(1, plusM[j][1]);
            }
        }
        else if (e2 == 'r')
        {
            // cout<<2<<endl;
            plusM[e][0] = max(2, plusM[e][0]);
            for (int j = e + 1; j < n; j++)
            {
                // cout<<" "<<j<<endl;
                plusM[j][0] = max(2, plusM[j][0]);
            }
        }
        else
        {
            plusM[e][0] = max(1, plusM[e][0]);
            for (int j = e + 1; j < n; j++)
            {
                plusM[j][0] = max(1, plusM[j][0]);
            }
            plusM[e][1] = max(1, plusM[e][1]);
            for (int j = 1; j < e; j++)
            {
                plusM[j][1] = max(1, plusM[j][1]);
            }
        }
        // cout<<plusM[e][0]<<endl;
        mxLeft = max(mxLeft, e + plusM[e][0]);
        // a[i][0] = ;
        // cout<<plusM[e][1]<<endl;
        mxRight = max(mxRight,(n - e) + plusM[e][1] );
        // a[i][1] = ;
        // a[i][1]++;
    }

    cout << max(min(mxLeft, mxRight),1) << endl;
    return 0;
}