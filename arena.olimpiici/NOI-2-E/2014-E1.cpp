#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main()
{
    int a, b, c, d, x, k, stol = 0, masi = 0, vz = 0;
    cin >> a >> b >> c >> d >> x >> k;
    b += a * 100;
    d += c * 100;
    if (d > b)
    {
        swap(d, b);
    }
    // cout<<d<<" "<<b<<endl;
    b -= 100;
    while (b >= x)
    {
        b -= x;
        stol += 2;
        vz++;
        if (vz == k)
        {
            vz = 0;
            masi++;
            b -= 50;
        }
    }
    if (vz > 0)
    {
        masi++;
    }

    cout << stol << endl;
    cout << masi << endl;
    return 0;
}