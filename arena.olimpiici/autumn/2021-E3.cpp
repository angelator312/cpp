#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    while (n%2==1)
    {
        n=n/2+1;
    }
    cout<<n<<endl;
}