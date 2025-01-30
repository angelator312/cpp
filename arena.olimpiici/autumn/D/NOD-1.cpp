#include<iostream>
using namespace std;
using LL =long long;
LL NOD(LL a,LL b)
{
    if(a<b)swap(a,b);
    if(b==0)return a;
    return NOD(b,a%b);
}
LL NOK(LL a,LL b)
{
    if(a<b)swap(a,b);
    return a/NOD(b,a)*b;
}
int main()
{
    int aCh,aZnam,bCh,bZnam;
    int outCh,outZnam;
    char a,znak;
    bool otricatelno=0;
    cin>>aCh>>a>>aZnam>>znak>>bCh>>a>>bZnam;
    if(znak=='/')
    {
        znak='*';
        swap(bCh,bZnam);
    }
    if(znak=='*')
    {
        outZnam=aZnam*bZnam;
        outCh=aCh*bCh;
    }
    else
    {

        int x=NOK(aZnam,bZnam);
        aCh*=x/aZnam;
        bCh*=x/bZnam;
        aZnam=x;
        bZnam=x;
        outZnam=x;
        if(znak=='+')
            outCh=aCh+bCh;
        if(znak=='-')
        {
            if(bCh>aCh)otricatelno=1;
            outCh=abs(aCh-bCh);
        }
    }
    /*
    cout<<aCh<<" "<<bCh<<endl;
    cout<<"-"<<znak<<"-"<<endl;
    cout<<aZnam<<" "<<bZnam<<endl;
    //*/
    int x=NOD(outCh,outZnam);
    outCh/=x;
    outZnam/=x;
    if(otricatelno)cout<<'-';
    cout<<outCh<<'/'<<outZnam<<endl;
}

/*
*/
