#include <iostream>
using namespace std;
int main()
{
    long long n,n2;
    int ch=0,p;
    bool ach9=true;
    cin >> n;
    n2=n;
    int a=0;
    while (n2!=0){
        ch++;
        if(n2%10!=9)
            ach9=false;
        n2/=10;
    }
    if(ach9){
        p=ch*9;
        cout <<p<<" "<<ch << endl;
    }else{
        p=(ch-1)*9;
        long long chi=1;
        for(int i=0;i<ch-1;i++){
            chi *=10;
            chi++;
        }
        // cout<<chi<<endl;
        cout << (n/chi)+p<<endl;
    }
    return 0;
}