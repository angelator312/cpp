#include <bits/stdc++.h>
using namespace std;
const int A = 1e8 + 1;
int povt[A]{};
int povt2[A]{};
int main()
{
    set<int> a;
    int n, mn = INT_MAX, mx = 0, br = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int e;
        cin >> e;
        a.insert(e);
        povt[e]++;
        mn = min(mn, e);
        mx = max(mx, e);
    }

    for (int i = mn; i <= mx * 2; i++)
    {
        povt2[i] = povt2[i - 1] + (povt[i] / 2);
    }

    for (auto i : a)
    {
        // povt2[i*2]-povt[i-1]\
            + \
           povt2[i]-povt2[(i/2)-1]
        //  =
        // Броят на всички двойки възможни

        // МИН(Броят, Броят двойки на 'i' )= Oтговор

        int brL = povt2[i * 2] - povt2[i + 1];
        // int brL2 = povt2[i]-povt2[(i/2)-1];
        // brL++;
        brL = min(brL, povt[i] / 2);
        if (brL > 0 && povt2[i*2]>0&&( povt2[i/2]>0 || i==mn) && povt2[i]>0)
        {
            br += brL;
            // cout << "[" << i << "] " << povt[i] << " " << povt2[i] << " " << brL << endl;
            brL*=2;
            for (int j = i; j <= mx * 2; j++)
            {
                povt2[j] -= brL;
                // cout << "    [" << j << "] " << povt2[j] << endl;
            }
        }
    }

    cout << br << endl;
    return 0;
}