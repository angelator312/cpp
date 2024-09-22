#include<iostream>
using namespace std;
typedef  long long ul;
int main()
{
    ul n,d,m1,m2,m3,gt;
    cin>>n>>m1>>m2>>m3>>d;gt=n;
    if((m1+2*d)<m2){
        gt-=d;
    }
    if(m1-d<1)gt-=1-(m1-d);
    if(m2-2*d>m1)gt-=d;
    if((m2+2*d)<m2){
        gt-=d;
    }
    if(m2-d<1)gt-=1-(m2-d);
    if(m2+d>n)gt-=n-(m2+d);
    if(m3-2*d>m2)gt-=d;
    if((m3+2*d)<m3){
        gt-=d;
    }
    if(m3-d<1)gt-=1-(m3-d);
    if(m3+d>n)gt-=n-(m3+d);
    cout<<gt<<endl;
    return 0;
}
