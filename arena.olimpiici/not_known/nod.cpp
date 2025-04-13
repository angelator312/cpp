#include <iostream>
#include <numeric>
using namespace std;
int main(){
    int N;
    cin>>N;
    for(int i=2;i*i<=N;i++){
        if(N%i==0){
            cout<<N/i<<endl;
            return 0;
        }
    };
    cout<<1<<endl;
    return 0;
}