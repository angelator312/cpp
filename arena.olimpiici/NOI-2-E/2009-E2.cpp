#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
using LL = int;
int main()
{
    bool usl1,usl2;
    int d = 0, v = 0;
    char a, b, c,a1,cPosledno;
    cin >> a;
    a1=a;
    cin >> b;
    cin >> c;
    usl1=a > b;
    usl2=a < b;
    while (c != '0')
    {
        if (c < b && b > a)
            v++;
        if (a > b && b < c)
            d++;

        a = b;
        b = c;
        cin >> c;
    }
    if (c > a1 &&c>b)
        v++;
    if (c < a1 && usl1)
        v++;
    if (c < a1 &&c<b)
        d++;
    if (c > a1 && usl2)
        v++;
    cout << v << " " << d << endl;
    return 0;
}