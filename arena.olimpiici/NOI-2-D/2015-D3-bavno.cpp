#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
using LL = int;
int main()
{
    int n,br=0;
    char k;
    cin >>k >>n;
    for (int i = 0; i <=n; i++)
    {
        string s=to_string(i);
        for (char x:s)
            if(x==k)br++;
        
        
    }
    
    cout<<br<<endl;
    return 0;
}