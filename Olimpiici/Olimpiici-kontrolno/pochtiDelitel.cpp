#include <bits/stdc++.h>
using namespace std;
using LL = unsigned long long;
// rek
//  const int N=1e8; // mili gospodin Lupov
LL size=1;
vector<LL> dels;
int getTheInd(int a)
{
    LL b = dels.back();
    if (b > a)
    {
        int i=size;
        while (dels[i] >= a)
        {
            i--;
        }
        return i + 1;
    }
    else if (b == a)
        return -1;
    else
        return -2;
}
int main()
{
    LL n;
    int q;
    cin >> n >> q;
    dels.push_back(1);
    for (int i = 0; i < q; i++)
    {
        LL e;
        cin >> e;
        LL j = getTheInd(e);

        if (j == -1)
        {
            cout << e << endl;
            continue;
        }
        else if (j > -1)
        {
            cout << dels[j] << endl;
            continue;
        }
        else
            j = e;
        for (; j <= n; j++)
        {
            if (n % j == 0)
            {
                size++;
                dels.push_back(j);
                cout << j << endl;
                break;
            }
        }
    }
    cout<<size<<endl;
    return 0;
}