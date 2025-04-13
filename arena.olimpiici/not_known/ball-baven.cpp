#include <iostream>
using namespace std;
int main()
{
    long long n;
    int x, n0, n1;
    cin >> n >> x;
    for(long long i=n; i>0;i--){
        if (i%2==0){
            if (x==1){
                x=2;
            }else if (x==2){
                x=1;
            }
        }
        else{
            if (x==0){
                x=1;
            }else if (x==1){
                x=0;
            }
        }
    }
        cout << x << endl;
    return 0;
}