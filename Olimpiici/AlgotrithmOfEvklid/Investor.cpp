#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

using LL = long long;
using mint = LL;
using pMM = pair<mint, mint>;
using pII = pair<int, int>;

const int BIGGEST_INDEX = 47;

mint indexOfPayment, paymentMoney;

pII coefficients[BIGGEST_INDEX];

inline void Read() noexcept {
    cin >> indexOfPayment >> paymentMoney;
    --indexOfPayment;
}

inline pMM extendentEvklid(mint a, mint b) noexcept {
    if (b == 0)
        return {1, 0};
    pMM previousPair = extendentEvklid(b, a % b);
    mint x = previousPair.second;
    mint y = previousPair.first - mint(a / b) * previousPair.second;
    return {x, y};
}

inline void fillCoefficients() noexcept {
    coefficients[0].first = 1;
    coefficients[0].second = 0;

    coefficients[1].first = 0;
    coefficients[1].second = 1;

    for (int i = 2; i < BIGGEST_INDEX; ++i) {
        coefficients[i] = coefficients[i - 2];
        coefficients[i].first += coefficients[i - 1].first;
        coefficients[i].second += coefficients[i - 1].second;
    }
}

int main() noexcept {
    fillCoefficients();
    Read();

    int firstCoefficient = coefficients[indexOfPayment].first;
    int secondCoefficient = coefficients[indexOfPayment].second;

    mint nod = __gcd(firstCoefficient, secondCoefficient);
    firstCoefficient /= nod;
    secondCoefficient /= nod;

    pMM outPair = extendentEvklid(firstCoefficient, secondCoefficient);

    outPair.first*=paymentMoney;
    outPair.second*=paymentMoney;

    mint tMinForX=ceil(-outPair.first/secondCoefficient);
    mint tMaxForX=floor(outPair.second/firstCoefficient);

    mint x=outPair.first+(tMinForX-1)*secondCoefficient;
    mint y=outPair.second-(tMinForX-1)*firstCoefficient;
    LL cnt=0;
    for(int i=tMinForX; i<=tMaxForX; ++i)
    {
        x+=secondCoefficient;
        y-=firstCoefficient;
        // cerr<<x<<" "<<y<<endl;
        if(y<=0)break;
        if(x>0)
            ++cnt;
    }

    // cerr << outPair.first<<"*"<<firstCoefficient << "+" << outPair.second<<"*"<<secondCoefficient<<"="<<paymentMoney << endl;
    cout<<cnt<<endl;
    return 0;
}
