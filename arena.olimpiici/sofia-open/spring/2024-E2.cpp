#include <bits/stdc++.h>
#include <algorithm>
#define endl "\n"
using namespace std;
using LL = long long;
int main()
{
    LL n, br = 0;
    cin >> n;
    int m[n + 2];
    for (int i = 1; i < n; i++)
    {
        cin >> m[i];
    }
    cin >> m[0];

    for (int i = 1; i <= n; i++)
    {
        
        // int br2=br;
        while (m[i] % 2 == 1 && m[i - 1] > 0 && m[i] > 0 && i == 1)
        {
            m[i]--;
            m[i - 1]--;
            br++;
        }
        while (m[i] % 2 == 1 && m[i + 1] > 0 && m[i] > 0)
        {
            m[i]--;
            m[i + 1]--;
            br++;
        }
        while (m[i] > 0)
        {
            m[i] -= 2;
            br++;
        }
        //cout << "[" << i << "] " << br-br2 << endl;
        if (i == 1)
            m[n] = m[0];
    }
    cout << br << endl;
    return 0;
}