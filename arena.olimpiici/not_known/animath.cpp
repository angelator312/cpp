#include <iostream>
#include <map>
using namespace std;
typedef long long ul;
map<string,int> m{{"no",0},{"pa",1},{"re",2},{"ci",3},{"vo",4},{"mu",5},{"xa",6},{"ze",7},{"bi",8},{"so",9}};
map<int,string> om{{0,"no"},{1,"pa"},{2,"re"},{3,"ci"},{4,"vo"},{5,"mu"},{6,"xa"},{7,"ze"},{8,"bi"},{9,"so"}};
ul tr(string s)
{
    ul out=0,mn=1;
    int a[15],k=0;
    string ch;
    for(char c:s)
    {
        if(c==' ')continue;
        ch+=c;
    }
    for(int i=0; i<ch.size(); i+=2)
    {
        char p=ch[i];
        char c=ch[i+1];

        string d=string(1,p);
        d+=c;
        a[k]=m[d];
        k++;


    }
    for(int i=k-1; i>=0; i--)
    {
        out+=a[i]*mn;
        //cout<<a[i]<<" mn:"<<mn<<endl;
        mn*=10;
    }
    return out;
}
string trFromUl(ul in)
{
    string sin=to_string(in);
    string out="";
    for(char c:sin)
    {
        out+=om[c-'0'];
    }
    return out;
}
int main()
{
    int n;
    string in,e;
    cin>>n;
    cin>>in;
    ul chs[n],sum=0,r=0;
    getline(cin,e);
    for(int i=0; i<n; i++)
    {
        getline(cin,e);
        ul et= tr(e);
        if(in=="+")sum+=et;
        if(in=="-")
        {
            chs[i]=et;
        }
        //cout<<et<<endl;
    }
    if(in=="-")
    {
        for(int i=0; i<n; i++)
        {
            if(chs[i]>r)r=chs[i]-r;
            else r-=chs[i];
        }
        cout<<trFromUl(r)<<endl;
    }
    else
    {
        //cout<<sum<<endl;
        cout<<trFromUl(sum)<<endl;
    }
    return 0;
}
