#include<iostream>

using namespace std;
int posX[10]={1,0,1,2,0,1,2,0,1,2};
int posY[10]={3,0,0,0,1,1,1,2,2,2};
int hOrg,mOrg;
char z;
#define print2(a,b,out)\
    out<<a/10<<a%10;\
    out<<":";\
    out<<b/10<<b%10<<"\n";
inline int dist(int a,int b)
{
   return abs(posX[a]-posX[b])+abs(posY[a]-posY[b]);
}
inline int usilie(int h,int m)
{
    return dist(h/10,h%10)+dist(h%10,m/10)+dist(m/10,m%10);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);cout.tie(nullptr);
    cin>>hOrg>>z>>mOrg;
    int distMin=1000,distN=0;
    int lastH,lastM;
    for(int h=hOrg;h<=99;h+=24)
    {
        for(int m=mOrg;m<=99;m+=60)
        {
            distN=usilie(h,m);
            if(distMin>distN)
            {
                lastH=h;
                lastM=m;
                distMin=distN;
            }
            //print2(h,m,cerr);
            //cerr<<distN<<endl;

        }
    }
    print2(lastH,lastM,cout);
    return 0;
}
