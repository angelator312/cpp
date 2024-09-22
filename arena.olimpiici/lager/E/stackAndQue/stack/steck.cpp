#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> mystack,floap,bar;
    int a,n,i;
    mystack.push(111);
    mystack.push(112);
    mystack.push(113);
    mystack.push(114);
    mystack.push(115);
    
    cin>>a>>n>>i;

    floap.push(a);
    floap.push(n);
    floap.push(i);
    floap.push(n);
    
    bar.push(n);
    bar.push(a);
    bar.push(i);

    cout<<"Size of my stack:"<<mystack.size()<<endl;
    cout<<"Size of my flop:"<<floap.size()<<endl;
    cout<<"Size of my bar:"<<bar.size()<<endl;
}