#include <bits/stdc++.h>
using namespace std;

int dels(long long a)
{
    int br = 0;
    for (long long i = 1; i * i <= a; i++)
    {
        if (a % i != 0)
            continue;
        if (i * i == a)
            br++;
        else
            br += 2;
    }
    return br;
}

int main()
{
    long long a;
    cin >> a;
    cout << dels(a) << endl;
}