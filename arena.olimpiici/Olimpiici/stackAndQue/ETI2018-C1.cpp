#include <algorithm>
#include <iostream>
#include <stack>

using namespace std;
const int N=3e5+2;
int a[N];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n,ptr_start=0,ptr_end=0;
  cin >> n;
  while(n>0) {
    int t;
    cin >> t;
    if( t==1)
    {
        cin >> a[ptr_end];
        ++ptr_end;
        while (a[ptr_start]==0) ++ptr_start;
        cout<<a[ptr_start]<<" ";  
    }else if( t==2)
    {
        int e;
        cin>>e;
        for (int i = ptr_start; i <ptr_end ; ++i)
        {
            if(a[i]==e)
            {
                a[i]=0;
                break;
            }
        }
        
        while (a[ptr_start]==0) ++ptr_start;
        cout<<a[ptr_start]<<" ";
    }
    --n;
  }
  cout<<endl;
}