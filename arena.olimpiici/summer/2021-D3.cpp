#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    vector<int> c;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++)
    {
        int e;
        cin>>e;
        for (int j = 0; j < n; j++)
            c.push_back(e+a[j]);
    }

    sort(c.begin(),c.end(),greater<int>());
    cout << c[k-1] << endl;

    // cout << br << endl;
    return 0;
}