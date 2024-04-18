#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main()
{
    int lLocal = 0, lMain = 0;
    char naiGolqm = '`', a, p;
    while (cin >> a)
    {
        if (a == p)
        {
            lLocal++;
        }
        else
        {
            if (lLocal > lMain)
            {
                naiGolqm = p;
                lMain = lLocal;
            }
            else if (lLocal == lMain && p > naiGolqm)
            {
                naiGolqm = p;
            }
            lLocal = 1;
        }
        p = a;
    }
    if (lLocal > lMain)
    {
        naiGolqm = p;
        lMain = lLocal;
    }
    else if (lLocal == lMain && p > naiGolqm)
    {
        naiGolqm = p;
    }
    lLocal = 1;

    cout << lMain << " " << naiGolqm << endl;
    return 0;
}