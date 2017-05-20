#include <iostream>
#include <stdio.h>

#define rep(i,a,b) for(int i = (a); i <= (b); i++)
using namespace std; 
typedef long long ll;

FILE* f1=freopen("input.txt", "r", stdin);
FILE* f2=freopen("output.txt", "w", stdout);

const ll T=1000300200;
int a[200200],n;
ll b[200200][2];
bool c[200200];

ll dfs()
{
	
	int curr=1;
	ll sum=0;
	bool j=1;
	c[1]=1;
	while(true)
	{
		sum=sum+a[curr];
		curr=b[curr][j];
		if(curr==T)
			return sum;
		if (c[curr]==1)
			{return -1;}
		else
			{
				c[curr]=1;
			}
		j=(j+1)%2;		

	}
}

int main(int argc, char const *argv[])
{
	cin>>n;
	rep(i,2,n)
	{
		cin>>a[i];
		b[i][0]=(i-a[i])>0?i-a[i]:T;
		b[i][1]=(i+a[i]-n)>0?T:i+a[i];
	}
	ll k;
	rep(i,1,n-1)
	{
		rep(l,1,n) c[l]=0;
		a[1]=i;
		b[1][0]=(1-a[1])>0?1-a[1]:T;
		b[1][1]=(1+a[1]-n)>0?T:1+a[1];
	    k=dfs();
	    cout<<k<<"\n";
	}
	return 0;
}
