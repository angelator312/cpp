#include <bits/stdc++.h>
using namespace std;
int main()
{
    int m = 0, n, h = 0,s=0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int e1, e2;
        cin >> e1 >> e2;
        s += e1*60+e2;

    }
    // while(cin>>h>>m)
    // {
    //     s+=h*60+m;
    // }
    // cout<<s<<endl;
    h=s/60;
    m=s%60;
    if(m>0)h++;
    int k3=h/3+1;//min(h%3,1)
    int k4=h/4+1;
    int t=1000000;  //tcena
    for(int i=0;i<=34;i++)
    {
        for(int j=0;j<=25;j++){
            if(3*i+4*j>=h)
            {
                int tcL=i*915+j*1090;
                if(t>tcL)
                {
                    t=tcL;
                }
            }
        }
    }
    int lv=t/100,st=t%100;
    cout<<lv<<"."<<st/10<<st%10<<endl;
    // 3 
    // 3 30
    // 4 25
    // 1 05
    return 0;
}