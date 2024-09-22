#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int cnt[n + 1]{}, mx = 0, chis = 0;
    for (int i = 1; i <= n; i++)
    {

        for (int k = i; k <= n; k += i)
            cnt[k]++;
        if (cnt[i] > mx)
        {
            chis = i;
            mx = cnt[i];
        }
    }
    // for (int i = 0; i < n + 1; i++)
    // {
    //     cout << cnt[i] << endl;
    // }
    cout<<chis<<endl;
    cout<<mx<<endl;
}