// TEST_ZIP: https://arena.olimpiici.com/api/public/problems/1855/zip?download=true
#include <iostream>
#define endl "\n"
#if 0
#define P(a) cout << "[" << __LINE__ << "] : " << a << endl
#else
#define P(a)
#endif
using namespace std;
struct MaxS
{
    int max;
    int max2;
};

MaxS maxABCDE(long long mas[])
{

    MaxS out = {.max = 0, .max2 = 0};
    long long maxInt = 0;
    for (long long i = 0; i < 5; i++)
    {
        if (maxInt < mas[i])
        {
            out.max2 = out.max;
            out.max = i;
            maxInt = mas[i];
        }if (maxInt==mas[i])
        {
            out.max2=i;
        }
        
    }
    return out;
};
int main()
{
    long long mas[5] = {29464578, 30222153, 0, 0, 0}, k = 165631774;
    // mas[0] = 7;
    // mas[1] = 3;
    // k = 6;
    cin >> mas[0] >> mas[1] >> mas[2] >> mas[3] >> mas[4] >> k;
    if (mas[0]+mas[1]+mas[2]+mas[3]+mas[4]<=k)
    {
        cout<<0<<endl;
        return 0;
    }
    
    for (long long i = 0; i < k;)
    {
        MaxS maxS = maxABCDE(mas);
        P(mas[maxS]);
        if (mas[maxS.max] == 0)
        {
            break;
        }
        long long z = max(mas[maxS.max] - mas[maxS.max2], (long long)1);
        mas[maxS.max] -= min(z, k);
        i += min(z, k);
    }
    cout << mas[maxABCDE(mas).max] << endl;
    return 0;
}