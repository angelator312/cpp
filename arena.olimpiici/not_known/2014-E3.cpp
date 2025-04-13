#include<iostream>
using namespace std;
using LL=long long;
int main()
{
    int a,b,o;
    char z;
    cin>>a>>b>>z;
    switch (z)
    {
    case 'f':
        if (b>a)
            o=a;
        else o=b;
        break;
    case 'h':
        if (b<a)
            o=a;
        else o=b;
        
        break;
    case 'a':
        o=b;
        break;
    case 'v':
        o=a;
        break;
    
    default:
        break;
    }
    
    
    cout<<o<<endl;

}