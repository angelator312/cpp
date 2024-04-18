#include <iostream>
using namespace std;

void next(int &d, int &m, int &y)
{ int days[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

  if((y%4==0 && y%100!=0) || (y%400==0)) days[2]=29;

  if(d<days[m]) {d++; return;}
  if(m<12) {d=1; m++; return;}
  d=1; m=1; y++;
}


int main()
{ int d1,m1,y1,d2,m2,y2;
  char c;

  cin >> d1 >> c >> m1 >> c >> y1;
  cin >> d2 >> c >> m2 >> c >> y2;

	int d=1,m=1,y=1900, n=1;
	int n1, n2;

	while(!(d==1 && m==1 && y==2101))
  { if(d==d1 && m==m1 && y==y1) n1=n;
    if(d==d2 && m==m2 && y==y2) n2=n;
    next(d,m,y); n++;
  }

//  cout << n1 << " " << n2 << endl;
//  cout << n1%7 << " " << n2%7 << endl;

  int br=0;
  for(int n=n1; n<=n2; n++)
    if(n%7==6 || n%7==0) br++;

  cout << br << endl;

	return 0;
}
