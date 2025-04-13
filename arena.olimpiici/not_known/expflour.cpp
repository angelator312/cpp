#include <iostream>
#include <numeric>
using namespace std;
int main(){
    long long n,m;
    cin >> n >> m;
    cout<<gcd(n-1,m-1)+1<<endl;
    return 0;
}