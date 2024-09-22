#include <bits/stdc++.h>
using namespace std;

// (n+1)×(n÷2)+p=S
// n*(n/2) + (n/2) = S-p
// (n/2)(n+1) = S-p

int main()
{
    unsigned long long x;
    cin >> x;
    bool k;
    cin >> k;
    string a = to_string(x);
    int sz = a.size();
    if (k)
    {

        // unsigned long long chis = stoull(a[0] + string(sz - 1, a[1]));
        // // cout << chis << endl;
        // if (chis >= x)
        //     cout << chis << endl;
        // else
        // {
        //     cout << a[0] << string(sz - 1, (char)(a[1] + 1)) << endl;
        // }

        string d=string(sz-2,a[0]);
        if(stoull(a[0]+(a[1]+d))>=x)
            cout<<a[0]<<a[1]<<d<<endl;
        else
            cout<<a[0]<<(char)(a[1]+1)<<string(sz-2,a[0])<<endl;

        // // махаме първото число
    }
    else
    {
        string b = string(sz, a[0]);
        if (stoull(b) < x)
        {
            cout << string(sz, (char)(a[0] + 1)) << endl;
        }
        else
            cout << b << endl;
    }

    return 0;
}