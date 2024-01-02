#include <iostream>
#include <cmath>
#include <math.h>
using namespace std;
int mx = 0, mn = 30, all = 0;
int main()
{
    int n, m, k, tcena = 0;
    bool s = 0;
    cin >> n >> m >> k;
    if (k > n)
    {
        s = true;
        // swap(k,n);
    }
    if (s)
    {
        while (k % n > 0)
        {
            k = k - k % n;
        }
    }
    else
        while (n % k > 0)
        {
            n = n - n % k;
        }
    if (s)
    {
        k /= n;
        n = 1;
        tcena = (m + k - 1) / k;
    }
    else
    {
        int x = (n + k - 1) / k;
        tcena = m * x;
    }

    cout << tcena << endl;
    return 0;
}