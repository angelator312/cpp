#include <iostream>
using namespace std;

int main()
{
    int n,mx=0,mi=1000;
    cin>>n;
    for(int i=1;i<=n;i++){
        int e;
        cin>>e;
        if(e!=i){
            mx=max(e,mx);
            mi=min(e,mi);

        }
    }
    if(mi==1000)
        cout<<"0 0"<<endl;
    else cout<<mi<<" "<<mx<<endl;
    return 0;
}
