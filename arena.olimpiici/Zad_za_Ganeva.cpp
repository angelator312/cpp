#include<iostream>

using namespace std;

int main()
{
    int N,i0=int('0'),i9=int('9'),sum=0;
    cin>>N;
    for(int i=0;i<N;i++)
    {   string e;
        cin>>e;
        for(int j=0;j<e.size();j++)
        {
            int d=e[j];
            if(d<=i9&&d>i0)sum+=d-i0;
        }
    }
    cout<<sum<<endl;
    return 0;
}
