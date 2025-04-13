#include <iostream>

using namespace std;

int main()
{
    int n,m,k,br=0;
    cin>>k>>n>>m;
    //cout<<"k="<<k<<" n="<<n<<" m="<<m<<endl;
    for(int i=0;i<m;i++)
    {
        int e,e2;
        cin>>e>>e2;
        //cout<<e<<" "<<e2<<" ";
        if(e==k || e2==k)br++;
    }
    cout<<br<<endl;
    return 0;
}

