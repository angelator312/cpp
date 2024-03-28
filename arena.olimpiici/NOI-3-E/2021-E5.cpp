#include <bits/stdc++.h>
using namespace std;
using LL = int; // int
const int N = 100;
int all[N];
int main()
{
    LL n;
    cin >> n;
    LL mx = 0, mn = 1e9 + 1, mn2 = 1e9 + 1;

    // /*

    for (LL i = 0; i < n; i++)
    {
        cin >> all[i];
        mx = max(all[i], mx);
        if (all[i] < mn)
            mn2 = mn, mn = all[i];
    }
    int v = mn2 - mn;
    for (LL i = 2; i <= v; i++)
    {
        int ost = all[0] % i;
        bool yes = 1;
        if (ost > mn)
            continue;
        for (LL j = 1; j < n; j++)
        {
            if (ost != all[j] % i)
            {
                yes = 0;
                break;
            }
        }

        if (yes)
        {
            cout << i << " ";
        }
    }

    // */

    cout << endl;
    return 0;
}