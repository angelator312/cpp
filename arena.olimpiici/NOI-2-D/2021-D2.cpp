#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
using LL = int;
int a[100000]{};
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i <n; i++)
    {
        cin>>a[i];
    }
    int br=0;
    for (int i = 0; i <n; i++)
    {
        while(a[i]!=i)
        {
            int j=a[i];
            swap(a[i],a[j]);
            br++;
        }
    }
    
    cout<<br<<endl;
    return 0;
}
/*
    0 1 2 3 4 5 6

    4 2 1 0 5 3 6
    5 2 1 0 4 3 6
    3 2 1 0 4 5 6
    0 2 1 3 4 5 6
    0 1 2 3 4 5 6



*/