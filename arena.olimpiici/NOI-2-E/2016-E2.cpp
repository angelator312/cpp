#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main()
{
    LL i, b, n, br = 0;
    cin >> n;
    // cout<<bombIz<<endl;
    // if (n%2)
    // {
    //     cout<<0<<endl;
    //     return 0;
    // }

    for (int i = 1; i <= (n + 1) / 2; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            b = (i - 1) * j + (j - 1) * i;
            // b = (i - 1) * j * 2;
            if (i * 2 + b + j * 2 == n)
            {
                // cout << i * 2 << " " << j * 2 << " " << b << endl;
                br++;
            }
        }
    }

    cout << br << endl;
    return 0;
}