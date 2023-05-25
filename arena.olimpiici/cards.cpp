#include <iostream>
using namespace std;

int main(){
    int n,h=0;
    cin>>n;
    int cards[100003]{};
    int es[n];
    for(int i=0; i<n; i++){
        int e;
        cin>>e;
        es[i]=e;
        cards[e]++;
    }
    for(int i=0;i<n;i++){
        h+=cards[es[i]]/2;
        cards[es[i]]=0;
    }
    if(h%2==0){
        cout<<2<<endl;
    }else{
        cout<<1<<endl;
    }
    return 0;
}