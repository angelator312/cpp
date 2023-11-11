#include<iostream>
using namespace std;
int main()
{    long long A,B,R,P,K;
    cin>>A>>B>>R>>P>>K;
    if (A>B)
    {
        swap(A,B);
    }
    
     long long e=(B-A)+1;
     long long out=e*R+max(e-2,( long long)0)*P+max(e-1,( long long)0)*K;
    cout<<out<<endl;
    return 0;
}