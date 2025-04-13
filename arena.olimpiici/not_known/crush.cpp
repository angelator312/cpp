#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
  int N;
  cin >> N;
  int A[N];
  long long maxSum=0,K;
  for(int i=0;N>i;i++)
    cin >> A[i];
  for(int k=1;k<N;k++){
    long long pK=0,sK=0,localSum;
    for (int i=0;i<k;i++)pK+=A[i] * A[i];
    for (int i=k;i<N;i++)sK+=A[i];
    localSum=pK*sK;
    if(localSum>maxSum){maxSum=localSum;K=k;}
  }
  cout<<maxSum<<" K="<<K<<endl;
  return 0;
}
