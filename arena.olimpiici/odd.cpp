#include <iostream>
using namespace std;
int main(){
    long long in,in2,out=0;
    cin >> in>>in2;
    for (long long i = in; i <= in2; i++){
        long dels;
        dels=0;
        for (long long j = 1;j<=i;j++){
            if (i%j==0){
                dels++;
            }
        }
        if (dels%2==1){
            out++;
        }
    }
    
    cout << out << endl;
    return 0;
}