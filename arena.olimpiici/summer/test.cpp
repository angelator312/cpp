#include <bits/stdc++.h>
// #include <vector>
using namespace std;
using LL = long long;

LL numberOfDivisors(LL num)
{
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
    return total;
}

int numbOfDivisors(LL a)
{
    int br = 0;
    for (LL i = 2; i * i < a; i++)
        if (a % i == 0)
        {
            br++;
            if (a / i != i)
                br++;
        }
    return br;
}

int main()
{
    LL a;
    cin >> a;
    uint32_t iterations = 100;
    auto begin = chrono::high_resolution_clock::now();

    for (uint32_t i = 0; i < iterations; ++i)
    {
        numberOfDivisors(a);
    }

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - begin).count();

    cout << duration << "ns total, average : " << duration / iterations << " ns." << endl;

    begin = chrono::high_resolution_clock::now();

    for (uint32_t i = 0; i < iterations; ++i)
    {
        numbOfDivisors(a);
    }

    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::nanoseconds>(end - begin).count();

    cout << duration << "ns total, average : " << duration / iterations << " ns." << endl;

    // cout << br << endl;
    return 0;
}