#include <bits/stdc++.h>
using namespace std;

// (n+1)×(n÷2)+p=S
// n*(n/2) + (n/2) = S-p
// (n/2)(n+1) = S-p

int main()
{
    long long x;
    cin >> x;

    for (int i = 1; i < x; i++)
    {
        if (i % 2 == 0)
        {
            cout << (i / 2) * (i + 1) << " : ";
            cout << i << endl;
        }
        else
        {

            cout << (((i - 1) / 2) * i) + i << " : ";
            cout << i << endl;
        }
    }

    return 0;
}