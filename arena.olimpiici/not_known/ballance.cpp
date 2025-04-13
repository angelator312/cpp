#include <iostream>
using namespace std;
int main()
{
    int n,ab=0,cd=0,otrez=0;
    string str;
    cin >> n >> str;
    // @param i int number of elements 
    for (int i = 0; i < str.size(); i++){
        if (str[i] == 'a' || str[i] == 'b')ab++;
        if (str[i] == 'c' || str[i] == 'd')cd++;
        // cout<<str<<endl;
        if(ab==cd){
            // cout<<ab<<endl;
            if(ab*2>otrez)otrez=ab*2;
        }
    }
    
    cout << otrez << endl;
    return 0;
}