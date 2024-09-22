#include <bits/stdc++.h>
using namespace std;
using ul = long long;

int main()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    bool izp[n]{};
    int ind = n - 1;
    for (int i = 0; i < n; i++)
    {
        if (k <= 0)
            break;
        if (s[i] == '0')
            continue;

        while (s[ind] == '1' && ind >= 0)
            ind--;
        if (izp[i] || izp[ind])
            continue;

        // cout << i << " " << ind << endl;
        s[ind] = '1';
        s[i] = '0';
        izp[ind]=1;
        izp[i]=1;
        k--;
    }
    cout << s << endl;

    return 0;
}