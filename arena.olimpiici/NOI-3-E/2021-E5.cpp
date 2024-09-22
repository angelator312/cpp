#include <bits/stdc++.h>
using namespace std;
using LL = int; // int
const int N = 100;
int all[N];
void del(int a, set<int> &v)
{
    for (int i = 2; i * i <= a; i++)
    {
        if (a % i == 0)
        {
            v.insert(i);
            //  cout << i << endl;
            if (a / i != i)
            {
                v.insert(a / i);
            }
        }
    }
    // v.pop_back();
}

int main()
{
    LL n;
    cin >> n;
    LL mn = 1e9;   // 10^9
    set<int> a; // out

    // /*

    for (LL i = 0; i < n; i++)
    {
        cin >> all[i];
        mn = min(all[i], mn);
    }

    for (LL i = 2; i <= mn; i++)
    {
        int ost = all[0] % i;
        bool yes = 1;

        for (LL j = 1; j < n; j++)
        {
            if (ost != all[j] % i)
            {
                yes = 0;
                break;
            }
        }

        if (yes)
        {
            a.insert(i);
            // cout<<i<<endl;
            // cout<<a<<endl;
            del(i,a);
            // cout<<a<<endl;
        }
    }

    // */

    for (auto i = a.begin(); i != a.end(); i++)
    {
        cout << *i << " ";
    }

    cout << endl;
    return 0;
}