#include <iostream>
using namespace std;

int main()
{
    int n,k;
    long long chs=0,ch=1,sd=1,ed=0,kchs=0,k2;
    cin>>n>>k;
    k2=k;
    while (k2!=0){
        k2=k2/10;
        kchs++;
        if(kchs>n){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    
    for(int i=1;i<n-1;i++){
        sd*=10;
        ed*=10+1;
    }
    sd*=10;
    sd=sd+ed*9;
    for(int i=1; i<=n-1; i++){
        ch*=10;
    }
    while(ch%k!=0){
        ch++;
        chs++;
        if(chs>=sd)break;
    }
    if(ch%k!=0)
        cout<<"NO"<<endl;
    else
        cout<<ch<<endl;
    return 0;
}
