#include <iostream>
using namespace std;
inline int  razl(int a, int b)
{
    return max(a, b) - min(a, b);
}
int main()
{
    int a1, a2, a3, a4, mn, t;
    cin >> a1 >> a2 >> a3 >> a4;
    int a12 = a1 + a2, a13 = a1 + a3, a14 = a1 + a4;
    int a23 = a2 + a3, a24 = a2 + a4;
    int a34 = a3 + a4;
    mn =razl(a12,a34) ;
    t =razl(a23,a14) ;
    if (t < mn)
    {
        swap(t, mn);
    }

    t =razl(a24,a13);
    if (t < mn)
    {
        swap(t, mn);
    }

    t =razl(a12+a3,a4);
    if (t < mn)
    {
        swap(t, mn);
    }

    t =razl(a23+a4,a1);
    if (t < mn)
    {
        swap(t, mn);
    }

    cout<<mn<<endl;
   

   return 0;

}