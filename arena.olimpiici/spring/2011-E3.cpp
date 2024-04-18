#include <bits/stdc++.h>
using namespace std;
using LL = long long;

bool chetnoByde(bool a, bool b) // 0- chetno, 1-nechetno
{
    // cout<<a<<" "<<b<<endl;
    // pri umnozhenie
    if (!a || !b)
        return 1;
    else
        return 0;
}

LL sum(LL a, LL b)
{
    LL len = (b - a) + 1;
    if (len % 2)
    {
        len--;
        len /= 2;
        // cout<<b-1+a<<endl;
        return b + (((b - 1) + a) * len);
    }
    else
    {
        len /= 2;
        return (b + a) * len;
    }
}

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        LL n, m, k;
        cin >> n >> m >> k;
        if (chetnoByde(k % 2, sum(n, m) % 2))
        {
            // cout<<sum(n,m)<<endl;
            cout << "YES" << endl;
        }
        else
            cout << "NO" << endl;
    }

    return 0;
}