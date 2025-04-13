#include <iostream>
#include <algorithm>
using namespace std;
int sum(int x,int y)
{
    int a[3]={x%10,x/10%10,x/100};
    int b[3]={y%10,y/10%10,y/100};
    int s=0;

    s+=(a[0]+b[0])%10;
    s+=((a[1]+b[1])%10)*10;
    s+=((a[2]+b[2]))*100;
    return s;
}
int main()
{
    int a,b;
    char z;
    cin >> a>>z>>b;
    
    cout <<sum(a,b)<< endl;
    cout <<a+b<< endl;
    return 0;

}