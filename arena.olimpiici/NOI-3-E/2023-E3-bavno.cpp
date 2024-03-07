#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
using LL = long long;
LL dels(LL a)
{
    LL br = 2, sq = floor(sqrt(a));
    // cout<<sq<<endl;
    if (a == 1)
        return 1;
    for (int i = 2; i <= sq; i++)
        if (a % i == 0)
        {
            br++;
            if (i != a / i)
                br++;
        }

    return br;
}
int main()
{
    LL n, k, br = 0;
    // cout<<dels(6)<<endl;
    cin >> n >> k;
    LL pl = 1;
    if (n % k == 0)
        br++;
    // if (n % 2 == 0)
    //     pl = 2;

    for (LL i = 2; i <= n; i += pl)
    {
        LL d1 = dels(i);
        for (LL j = i; j <= n; j++)
        {
            LL d2 = dels(j);
            if (k * d1 * d2 == i * j)
            {
                br++;
            };
        }
    }

    cout << br << endl;
    return 0;
}
/*

*/