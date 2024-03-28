#include <bits/stdc++.h>
#include <algorithm>
#define endl "\n"
using namespace std;
using LL = unsigned long long;
int main()
{

    LL br = 0;
    int n;
    cin >> n;
    int m[n + 1];
    set<int> vurhove, dolini;
    for (int i = 0; i < n; i++)
    {
        cin >> m[i];
    }
    for (int i = 1; i < n; i++)
    {
        int e = m[i];
        if (e > m[i - 1] && e > m[i + 1])
            vurhove.insert(i);
        if (e < m[i - 1] && e < m[i + 1])
            dolini.insert(i);
        for (int j = i - 1; j >= 0; j--)
        {
            br++;
            //cout << "[" << i << "] [" << j << "]\n";
            if (vurhove.count(j) == 1)
            {
                break;
            }
            if (dolini.count(j) == 1)
            {
                break;
            }
        }
    }
    cout << br*2 << endl;
    return 0;
}