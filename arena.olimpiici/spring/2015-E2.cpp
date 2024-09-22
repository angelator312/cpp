#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main()
{
    int m, n, u, d, l;
    cin >> m >> n >> u >> d >> l;
    int tcena = INT32_MAX;
    int tcena2 = INT32_MAX;

    for (int i = 0; i < l; i++)
    {
        int a;
        cin >> a;
        if (a >= n)
        {
            tcena = min(tcena, (a - n) * d);
            // cout<<tcena<<endl;
        }
        else 
        {
            tcena = min(tcena, (n - a) * u);
        }

        if (a >= m)
        {
            tcena2 = min(tcena2, (a - m) * u);
            // cout<<(a-m)*u<<endl;
        }
        else 
        {
            tcena2 = min(tcena2, (m - a) * d);
        }
    }
    if (l == 0)
    {
        if (m >= n)
        {
            tcena = (m - n) * d;
        }
        else 
        {
            tcena = (n - m) * u;
        }
        tcena2 = 0;
    }
    else
    {
        if (m >= n)
        {
            if (tcena + tcena2 > (m - n) * d)
            {
                tcena = (m - n) * d;
                tcena2 = 0;
            }
        }
        else 
        {
            if (tcena + tcena2 > (n - m) * u)
            {
                tcena = (n - m) * u;
                tcena2 = 0;
            }
        }
    }
    cout << tcena + tcena2 << endl;
    return 0;
}
