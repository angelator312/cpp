#include <iostream>
using namespace std;
int main()
{
    long long n;
    cin >> n;
    int a=0;
    for (long long i = 1; i <= n; i++){
        int pe=-1;
        bool k = true;
        for (long long d = i; d > 0;d/=10)
        {
            if(d % 10!=pe && pe!=-1){
                k=false;
                break;
            }
            pe=d % 10;
        }
        if (k)
            a++;
    }
    cout<<a<<endl;
}