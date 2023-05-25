#include <iostream>
using namespace std;
typedef long NUM;
bool prosto[40000];
NUM Eratosten(){
    for (int i = 2; i < 40000; i++)
        prosto[i] =true;
    
    for(NUM i = 2; i < 40000; i++)
    {
        for (NUM j = i+i; j < 40000; j+=i)
        {
            prosto[j] =false;
        }
        
    }
    
    return 0;
}
int main()
{
    Eratosten();
    for(int i = 2; i < 40000; i++)
        if(prosto[i])cout << i <<endl;
    return 0;
}