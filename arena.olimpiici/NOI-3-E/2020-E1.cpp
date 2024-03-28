#include <bits/stdc++.h>
#include <algorithm>
#define endl "\n"
using namespace std;
using LL = long long;
int main()
{

    int n;
    int ost;
    int d = 0;

    cin >> n;

    if (n % 7 == 0 || n % 3 == 0 || n % 11 == 0|| n % 13 == 0)
    {
        cout << "NO" << endl;
        return 0;
    }
    if (n == 1)
    {
        cout << 0 << endl;
        return 0;
    }
    // cout << 1 << endl;
    ost = 1;
    while (ost > 0)
    {
        if(d>31)
        {
            cout<<"NO"<<endl;
            return 0;
        }
        ost *= 10;
        // cout << ost << endl;
        ost =ost % n;
        // cout << ost << endl;
        d++;
    }
    cout << d << endl;

    return 0;
}