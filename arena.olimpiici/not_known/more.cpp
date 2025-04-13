#include <bits/stdc++.h>
using namespace std;



int main()
{
    string in;
    cin>>in;
    int outs[26]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    for(int i=0;i<in.size();i++)
    {
        outs[(in[i]-'a')]++;
    }
    for(int i=0;i<26;i++)
    {
        char e=i+'a';
        int p=outs[i];
        if(p>1)
            cout<<e<<" "<<p<<endl;
    }


    return 0;
}

