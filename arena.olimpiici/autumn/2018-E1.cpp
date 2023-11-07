#include <iostream>
using namespace std;
inline long long razl(int A, int B)
{
    return (max(A, B) - min(A, B)) + 1;
}
long long isPres(int A, int B, int C, int D)
{
    if (A > B)
    {
        swap(A, B);
    }
    if (C > D)
    {
        swap(C, D);
    }
    long long dKAll = min(B, D);
    long long lKAll = max(A, C);
    if (lKAll <= dKAll)
    {
        return razl(lKAll, dKAll);
    }
    else
    {
        // cout<<2<<endl;
        return 0;
    }
}
int main()
{
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    // cout << isPres(A, B, C, D) << endl;
    cout << razl(A, B) + razl(C, D) - isPres(A, B, C, D) << endl;
}