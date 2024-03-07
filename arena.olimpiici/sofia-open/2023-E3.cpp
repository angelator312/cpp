#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;
int main()
{
    int H1,H2,M1,M2,M3m,M3;
    cin>>H1>>M1>>H2>>M2>>M3m;
    M3=((H1*60+M1)-M3m);
    // cout<<M3<<endl;
    int mA=(M3+M1+M2+(H1+H2)*60)%1440;
    // cout<<mA<<endl;
    int mVTr=750-(mA);
    // cout<<mVTr<<endl;
    if (mVTr<0) 
    {
        mVTr+=1440;
    }
    int Ho=mVTr/60;
    int Mo=mVTr%60;
    if(Ho==24)
    {
        Ho=0;
    }
    cout<<Ho<<":"<<Mo/10<<Mo%10<<endl;
}