#include <iostream>
#include <cmath>
#include <math.h>
using namespace std;
inline int cmp(int a, int b)
{
    if (a >b)
        return 1;
    else if (a ==b)
        return 0;
    else
        return -1;
}
int main()
{
    int t1, t2, m1, m2;
    cin >> t1 >> m1 >> t2 >> m2;
    m1=t1*60+m1;m2=t2*60+m2;
    int usl=cmp(m1,m2),m;
    if (usl==1)
    {
        m=(1440-m1)+m2;
    }else if(usl==0)
    {
        m=0;
    }else
    {
        m=m2-m1;
    }
    cout<<m<<" "<<(int)(m/30)<<endl;
    return 0;
}