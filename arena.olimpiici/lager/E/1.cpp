#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int cnt[n + 1]{};
    for (int i = 2; i <= n; i++)
    {
        if (!cnt[i])
            for (int k = i; k <= n; k += i)
                cnt[k] = i;
    }

    for (int i = 0; i < n + 1; i++)
    {
        cout << cnt[i] << endl;
    }
}