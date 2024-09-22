#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int P = 3e3;
const int K = 3e4; // max chislo

int main()
{
    int n;
    cin >> n;
    int mas[n];
    for (int i = 0; i < n; i++)
        cin >> mas[i];

    int p;
    cin >> p;
    bool m2[p][K];
    for (int i = 0; i < p; i++)
    {
        int a,b;
        cin >> a;
        for (int j = 0; j < a; j++)
        {
            cin >> b;
            m2[i][b] = 1;
        }
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int a;
        cin >> a;
        a = mas[a - 1];
        int z = -1, kr = -1, br = 0;
        for (int i = 0; i < p; i++)
        {
            if (!m2[i][a])
                continue;
            if (z == -1)
                z = i;
            br++;
            kr = i;
        }
        if (z > -1)
            cout << br << " " << z + 1 << " " << kr + 1 << "\n";
        else
            cout << "0 0 0\n";
    }

    return 0;
}