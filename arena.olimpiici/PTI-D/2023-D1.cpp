#include<iostream>
#include<algorithm>

using namespace std;
using LL=long long;
using pI=pair<int,int>;
const int N=2e5+1;
const int NUM_BROI=11;
const int NUMBERS=28;//26

int n;
int broi[NUM_BROI][NUMBERS];
LL br=0;
string str;

inline void opravi_chislo()
{
    int i=0;
    for(auto e:str)
    {
        br+=broi[i][e-'0'];
        ++broi[i][e-'0'];
        ++i;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);cout.tie(nullptr);
    cin>>n;
    for(int i=0;i<n;++i)
    {
        cin>>str;
        reverse(str.begin(),str.end());
        opravi_chislo();
    }
    cout<<br<<endl;
    return 0;
}
