#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 9;

int a[N];

int main()
{
    int n, m;
    cin >> n >> m;

    int nm = 0, nmI = n * m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int umn = i * j, e = 0;
            string s = to_string(umn);
            for (char k : s)
            {
                e = k - '0';
                // if (e == 2)
                //     cout << i << endl;
                a[e]++;
                if (a[e] > nm)
                {
                    nm = a[e];
                    nmI = e;
                }
                else if (a[e] == nm && nmI > e)
                {
                    nmI = e;
                }
            }
        }
    }
    cout << nmI << " " << nm << endl;
    // cout << a[2] << endl;
    return 0;
}