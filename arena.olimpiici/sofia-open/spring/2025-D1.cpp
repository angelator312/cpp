#include <iostream>
#include <cmath>
#define endl "\n"
using namespace std;
using LL=long long;
using pI=pair<int,int>;
string ch,str="";
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    double sum=0;
    int n;
    char a;
    cin>>str;
    cin>>n;
    for(auto e:str)
    {
         sum+=e-'0';
    }
    int i=3;
    while(i<n)
    {
        ch=to_string(int(round(sum/i)));
        for(auto e:ch)
        {
            sum+=e-'0';
            ++i;
        }
        str+=ch;
        //cerr<<sum<<" "<<str<<endl;
    }
    cout<<str[--n]<<endl;
    return 0;
}
/*
1
5
4 3 3 4 4
*/
