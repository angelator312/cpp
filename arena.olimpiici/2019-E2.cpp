#include <iostream>

using namespace std;
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    char a[3],b[3],c[3];
    cin>>a[0]>>a[1]>>a[2];
    cin>>b[0]>>b[1]>>b[2];
    cin>>c[0]>>c[1]>>c[2];
    string x=""+a[0];
    x+=b[1];x+=c[2];
    string y=""+a[2]+b[1]+c[0];
    cout<<x<<endl;
    int p=stoi(x),q=stoi(y);
    cout<<p*q<<endl;

}
