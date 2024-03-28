#include <bits/stdc++.h>
#include <algorithm>
#define endl "\n"
using namespace std;
using LL = int;

int main()
{

    LL wPixo = 0;
    LL wPenda = 0;
    LL rPixo = 0;
    LL rPenda = 0;
    string a;
    char b;
    cin >> a;
    LL n = a.size();
    for (LL i = 0; i < n; i++)
    {
        cin >> b;
        if (a[i] == 'O')
        { // Pixo
            if (b == 'r')
            {
                rPixo++;
            }
            else
                wPixo++;
        }
        else
        {
            if (b == 'r')
            {
                rPenda++;
            }
            else
                wPenda++;
        }

        if (rPixo >= wPenda)
        {
            rPixo -= wPenda;
            wPenda = 0;
        }
        else
        {
            wPenda -= rPixo;
            rPixo = 0;
        }

        if (wPixo >= rPenda)
        {
            wPixo -= rPenda;
            rPenda = 0;
        }
        else
        {
            rPenda -= wPixo;
            wPixo = 0;
        }
    }
    
    if (rPixo >= wPenda)
    {
        rPixo -= wPenda;
        wPenda = 0;
    }
    else
    {
        wPenda -= rPixo;
        rPixo = 0;
    }
    if (wPixo >= rPenda)
    {
        wPixo -= rPenda;
        rPenda = 0;
    }
    else
    {
        rPenda -= wPixo;
        wPixo = 0;
    }
    swap(rPixo, wPenda);
    swap(rPenda, wPixo);

    cout << wPixo << endl;
    cout << rPixo << endl;
    cout << wPenda << endl;
    cout << rPenda << endl;
    return 0;
}