#include <iostream>
#include <array>
using namespace std;

int main()
{
    string ops;
    ops="'m=m,ch','m,ch=m','x,y,x2,y2=ch:m','n:6ch,k:0,100=kod','n:6ch,k:0,100=kod_w_for'";
    cout<<ops<<endl;
    string o;
    cin>>o;
    if(o=="m=m,ch")
    {
        int m,x,y;
        cin>>m;
        x=m/60;
        y=m%60;
        cout<<"minuti "<<y<<endl;
        cout<<"chasove "<<x<<endl;
    }
    else if(o=="m,ch=m")
    {
        int m,x,y;
        cin>>x>>y;
        m=x*60+y;
        cout<<m<<endl;
    }
    else if(o=="x,y,x2,y2=ch:m")
    {
        int x,y,x2,y2;
        cin>>x>>y>>x2>>y2;
        int vp=x*60+y;
        int vend=x2*60+y2;
        int vn=vend-vp;
        int ch=vn/60;
        int m=vn%60;
        int ch1=ch/10;
        int m1=m/10;
        int ch2=ch%10;
        int m2=m%10;
        cout<<ch1<<ch2<<":"<<m1<<m2<<endl;

    }
    else if(o=="n:6ch,k:0,100=kod_w_for")
    {
        int n,k,ch,ost,n1;
        int a[6];
        cin>>n>>k;
        a[0]=n;
        cout<<1<<endl;
        for(int i=6; i>0; i--)
        {
            cout<<i<<endl;
            a[i]=a[0]%10;
            a[0]=a[0]/10;
        }
        n1=a[6]*100000+a[5]*10000+a[4]*1000+a[3]*100+a[2]*10+a[1];
        ch=n1/k;
        ost=n1%k;
        cout<<ch+ost<<endl;
    }
    else if(o=="n:6ch,k:0,100=kod")
    {
        int n,a1,a2,a3,a4,a5,a6,k,n1,ch,ost;
        cin>>n>>k;
        a1=n/100000%10;
        a2=n/10000%10;
        a3=n/1000%10;
        a4=n/100%10;
        a5=n/10%10;
        a6=n%10;
        n1=a6*100000+a5*10000+a4*1000+a3*100+a2*10+a1;
        ch=n1/k;
        ost=n1%k;
        cout<<ch+ost<<endl;
    }
    else
    {
        cout<<"not command"<<endl;
    }
    return 0;
}
