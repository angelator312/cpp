#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;

long long prefix[N];
int main()
{
    int n;
    cin >> n;
    long long k, a[n];
    cin >> k;
    for (int i = 1; i <= n; i++)
    {
        long long e;
        cin >> e;
        prefix[i] = prefix[i - 1] + e;
        a[i] = e;
        // cout<<prefix[i]<<endl;
    }
    for (int i = 0; i < k; i++)
    {
        long long e, e2, k2;
        cin >> e >> e2 >> k2;
        if (e > e2)
            swap(e, e2);
        long long sum = prefix[e2] - prefix[e - 1];
        while (k2 > 0)
        {
            long long x;
            cin >> x;
            // cout << x * x << endl;
            if (x >= e && x <= e2)
            {
                /* code */

                sum -= a[x];
            }
            sum += a[x] * a[x];
            // cout<<sum<<endl;
            k2--;
        }

        cout << sum << endl;
    }

    return 0;
}