#include <iostream>
using namespace std;
typedef long NUM;
bool prosto[60000];
NUM Eratosten(){
    for (int i = 2; i < 60000; i++)
        prosto[i] =true;
    
    for(NUM i = 2; i < 60000; i++)
    {
        for (NUM j = i+i; j < 60000; j+=i)
        {
            prosto[j] =false;
        }
        
    }
    
    return 0;
}
NUM del(NUM ch){
    NUM d=2;
    if(ch==2)return 2;
    while (ch>1)
    {
        if(ch%d != 0)
        {
            do 
            {
                d++;
                if(d>60000){cerr<<"ERROR: "<<d<<endl;}
            }while(!prosto[d]);
        }
        else ch /=d;
    }
    return d;
}
int main()
{
    Eratosten();
    NUM N,posl=2;
    cin >> N;
    for (NUM i = 1; i < N;i++)
    {
        posl=posl+del(posl);
    }
    cout<<posl<<endl;
    return 0;
}