#include <iostream>
using namespace std;
int main(){
    string N;
    cin >> N;
    do{
        int sum=0;
        for (char c : N)
        {
            sum+=(c-'0')*(c-'0');
        }
        N=to_string(sum);
    }while (N.size()>1);
    if(N=="1")cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}