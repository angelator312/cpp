#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#define endl "\n"
using namespace std;
using LL=long long;
using pI=pair<int,int>;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin>>t;
    for(int k=0; k<t; ++k)
    {
        int n, m,pr=0;
        cin >> n >> m;
        char matrix[n][m];
        int stvRed[n] {};
        int stvKol[m] {};
        for(int i=0; i<n; ++i)
        {
            int br1=0;
            for(int j=0; j<m; ++j)
            {
                cin>>matrix[i][j];
                br1+=(matrix[i][j]-'0');
            }
            stvRed[i]=br1;
        }
        //cerr<<"cinStop"<<endl;
        for(int j=0; j<m; ++j)
        {
            int br1=0;
            for(int i=0; i<n; ++i)
            {
                br1+=matrix[i][j];
            }
            stvKol[j]=br1;
            if(br1%2==1)
            {
                for(int i=0; i<n; ++i)
                {
                    if(stvRed[i]%2==1)
                    {
                        if(matrix[i][j]=='0'&&stvRed[i]<m)
                        {
                            ++stvRed[i];
                            ++stvKol[j];
                            matrix[i][j]='1';
                            ++pr;
                        }
                        else
                        {
                            --stvRed[i];
                            --stvKol[j];
                            matrix[i][j]='0';
                            ++pr;
                        }
                        break;
                    }
                }
            }
            if(stvKol[j]%2==1)
            {
                int i=0;
                while(i<n&&matrix[i][j]=='1')
                {
                    ++i;
                }
                if(i==n)
                {
                    //triene
                    i=0;
                    matrix[i][j]='0';
                    --stvRed[i];
                    --stvKol[j];
                    ++pr;
                }
                else
                {
                    matrix[i][j]='1';
                    ++stvRed[i];
                    ++stvKol[j];
                    ++pr;
                }
            }
        }
        //*
        for(int i=0; i<n; ++i)
        {
            if(stvRed[i]%2==1)
            {
                for(int j=0; j<m; ++j)
                {
                    if(stvKol[j]%2==1)
                    {
                        if(matrix[i][j]=='0'&&stvKol[j]<n)
                        {
                            ++stvRed[i];
                            ++stvKol[j];
                            matrix[i][j]='1';
                            ++pr;
                        }
                        else
                        {
                            --stvRed[i];
                            --stvKol[j];
                            matrix[i][j]='0';
                            ++pr;
                        }
                        break;
                    }
                }
            }
            if(stvRed[i]%2==1)
            {
                int j=0;
                while(j<m&&matrix[i][j]=='1')
                {
                    ++j;
                }
                if(j==m)
                {
                    //triene
                    j=0;
                    matrix[i][j]='0';
                    --stvRed[i];
                    --stvKol[j];
                    ++pr;
                }
                else
                {
                    matrix[i][j]='1';
                    ++stvRed[i];
                    ++stvKol[j];
                    ++pr;
                }
            }
        }

        /*
        for(int i=0; i<n; ++i)
        {
            for(int j=0; j<m; ++j)
            {
                cerr<<matrix[i][j];
            }
            cerr<<endl;
        }
        //*/

        cout<<pr<<endl;
    }
    return 0;
}
/*
1
3 3
0 1 0
0 0 0
0 0 0


1
4 1
0
1
0
1
*/
