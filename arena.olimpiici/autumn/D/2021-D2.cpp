#include <bits/stdc++.h>
using namespace std;

int NMD(int a)
{
    for (int i = 2; i * i <= a; i++)
    {
        if (a % i == 0)
            return i;
    }
    return 1;
}

int main()
{
    int n;
    cin >> n >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b, mxGCD = 0;
        cin >> a >> b;
        while (1)
        {
            if (a > b)
            {
                int d = NMD(a);
                if(d==1)break;
                a /= d;
                b *= d;
            }
            else
            {
                int d = NMD(b);
                if(d==1)break;
                b /= d;
                a *= d;
            }
            // cout << a << endl;
            // cout << b << endl;

            int gcd = __gcd(a, b);
            // cout<<gcd<<endl;
            if (gcd >= mxGCD)
            {
                mxGCD = gcd;
            }
            else
            {

                // cout << "1\n";
                break;
            }
            if(gcd==1)break;
        }
        cout << mxGCD << endl;
    }
    cout << endl;
}