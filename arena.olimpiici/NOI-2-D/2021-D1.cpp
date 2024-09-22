#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
using LL = long long;
LL ch(LL a)
{
    while (a / 10 > 0)
    {
        LL sum = 0;
        while (a > 0)
        {
            sum += a % 10;
            a /= 10;
        }
        a = sum;
    }

    return a;
}
LL ch2(LL a, LL doCh)
{
    LL zap = ch(a), sum = zap;
    for (int i = 1; i < doCh; i++)
    {
        zap++;
        zap = zap / 10 + zap % 10;
        sum += zap;
    }
    return sum;
}
int main()
{
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        LL e, e2;
        cin >> e >> e2;
        LL sum = 0;
        for (LL j = e; j <= e2; j++)
        {
            if (j % 10 != 0)
                sum += ch(j);
            else
            {
                LL doCh=j / 10 == e2 / 10 ? min(j % 10, e2 % 10) : 10;
                cout<<doCh<<" "<<sum<<endl;
                sum += ch2(j,doCh );
                j += doCh;
            }
        }
        cout << sum << endl;
    }
    return 0;
}
/*

*/