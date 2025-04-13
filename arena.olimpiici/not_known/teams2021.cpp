#include <iostream>
using namespace std;
int main(){
    long long n,m,teams=0;
    cin>>n>>m;
    if (m>n)
    {
        if(2*n<=m){
            teams=n;
            m=m/2;
            n=0;
        }
    }
    else{
        if(2*m<=n){
            teams=m;
            n=n/2;
            m=0;
        }
    }
    
    while ((n>=1&&m>=2)||(n>=2&&m>=1)){
        if (n>m)
        {
            n = n-2;m--;
            teams++;
        }else{
            n--;m=m-2;
            teams++;
        }
    }
    cout<<teams<<"\n";
    return 0;
}