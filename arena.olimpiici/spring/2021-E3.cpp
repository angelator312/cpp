#include <iostream>
#include <algorithm>
using namespace std;
using LL = long long;
const int N = 1e6 + 1;
LL m[N];
LL cnt[N];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    LL sumM = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> m[i];
        cnt[i] = cnt[i - 1] + m[i];
    }
    // cout<<"zav"<<endl;
    for (int i = 0; i < n; i++)
    {
        int mezhdinen=0,kray=0;
        // cout<<i<<endl;
        LL pI = i + 1;
        // cout<<i<<" ";
        for (int j = i + 1; j < n; j++)
        {
            mezhdinen=j;
            if (m[j - 1] >= m[j])
                break;
            pI++;
        }

        // cout<<pI<<" sum:"<<sum<<" ";
        for (int j = pI; j < n; j++)
        {
            kray=j;
            if (m[j - 1] <= m[j])
                break;
            pI++;
        }
        if(mezhdinen==kray)
        {
            sumM = max(sumM,m[i]);
            continue;
        }
        // cout<<pI<<endl;
        sumM = max(sumM, cnt[pI-1] - cnt[i - 1]);
        i=pI-2;
    }
    cout << sumM << endl;
    return 0;
}