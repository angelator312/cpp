#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 1e7 + 3;
int m2[N];
LL k;
bool match(int l, int r, int m[])
{
    LL sum = 0;
    for (int i = l; i < r; i++)
    {
        for (int j = i + 1; j <= r; j++)
        {
            // cout<<i<<" "<<j<<endl;
            // cout<<m[i]*m[j]<<endl;
            sum += m[i] * m[j];
        }
    }
    if (sum >= k)
        return true;
    return false;
}

bool match2(int l, int r, int m[])
{

    if (m2[r] - m2[l] >= k)
        return true;
    return false;
}

int main()
{
    int n;
    LL br = 0;
    cin >> n >> k;
    int m[n];
    // int mDv[n][n]{};
    // cout << 1 << endl;
    int st = -1;
    for (int i = 0; i < n; i++)
    {
        cin >> m[i];
        if (i > 0)
        {
            m2[i] = m2[i - 1];
            if (m[i] == 0)
                continue;
            for (int j = 0; j < i; j++)
            {
                m2[i] += m[i] * m[j];
            }
        }

        // cout<<!!m[i]<<endl;
        if (st == -1 && m[i] > 0)
            st = i;
    }
    st = max(st, 0);
    // cout<<st<<endl;
    // cout << match(0, 4, m) << endl;
    // /*

    // for (int i = 0; i < n; i++)
    // {
    //     cout << m2[i] << endl;
    // }

    for (int r = st + 1; r < n; r++)
    {
        // if (!match(st, r, m))
        //     continue;
        // br+=st;
        // cout<<r<<endl;
        for (int l = r - 1; l > st - 1; l--)
        {
            // cout << r << " " << l << endl;
            bool e = match2(l, r, m);
            if (l + 1 == r)
                if (m[l] * m[r] >= k)
                {
                    // cout << m[l] << endl;
                    e = 1;
                }
                else
                    e = 0;
            if (m[r] == 0 || m[l]==0)
                e=match(l,r,m);
            if (e)
            {
                cout << r << " " << l << endl;
                cout<<m2[r]<<endl;
                cout<<m2[l]<<endl;

                br += l + 1;
                break;
            }
            // br += e;
        }
    }
    // */

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         if(i==j)continue;
    //         cout <<i<<" "<<j << endl;
    //         cout << mDv[i][j] << endl;
    //     }
    // }

    cout << br << endl;
    return 0;
}