#include <iostream> 
#ifdef DEBUG
#define P(p1,p2) cout<<p1<<" "<<p2<<endl
#else 
#define P(p1,p2) 
#endif
// #define print(...)   
#define ret return 0
using namespace std;
int main(){
    P(12,13);
    P(" cpp:",__cplusplus);
    printf("cpp:%i\n",__cplusplus);
    ret;
}