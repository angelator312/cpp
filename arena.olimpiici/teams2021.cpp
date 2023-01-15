#include <iostream>
using namespace std;
int main(){
    long n,m;
    long teams=0;
    cin>>n>>m;
    while ((n>=1&&m>=2)||(n>=2&&m>=1)){
        if (n>m)
        {
            n-2;m-1;
            teams++;
        }else{
            n-1;m-2;
            teams++;
        }
    }
    cout<<teams<<"\n";
    return 0;
}