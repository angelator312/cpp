#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main()
{
    long long a,b;
    int br=0;
    cin >> a>>b;
    
    while (a>0 && b>0)
    {
        if(a>b)
            a-=b;
        else b-=a;
        br++;
        
    }
    

    cout << br << endl;
    return 0;
}