#include <bits/stdc++.h>
#include <stdlib.h> /* srand, rand */
#include <time.h>   /* time */

using namespace std;
// using LL = long long;
string abc = "", abc2 = "", sp = "", sp2="";
void start()
{

    for (int i = 0; i < 26; i++)
        abc += (char)('a' + i);

    for (int i = 0; i < 26; i++)
        abc2 += (char)('A' + i);
    for (int i = 0; i < 26; i++)
        sp += (char)('!' + i);
    
    for (int i = 0; i < 6; i++)
        sp2 += (char)(';' + i);
    for (int i = 0; i < 6; i++)
        sp2 += (char)('[' + i);
    for (int i = 0; i < 4; i++)
        sp2 += (char)('{' + i);
}

bool isD(char a)
{
    for (char x:sp2)
    {
        if(x==a)return 1;
    }
    return 0;
    
}

string morseToString(string a)
{
    string out = "";
    for (char x : a)
    {
        if (x == '-' || x == '—')
            out += "b";
        else if (x == '.' || x == '•')
            out += "a";
        else if (x == '/')
            out += "c";
        else
            out += "d";
    }
    return out;
}

string stringToMorse(string a)
{
    string out = "";
    for (char x : a)
    {
        if (x == 'b')
            out += "-";
        else if (x == 'a')
            out += ".";
        else if (x == 'c')
            out += "/";
        else
            out += " ";
    }
    return out;
}

string encrypt(string a)
{
    string out = "";
    // a e ot a, b i c

    for (char x : a)
    {
        bool koe = rand() % 2;
        int k = rand() % 26;

        if (x == 'a')
            if (k % 2 == 0)
                k += 1, k %= 26;
        if (x == 'b')
            if (k % 2 == 1)
                k += 1, k %= 26;
        if (x == 'c')
        {
            out += sp[k % 22];
            continue;
        }
        if (x == 'd')
        {
            out += sp2[k % 16];
            continue;
        }
        // cout << k << endl;
        if (koe)
            out += abc[k];
        else
            out += abc2[k];
    }
    return out;
}

string decrypt(string a)
{
    string out = "";
    // a e ot a, b i c

    for (char x : a)
    {
        if (isD(x))
        {
            out += "d";
            continue;
        }
        if (x <= 'Z' && x >= 'A')
        {
            int k = x - 'A';
            if (k % 2 == 0)
                out += "b";
            else
                out += "a";
        }
        else if (x <= 'z' && x >= 'a')
        {
            int k = x - 'a';
            if (k % 2 == 0)
                out += "b";
            else
                out += "a";
        }
        else
            out += "c";
    }
    return out;
}

int main()
{
    srand(time(NULL));
    start();
    // cout<<sp<<endl;
    string s;
    char c;
    cin >> c;
    if (c == 'd' || c == 'D')
    {
        cin >> s;
        cout << decrypt(s) << endl;
    }
    else if (c == 't')
    {
        string a;
        while (cin >> a)
        {
            if (a == "Stop")
                break;
            s += " ";
            s += a;
        }
        cout << morseToString(s) << endl;
    }
    else if (c == 'm')
    {
        cin >> s;
        cout << stringToMorse(s) << endl;
    }
    else if (c == 'e' || c == 'E')
    {
        cin >> s;
        cout << encrypt(s) << endl;
    }
    return 0;
}