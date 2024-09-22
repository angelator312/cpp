#include <bits/stdc++.h>
using namespace std;
// const int N;

int main()
{
    string s;
    cin >> s;
    // int n1m[900000], n2, n1, out = 0;
    // int nI1 = 0, nS = 0;
    bool pr = false;
    long long int d = 0, r = 0;
    for (int i = 0; i < s.length(); i++)
    {
        // if(s[i]=='1')
        // {
        //     nI1++;
        //     if(!pr)
        //     {
        //         nS++;
        //         n1=i;
        //     }
        //     else
        //     {
        //         n2=i;
        //     }
        // }
        // else if(pr)
        // {
        //     n1m[nS]=(n1-n2)+1;
        // }
        if (s[i]=='0')
        {
            r+=(d*(d+1))/2;d=0;continue;
        }
        if(s[i]=='1')d++;
    }
    r+=(d*(d+1))/2;
    // for (int i = 0; i < nS; i++)
    // {
    //     int e = n1m[i];

    //     out += (e * (e + 1)) / 2;
    // }
    cout << r << endl;
}

