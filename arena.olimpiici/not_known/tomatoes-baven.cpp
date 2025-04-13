#include<iostream>
using namespace std;
typedef  long long ul;
int main()
{
    ul n,d,m1,m2,m3,gt=0;
    cin>>n>>m1>>m2>>m3>>d;
    m1--;m2--;m3--;
    char t[n]{};
    t[m1]=1;
    t[m2]=1;
    t[m3]=1;
    for(ul i=1; i<=d; i++)
    {
        if(m1+i<n){
                t[m1+i]=1;
        }
        if(m1-i>=0)t[m1-i]=1;
        if(m2+i<n)t[m2+i]=1;
        if(m2-i>=0)t[m2-i]=1;
        if(m3+i<n)t[m3+i]=1;
        if(m3-i>=0)t[m3-i]=1;
    }
    //cout<<gt<<endl;
    for(ul i=0; i<n; i++)
    {
        if(t[i]==0)gt++;
        //cout<<t[i]<<" ";
    }
    //cout<<endl;
    cout<<gt<<endl;
    return 0;
}
