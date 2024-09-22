#include <bits/stdc++.h>
using namespace std;
using LL = long long;
LL getRand16()
{
    return rand() % (1LL << 16);
}
LL getRand32()
{
    return getRand16() % (1LL << 16) + getRand16();
}
LL getRand64()
{
    return getRand32() % (1LL << 16) + getRand32();
}
LL getRandom(LL from, LL to)
{
    return getRand64() % (to - from) + to;
}

int main()
{
    srand(time(0));
    int n = getRandom(0,100);
    cout << n << endl;
    vector<int> numbers;
    for (int i = 0; i < n; i++)
    {
        numbers.push_back(getRandom(0,100));
        cout<<numbers[i]<<endl;
    }
    sort(numbers.begin(), numbers.end());

    cout<<" "<<numbers[0];
    cout<<" "<<numbers[1];
    cout<<" "<<numbers[2];
    cout<<" "<<numbers[4];
    cout<<" "<<numbers[3]<<endl;
    
    return 0;
}