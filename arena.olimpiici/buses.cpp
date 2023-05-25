/** NOI-3, 2021,busses

*/

#include <iostream>
using namespace std;

int main()
{ long long p,t,x,y,n,hora=0,minuti=0,avto=0,dHora=0;
 //long long p=45616,t=1546,x=15,y=51,n=10,hora=0,minuti=0,avto=0,dHora=0;
  bool D=false;
  cin >> p>>t>>x>>y>>n;
  for(long long i=1;i<x*p+1;i++)
  {
      minuti++;
      if(i%y==0)
      {
        if(dHora+1<t){hora++;dHora++;}
        else
            {
                if(!D){
                  minuti=0;D=true;
                }
            }
      }
      if(i%x==0 && avto<p)
      {
          if(hora>=n){hora-=n;}
          else
          {
            if(hora<=n-1 && D)break;
            hora=0;
          }
          avto++;
      }
     ///cout<<"hora:"<<hora<<" dHora:"<<dHora<<" i:"<<i<<" D:"<<D<<" minuti:"<<minuti<<endl;
  }
  if(!D)cout<<"No"<<endl;
  else cout<<minuti<<endl;
  return 0;
}
