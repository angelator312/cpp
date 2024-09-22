#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x1,y1;
    int x2,y2;
    int a,b;
    int P,S;
    cin>>x1>>y1;
    cin>>x2>>y2;
    a=fabs(x1-x2);
    b=fabs(y1-y2);

    S=a*b;
    P=2*(a+b);

    cout<<P<<" "<<S<<endl;
    return 0; 

}

