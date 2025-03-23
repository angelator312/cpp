#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using pI = pair<int, short>;
vector<pI> vec;
int L,Len=1e9,LenL;
int n,k,num;
int main()
{
    cin>>k>>k;
    for(int i=0;i<k;i++)
    {
        cin>>n;
        for(int j=0;j<n;++j)
        {
            cin>>num;
            vec.push_back({num,i});
        }
    }
    //cerr<<"cin"<<endl;
    sort(vec.begin(),vec.end());
    /*
    for (auto e:vec)
    {
        cerr<<e.first<<" "<<e.second<<endl;
    }
    //*/
    

    int j=0,br=0;
    int mnozhestva[k+1]{};
    int vSize=vec.size();
    for(int i=0;i<vSize;)
    {
        //cerr<<"i:"<<i<<endl;
        while(j<vSize && br<k)
        {
            br += mnozhestva[vec[j].second]==0;  
            ++mnozhestva[vec[j].second];
            //cerr<<j<<":"<<br<<endl;
            ++j;
        }
        if(br<k)break;
        LenL = vec[j-1].first-vec[i].first;
        if(Len>LenL)
        {
            Len=LenL;
            L=vec[i].first;
        }
        --mnozhestva[vec[i].second];
        br -= mnozhestva[vec[i].second]==0;
        ++i;
    }
    cout<<L<<" "<<L+Len<<endl;
    return 0;
}