#include <bits/stdc++.h>
#include <algorithm>
#define endl "\n"
using namespace std;
using LL = long long;
LL rec(LL a)
{
    if(a==1)return 1;
    return a+rec(a-1);
}
int main()
{
    LL n;
    cin >> n;
    
    cout << rec(n) << endl;
    return 0;
}