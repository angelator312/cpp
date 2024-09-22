#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    stack<int> a;
    while (n>0)
    {
        a.push(n%2);
        n/=2;
    }
    
    
    while (!a.empty())
    {
        cout<<a.top();
        a.pop();
    }
    
    cout << endl;
}