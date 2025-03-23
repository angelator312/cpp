#include<iostream>
#include<algorithm>
#include <vector>
#define endl "\n"
using namespace std;
using LL=long long;
using pI=pair<int,int>;
using pPI=pair<pI,int>;
const int N=1e9;
vector<pPI> intervals;
int n,q,mxI=0;
int l,r,v,n2;

bool cmp(const pPI &a,const pPI &b)
{

    if(a.first.first==b.first.first)
    {
        if(a.first.second>b.first.second)
        {
            return true;
        }else
        {
            return false;
        }
    }
    return a<b;
}

pI valOfI(int sg,int zap=0)
{
    int i=zap,first=-1,val=0;
    for(; i<n2; ++i)
    {
        if(intervals[i].first.second>=sg&&intervals[i].first.first<=sg)
        {
            first=first==-1?i:first;
            val+=intervals[i].second;
        }
        else if(sg<intervals[i].first.first)
        {
            return {first,val};
        }
    }
    return {first==-1?0:first,val};
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);cout.tie(nullptr);
    cin>>n>>q;
    for(int i=0; i<n; ++i)
    {
        cin>>l>>r>>v;
        intervals.push_back({{l,r-1},v});
        mxI=max(r+2,mxI);
        ////cerr<<"l:"<<prefix[l]<<endl;
        ////cerr<<"r:"<<prefix[r]<<endl;
    }
    /*
    //cerr<<"intervals:prosti"<<endl;
    for(pPI e:intervals)
    {
        //cerr<<e.first.first<<" "<<e.first.second<<" v:"<<e.second<<endl;
    }
    pI last=intervals[0].first;
    for(int i=1; i<intervals.size(); ++i)
    {
        //*
        l=intervals[i].first.first;
        r=intervals[i].first.second;
        if(last.first<l&&last.second<=r)
        {
            intervals[i-1].first.second=l-1;
            intervals[i].first.first=last.second+1;
            intervals.insert(i,{{l-1,last.second},v+intervals[i-1].second});
            sort(intervals.begin(),intervals.end());
        }
        ///
        last=intervals[i].first;
    }
    //*/
    n2=intervals.size();
    sort(intervals.begin(),intervals.end(),cmp);
    /*
    cerr<<"intervals"<<endl;
    for(pPI e:intervals)
    {
        cerr<<e.first.first<<" "<<e.first.second<<" v:"<<e.second<<endl;
    }
    //*/
    ////cerr<<endl;
    LL sum=0;
    for(int i=0; i<q; ++i)
    {
        cin>>l>>r;
        sum=0;
        if(mxI<r)
        {
            r=mxI;
        }
        else --r;
        pI lastI=valOfI(l);
        //cerr<<"lasts";
        for(int j=l; j<=r; ++j)
        {
            lastI=valOfI(j);
            //cerr<<lastI.second<<" ";//<<lastI.first<<endl;
            sum+=lastI.second;
        }
        //cerr<<endl;
        //cout<<prefix[r]-prefix[--l]<<endl;
        cout<<sum<<endl;
    }

}

/*
5 5
3 7 2
1 10 4
1 6 10
0 4 10
6 7 1
5 7
0 2
5 9
1 6
4 9

*/
