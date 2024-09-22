#include <iostream>
#include <numeric>
using namespace std;
int main(){
    int N,M,m;
    cin>>M>>N;
    for(int i=1;;i++){
        int f=(N+M)*i;
        if(f%N+f%M==0){
            cout<<i*2<<endl;
            return 0;
        }
    }
    cout<<0<<endl;
    return 0;
}