#include <iostream>
#include <vector>
using namespace std;



vector<long long> next(vector<long long> a)
{
    vector<long long> b;
    for(int i=1; i<a.size(); i++)
        b.push_back(a[i-1]+a[i]);
    return b;
}

int main()
{
    int N,K;
    cin>>N>>K;

    vector <long long> a;

    for(int i=0; i<N; i++)
        a.push_back(K+i);
    for(int i=1;i<N;i++)
        a=next(a);
    cout<<a[0]<<endl;
    return 0;
}
