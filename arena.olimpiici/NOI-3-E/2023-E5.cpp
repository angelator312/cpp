#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
using LL = long long;
LL pow2[10000000] = {0, 1};
LL grupa(LL pch, LL nom, LL nOtGrupata)
{
    return pch + (int)(nOtGrupata / nom);
}
int main()
{
    LL n;
    // cout<<dels(6)<<endl;
    cin >> n;
    n--;
    LL pow2Seg = 4, nom = 2, doSega = 1, pCh = 2;
    if (n == 1)
    {
        cout << 1 << endl;
        return 0;
    }
    for (int i = 5;; i += 2)
    {
        if (n > doSega && n < doSega + pow2Seg)
        {
            cout << grupa(pCh, nom, n - doSega) << endl;
            return 0;
        }
        doSega += pow2Seg;
        pCh += nom;
        pow2Seg += i;
        nom++;
    }
    cout<<"AAAAAAAAAA"<<endl;
    return 0;
}
