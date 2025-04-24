#include <bits/stdc++.h>
using namespace std;
using LL = unsigned long long;
// rek
//  const int N=1e8; // mili gospodin Lupov
LL size = 1;
vector<LL> dels;
int getTheInd(int a)
{
    int nas=0;
    for (int i = 1; i*i <=n; i++)
    {
        if(n%i!=0)continue;
        if(i>x&&i<=nas)nas=i;
    }
    
}
int main()
{
    LL n;
    int q;
    cin >> n >> q;
    dels.push_back(1);
    for (LL j=2; j*j <= n; j++)
    {
        if (n % j == 0)
        {
            size++;
            dels.push_back(j);
            // cout << j << endl;
            // break;
        }
    }
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
    }
    cout << size << endl;
    return 0;
}