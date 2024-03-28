#include <bits/stdc++.h>
#include <algorithm>
#define endl "\n"
using namespace std;
using LL = long long;
int main()
{

    int n, mn = 1,p=0;

    for (int kinka = 0; kinka < 3; kinka++)
    {
        mn=1;
        cin >> n;
        for (int i = 3; i+p*10 <= n; i+=2)
        {
            if(i>10)
            {
                i%=10;
                p++;
            }
            if(i==5)continue;
            mn = (mn*i)%10;
        }
        cout<<mn<<endl;
    }

    return 0;
}