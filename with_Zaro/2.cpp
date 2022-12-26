#include "types.hpp"

int main() {
    Vs s;
    s.push_back("1");
    s.push_back("2");
    s.push_back("3");
    cout << "Hello, world!\n";
    for(int i=0; i< s.size(); i++) {
        cout << i << "=" << s[i] << endl;
    }
    return 0;
}