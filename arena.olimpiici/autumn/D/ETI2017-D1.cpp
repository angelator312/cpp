#include<iostream>
using namespace std;
const int A=2e2+1;//Lupov pravilo
const int N=A;//Lupov pravilo
const int M=A;//Lupov pravilo
int n,m,h,br;
bool canHide[N][M];
bool canHide2[N][M];
void addBag(int e,int i,int j)
{
    if(canHide[i][j])return;
    if(e<h)return;
    canHide[i][j]=1;
    if(i==0)return;
    if(i==n-1)return;
    for(int k=j+1;k<=m-2;k++)
    {
        canHide[i][k]=1;
    }
}
void addBag2(int e,int i,int j)
{
    if(canHide2[i][j])return;
    if(e<h)return;
    canHide2[i][j]=1;
    if(j==0)return;
    if(j==m-1)return;
    for(int k=i+1;k<=n-2;k++)
    {
        canHide2[k][j]=1;
    }
}
int main()
{
    cin>>n>>m>>h;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int e;
            cin>>e;
            addBag(e,i,j);
            addBag2(e,i,j);
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
           //cout<<canHide[i][j]<<" ";
           //cout<<canHide2[i][j]<<"| ";
           br+=(canHide[i][j]&&canHide2[i][j]);
        }
        //cout<<endl;
    }
    cout<<br<<endl;
}

/*
3 4 5
7 7 4 4
6 3 4 3
6 7 4 2
*/
