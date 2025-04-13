#include <iostream>
using namespace std;
int main(){
    int a,b,k,mS=0;
    cin >> a >> b >> k;
    for (int i = a; i <= b-k; i++)
    { int sum = 0;
        for(int j = 0; j < k; j++){
            int e=i+j;
            while(e>0){
                sum+=e%10;
                e/=10;
            }
        }
        mS=max(mS,sum);
    }
    cout<<mS<<endl;
    return 0;
}