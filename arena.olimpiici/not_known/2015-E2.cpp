#include <iostream>
using namespace std;
using LL = long long;
int main()
{
    int a, b, o, sedm, den;
    string days[5] = {"Friday", "Monday", "Tuesday", "Wednesday", "Thursday"};
    cin >> a;
    b = (a + 5) / 6;
    sedm = (b + 4) / 5;
    den = b % 5;
    if (sedm == 9)
        sedm = 10;

    cout << "Week " << sedm << " " << days[den] << endl;
}