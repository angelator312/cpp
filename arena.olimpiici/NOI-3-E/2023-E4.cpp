#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
using LL = long long;
bool del2(int a)
{
    return a % 2;
}
short pr(int n, int &br)
{
    if ((n - 1) % 2)
    {
        if (pr(n / 2, ++br))
            return 1;
        else
            return 0;
    }
    else
    {
        if (pr(n / 2, ++br))
            return 1;
        else
            return 0;
    }
}
int main()
{
    LL n, br = 0;
    // cout<<dels(6)<<endl;
    vector<short> a;
    cin >> n;
    // cout << pr(n) << endl;
    while (0 < n)
        if (del2(n))
        {
            br++;
            a.push_back(2);
            n--;
            n /= 2;
        }
        else
        {
            br++;
            a.push_back(1);
            n /= 2;
        }
    if (br == 0)
    {
        cout << -1 << endl;
        return 0;
    }

    cout << br << endl;
    for (int i = a.size()-1; i >=0 ; i--)
    {
        cout << a[i] << " ";
    }

    cout << endl;
    // cout << dels(n) << " " << dels(k) << endl;
    return 0;
}
/*

*/