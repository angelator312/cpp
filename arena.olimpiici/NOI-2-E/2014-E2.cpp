#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main()
{
    LL n, f, s, m, sek = 0;
    cin >> n >> f;
    // cout<<m+(int)(s>0)<<endl;
    for (int i = 0; i < n; i++)
    {
        cin >> m >> s;
        if (m + (LL)(s > 0) > f)
        {
            // cout << i << endl;
            sek += (m - f) * 60;
            sek += s;
            f = 0;
        }
        else
            f -= m + (LL)(s > 0);
    }

    cout << sek << endl;
    return 0;
}