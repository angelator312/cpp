#include "types.hpp"

int main()
{
    Vs ls;
    fstream s ("1.angelator312", s.in | s.out );
    if (!s.is_open())
    {
        cout << "failed to open "<< "1.angelator312" << '\n';
    }
    else{
        s.seekp(0,ios_base::end);
        s<<"Hello new file"<<'\n';
        s.seekp(0,ios_base::beg);
        for (size_t i = 0; ; i++)
        {
            cout<<i<<'\n';
            string l;
            if(!getline(s,l)){
                break;
            }
            ls.push_back(l);
        }
        cout<<"-----------------------------------------file"<<endl;
        for (size_t i = ls.size(); i > 0 ; i--)
        {
            cout << ls[i]<<'\n';
        }
        
        
    }
    return 0;
}