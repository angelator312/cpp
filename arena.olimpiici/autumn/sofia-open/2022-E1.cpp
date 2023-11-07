#include <iostream>
using namespace std;
inline long long toSm(int K1, int M1, int C1)
{
    long long mC1 = K1 * 100000 + M1 * 100 + C1;
    return mC1;
}
inline string toAll(long long Sm)
{
    string out = to_string(Sm / 100000);
    out += " ";
    out += to_string((Sm / 100) % 1000);
    out += " ";
    out += to_string(Sm % 100);
    return out;
}
int main()
{
    int K1, M1, C1;
    int K2, M2, C2;
    int K3, M3, C3;
    cin >> K1 >> M1 >> C1;
    cin >> K2 >> M2 >> C2;
    cin >> K3 >> M3 >> C3;
    long long Sm1 = toSm(K1, M1, C1);
    long long Sm2 = toSm(K2, M2, C2);
    long long Sm3 = toSm(K3, M3, C3);
    long long m23=max(Sm2, Sm3);
    // if (m23 > Sm1)
    // {
    //     if (min(Sm2, Sm3) > Sm1)
    //     {
    //         cout << toAll(max(m23-Sm1,Sm1)) << endl;
    //     }
    // }
    cout<<toAll(Sm1+m23)<<endl;

    return 0;
}