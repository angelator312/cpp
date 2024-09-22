#include <bits/stdc++.h>
using namespace std;

int main()
{
    float x1,y1;
    float x2,y2;
    float x3,y3;
    float h,a;
    float P,S;
    cin>>x1>>y1;
    cin>>x2>>y2;
    cin>>x3>>y3;
    h=fabs(y1-y3);
    a=fabs(x1-x2);

    S=(a*h)/2;
    

    cout<<S<<endl;
    return 0; 

}

