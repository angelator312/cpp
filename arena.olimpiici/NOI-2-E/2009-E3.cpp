#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
using LL = int;
int main()
{
    vector<int> ch;
    int n=0 ,mx= -1,mn=10009;
    cin >> n;
    for (int i = 0; i <n; i++)
    {
        char e;
        cin>>e;
        if (e-'0'>mx)mx=e-'0';
        if (e-'0'<mn)mn=e-'0';
        ch.push_back(e-'0');
    }
    double sum=(mx*2)/3+mn/3;
    int i=0;
    for (auto b:ch)
    {
        if (b<=sum)
        {
            break;
        }
        i++;
    }
    cout<<i+1<<endl;
    return 0;
}