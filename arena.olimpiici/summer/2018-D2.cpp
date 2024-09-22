#include <iostream>
#include <map>
using namespace std;
using LL = long long;
map<LL, LL> mas={};

LL numberOfDivisors(LL num)
{
    LL num2=num;
    if (mas[num])
        return mas[num];

    LL total = 1;
    for (int i = 2; (LL)i * i <= num; i++)
    {
        if (num % i == 0)
        {
            int e = 0;
            do
            {
                e++;
                num /= i;
            } while (num % i == 0);
            total *= e + 1;
        }
    }
    if (num > 1)
    {
        total *= 2;
    }
    // cout<<"n "<<num<<" "<<total<<" n";
    mas[num2] = total;
    return total;
}

// void reshNaEratostenP(LL b)
// {
//     eratosten[0] = 0;
//     eratosten[1] = 0; // da ne e prosto
//     for (LL i = 2; i <= b; i++)
//     {
//         eratosten[i] += 2;
//         // if (eratosten[i] > 2)
//         // {
//         //     continue;
//         // }
//         for (LL j = i * 2; j <= b; j += i)
//             eratosten[j]++;
//     }
// }

int main()
{
    // cout<<1<<endl;
    LL a, b;
    cin >> a >> b;
    // reshNaEratostenP(b);
    // cout<<mas[0]<<endl;
    int br = 0;
    for (LL i = a; i <= b; i++)
    {
        // cout << i << "  ";
        LL a = numberOfDivisors(i);
        // cout << a << "  ";
        // cout << numberOfDivisors(a) << endl;
        // if (eratosten[eratosten[i]] + 0 == 2 && eratosten[i] + 0 > 2)
        if (a > 2 && numberOfDivisors(a) == 2)
        {
            // cout << 1 << endl;
            br++;
        }
    }

    cout << br << endl;
    return 0;
}