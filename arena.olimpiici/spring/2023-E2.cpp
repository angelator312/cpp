#include <iostream>
#include <algorithm>
using namespace std;
using LL = int;
// const int N = 1e7;
// int mas[N];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    // char a;
    LL lengthMain = 0;
    string mas;
    cin >> mas;
    int length = mas.size();
    // cout<<"zawyrshi"<<endl;
    for (int i = 0; i < length; i++)
    {
        bool isIn[127]{};
        int j = i;

        while (!isIn[mas[j]] && j < length)
        {
            isIn[mas[j]] = 1;
            j++;
        }
        // cout << i << " " << j << endl;
        // for (int k = 33; k <= 126; k++)
        //     isIn[k] = 0;
        lengthMain = max(lengthMain,  (j - i));
        // i = j-1;
    }

    cout << lengthMain << endl;
    return 0;
}