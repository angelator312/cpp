#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
int cnt[N]{};
int del[N]{};
int main()
{
    int q;
    cin >> q;

    for (int i = 1; i <= N; i++)
    {
        del[i]=del[i-1];
        if(cnt[i]>=i)del[i]++;
        for (int k = i * 2; k <= N; k += i)
            cnt[k] += i;
    }
    for (int i = 0; i < q; i++)
    {
        int l, r,br=0;
        cin >> l >> r;
        // cout<<r<<l<<endl;
        br=del[r]-del[l-1];
        // for (int e = l; e <= r; e++)
        // {
        //     // cout<<cnt[e]<<endl;
        //     if(cnt[e]>=e)br++;
        // }

        cout << br << endl;
    }
    // for (int i = 0; i < n + 1; i++)
    // {
    //     cout << cnt[i] << endl;
    // }
}