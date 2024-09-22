#include <iostream>
#include <climits>

using namespace std;

int findIndex(int r[],int n,int f)
{
    for(int i=0;i<n;i++)
    {
        if(r[i]==f)return i;
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);cin.tie(0);
    int n,br=0;
    cin >> n;
    int r[n];
    for (int i = 0; i < n; i++)
        cin >> r[i];
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for(int j=0;j<n;j++)
        {
            if(j==i)continue;
            int ind=findIndex(r,n,r[i]+r[j]);
            if(ind!=-1)br++;
        }
    }
    cout <<br << endl;
}
