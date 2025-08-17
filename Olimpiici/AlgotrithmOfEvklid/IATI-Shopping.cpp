// IATI 2017 - Day 2/Junior/Група B
#include<iostream>
using namespace std;

using LL = long long;
using mint = LL;
using pMM = pair<mint, mint>;
using pII = pair<int, int>;


mint countOfRequests,countOfProducts,moneyHaveToRemain;


inline pMM extendentEvklid(mint a, mint b) noexcept {
    if (b == 0)
        return {1, 0};
    pMM previousPair = extendentEvklid(b, a % b);
    mint x = previousPair.second;
    mint y = previousPair.first - mint(a / b) * previousPair.second;
    return {x, y};
}


void GetRequest()
{
    cin>>countOfProducts;
    if (countOfProducts!=2)
        throw "Stop";
    mint firstCoefficient,secondCoefficient;
    cin>>firstCoefficient>>secondCoefficient;
    cin>>moneyHaveToRemain;
}


int main()
{
    cin>>countOfRequests;
    for(int i=0; i<countOfRequests; ++i)
    {
        GetRequest();
    }
}
