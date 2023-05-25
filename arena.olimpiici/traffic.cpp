#include <iostream>
using namespace std;

int main()
{
    char a1,a2,a3;
    cin>>a1>>a2>>a3;
    if(a1!='b'&& a1!='r'){
        cout<<"error"<<endl;
        return 0;
    }
    if(a2!='b'&& (a2!='y'&&a2!='Y')){
        cout<<"error"<<endl;
        return 0;
    }
    if(a3!='b' && (a2!='b'&&a1!='b')){
        cout<<"error"<<endl;
        return 0;
    }
    if(a1=='b'&&a2=='b'&&a3=='b'){
        cout<<"error"<<endl;
        return 0;
    }
    if(a1=='b'&&a2=='Y'&&a3=='b'){
        cout<<"black"<<endl;
        cout<<"YELLOW"<<endl;
        cout<<"black"<<endl;
    }
    if(a1=='b'&&a2=='y'&&a3=='b'){
        cout<<"red"<<endl;
        cout<<"black"<<endl;
        cout<<"black"<<endl;
    }
    if(a1=='r'&&a2=='b'&&a3=='b'){
        cout<<"red"<<endl;
        cout<<"yellow"<<endl;
        cout<<"black"<<endl;
    }
    if(a1=='r'&&a2=='y'&&a3=='b'){
        cout<<"black"<<endl;
        cout<<"black"<<endl;
        cout<<"green"<<endl;
    }
    if(a1=='b'&&a2=='b'&&a3=='g'){
        cout<<"black"<<endl;
        cout<<"black"<<endl;
        cout<<"GREEN"<<endl;
    }
    if(a1=='b'&&a2=='b'&&a3=='G'){
        cout<<"black"<<endl;
        cout<<"yellow"<<endl;
        cout<<"black"<<endl;
    }
    return 0;
}
