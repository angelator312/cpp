#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using pI = pair<int, short>;
vector<pI> points;
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
            points.push_back({num,i});
        }
    }
    //cerr<<"cin"<<endl;
    sort(points.begin(),points.end());
    /*
    for (auto e:vec)
    {
        cerr<<e.first<<" "<<e.second<<endl;
    }
    //*/
    

    int j=0,br=0;
    int mnozhestva[k+1]{};
    int vSize=points.size();
    for(int i=0;i<vSize;)
    {
        //cerr<<"i:"<<i<<endl;
        while(j<vSize && br<k)
        {
            br += mnozhestva[points[j].second]==0;  
            ++mnozhestva[points[j].second];
            //cerr<<j<<":"<<br<<endl;
            ++j;
        }
        if(br<k)break;
        LenL = points[j-1].first-points[i].first;
        if(Len>LenL)
        {
            Len=LenL;
            L=points[i].first;
        }
        --mnozhestva[points[i].second];
        br -= mnozhestva[points[i].second]==0;
        ++i;
    }
    cout<<L<<" "<<L+Len<<endl;
    return 0;
}