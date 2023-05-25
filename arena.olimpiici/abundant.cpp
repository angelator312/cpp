#include<iostream>

using namespace std;

int main(){
    long long n,sum=1;
    cin>>n;
    bool ch=n%2==0;
    long long i=ch?2:3;
    while(i<=n/2)
    {
        if(n%i==0){sum+=i;}
        if(ch)i++;
        else i+=2;
    }
    cout<<sum<<endl;
    if(sum>n)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
