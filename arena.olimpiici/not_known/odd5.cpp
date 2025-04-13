#include <bits/stdc++.h>
using namespace std;


const int N=12000000;

vector <long long> x(N);

int main()
{
    long long a,b;
    cin>>a>>b;

    for(long long i=1;i<N;i++)
        x[i]=i*i;

    int br=upper_bound(x.begin(),x.end(),b)-lower_bound(x.begin(),x.end(),a);

    cout<<br<<endl;
    return 0;
}

