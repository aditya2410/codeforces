#include <iostream>
using namespace std;
typedef long long LL;
const LL M=200200;
LL n,a[M],b[M][2],c[M][2],d;
LL go(LL i,LL j)          //it returns the sum of the values of nodes of path going in the direction (i,j)
{
  if(i<1||i>n)return 0;   //for termination return 0 as no nodes in path ahead
  LL& r=b[i][j],&s=c[i][j];  // reference variables  and b denotes the memoized value of sum 
  // c denotes in which run the node is discovered (run corresponds to various values of a[1])
  if(1==i||s==d)r=-1;     // we are checking i to be 1 specially because it is not marked c[1][j] and marker is same as d
  // we have so many markers for each starting a[1] so we overright them rather reiniatilizing with 0
  else if(!s){    //!s implies the node is not memoized yet(not discovered yet)
    s=d;               // marking it with d 
    LL t=go(i+(j?-a[i]:a[i]),!j);
    r=t<0?-1:t+a[i];
  }
  return r;
}
int main(){
  cin>>n;
  for(LL i=2;i<=n;++i)cin>>a[i];
  for(LL i=1,t;i<n;++i)++d,cout<<((t=go(i+1,1))<0?-1:t+i)<<endl;
}
