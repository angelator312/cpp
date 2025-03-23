#include<iostream>
using namespace std;

const int N=3e5+2;
const int M=3e5+1;
const int A=2e9+1;

int n,m,t,maxTracks=0;
int golemini[N];
int onTrack[M];
int k;

int main()
{
    cin>>n>>m>>t;
    for(int i=0; i<n; ++i)
    {
        cin>>golemini[i];
    }
    for(int i=0; i<m; ++i)
    {
        cin>>onTrack[i];
        --onTrack[i];
    }
    for(int i=0; i<m; ++i)
    {
        int tracks=0,predInd=-1,indN=onTrack[i];
        k=0;
        while(predInd!=indN&&k<t)
        {
            predInd=indN;
            k+=golemini[indN];
            ++tracks;
            int mn;
            if(indN==0)
            {
                if(golemini[indN]>golemini[indN+1])
                    ++indN;
            }
            else if(i==m-1)
            {
                if(golemini[indN]>golemini[indN-1])
                    --indN;
            }
            else
            {
                if(golemini[indN]>golemini[indN-1])
                {
                    if(golemini[indN-1]>golemini[indN+1])
                    {
                        ++indN;
                    }
                    else
                        --indN;
                }
                else if(golemini[indN]>golemini[indN+1])
                {
                    ++indN;
                }
            }
        }
        if(k>t)
        {
            tracks+=(t-k)/golemini[indN];
        }
        if(k>t)
        {
            --tracks;
        }
        cerr<<i<<" "<<tracks<<" i:"<<indN<<endl;
        maxTracks=max(maxTracks,tracks);
    }
    cout<<maxTracks<<endl;
}
