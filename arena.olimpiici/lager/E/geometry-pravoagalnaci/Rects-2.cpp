#include <bits/stdc++.h>
using namespace std;

int main()
{
    float x1, y1;
    float x2, y2;
    float a, b;
    float a1, b1;
    float a2, b2;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin >> a1 >> b1;
    cin >> a2 >> b2;
    a=fabs(a1-x2);
    b=fabs(b1-y2);
    float ka1=fabs(x1-x2);
    float kb1=fabs(y1-y2);
    float ka2=fabs(a1-a2);
    float kb2=fabs(b1-b2);
    float s=ka1*kb1+ka2*kb2-a*b;
    float p=(a+b)*2;
    cout<<p<<" "<<s<<endl;
    
    // cout << P << " " << S << endl;
    return 0;
}
