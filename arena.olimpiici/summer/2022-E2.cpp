#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main()
{
    LL len = 0, edBr = 0;
    char a;
    vector<int> ed;

    while (cin >> a)
    {
        // setbit(len, a - '0');
        if (a == '1')
        {
            // cout<<len<<endl;
            ed.push_back(len);
            edBr++;
        }
        len++;
        // cin>>a;
    }

    LL b = 0, br = 0;
    for (int i = edBr - 1; i >= 0; i--)
    {
        // cout<<ed[i]<<endl;
        // cout<<(len-(b+1))-ed[i]<<endl;
        br += (len - (b + 1)) - ed[i];
        b++;
    }

    cout << br << endl;
    return 0;
}