#include <bits/stdc++.h>
using namespace std;
using LL = long long;
// const int N = 1e5;
multiset<int> pari;

int main()
{
    int n, k;
    cin >> n;
    int put[n + 2]{};
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        put[i] = a;
    }
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        pari.insert(a);
    }
    cin >> k;
    auto endOfSet = pari.end();
    endOfSet--;

    for (int i = 0; i < k; i++)
    {
        int a;
        cin >> a;
        put[a] = 0;
        pari.erase(endOfSet);
        endOfSet = pari.end();
        endOfSet--;
    }
    sort(put, put + n + 1);

    int ind = n;
    LL sum = 0;
    for (auto e : pari)
        sum += e * put[ind], ind--;
    cout<<sum<<endl;

}