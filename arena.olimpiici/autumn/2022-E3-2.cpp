#include <iostream>
using namespace std;
int main(){
    int x[5],k,a=-1,b;
    cin>>x[0]>>x[1]>>x[2]>>x[3]>>x[4]>>k;
    b=max(max(x[0],x[1]),max(max(x[2],x[3]),x[4]));
    for (int i=(a+b)/2 ;a+1< b;i=(a+b)/2)
    {
       int s=0;
       for (int j = 0; j < 5; j++)
       {
        if (x[j]>i)
       {
        s+=x[j]-i;
       }
       }

       if(s<=k){
        b=i;
       }else{
        a=i;
       }
    }
    cout<<b<<endl;
    
}