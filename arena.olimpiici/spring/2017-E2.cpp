#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using razIndPair = pair<int, int>;

const int N = 1e3 + 1;
int mas[N];
int main()
{
    int m, a;
    cin >> m;

    vector<int> mas;
    // , prefix;
    int mx = 0, mxI = -1, smM = 0, smI = 0, mnM = 0;
    for (int i = 0; cin >> a; i++)
    {
        mas.push_back(a);
        if (a > mx)
        {
            mx = a;
            mxI = i;
        }
        // if (i > 0)
        //     prefix.push_back(prefix[i - 1] + a);
        // else
        //     prefix.push_back(a);
    }

    int n = mas.size();

    for (int i = 0; i <= n - m; i++)
    {
        // cout<<i<<endl;
        int mn = mx + 2;
        int sm = 0;
        for (int j = 0; j < m; j++) // index = j+i;
        {
            // if (i == 2)
            // cout << mas[i + j] << endl;
            sm += mas[i + j];
            if (mas[j + i] < mn)
                mn = mas[j + i];
        }

        int mxOther = 0;
        for (int j = 0; j < i; j++)
        {
            if (mas[j] > mxOther)
            {
                mxOther = mas[j];
            }
        }
        for (int j = i + m; j < n; j++)
        {
            if (mas[j] > mxOther)
            {
                mxOther = mas[j];
            }
        }
        if (mxOther > mn)
            sm += (mxOther - mn);

        if (sm > smM)
        {
            // if(i==2)
            //     cout<<mxOther<<endl;
            smM = sm;
            smI = i;
            mnM = mn;
        }
    }


    // cout << smI << endl;
    cout << smM << endl;
    return 0;
}