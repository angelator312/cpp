#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    for (int i = 0; i < 100; i++)
    {
        system(("./gen.exe > test/in/"+to_string(i)+".in").c_str());
        system(("./2023-E1.exe < test/in/"+to_string(i)+".in > test/out/"+to_string(i)+".out").c_str());
        sleep(1);

    }
    
    return 0;
}