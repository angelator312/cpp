#include <iostream>
#include <algorithm>
#if 0
#define P(a) cout<<a<<endl
#else
#define P(a)
#endif
using namespace std;
int brK(int s,int s2)
{
    return (s+s2-1)/s2;
}
int main()
{
    int s[3],lv[3],st[3],a,b;
    for (int i = 0; i < 3; i++)
    {
        cin >>s[i]>>lv[i]>>st[i];
    }
    cin>>a>>b;
    const int S=a*b*4;
    int tcena =100*100*25*25;
    int nom=0;
    int t=brK(S,s[0])*(lv[0]*100+st[0]);
    P(t);
    if (tcena>t)
    {
        tcena=t;
        nom=0;
    }
    P(t);
    t=brK(S,s[1])*(lv[1]*100+st[1]);
    if (tcena>t)
    {
        tcena=t;
        nom=1;
    }
    P(t);
    t=brK(S,s[2])*(lv[2]*100+st[2]);
    if (tcena>t)
    {
        tcena=t;
        nom=2;
    }
    P(t);
    int tcenaSt=tcena;
    int tcenaLv=tcenaSt/100;
    tcenaSt%=100;
    cout <<tcenaLv<<" "<<tcenaSt<< endl;
    return 0;

}