#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int N;
int ans;
bool check(int X)
{
	long long n=N,x=X;
	long long c=n*n-x*x;
	double S=sqrt(c);
	long long s=S;
	if(s*s+x*x==n*n)
		return 1;
	return 0;
}
int main() 
{
	freopen("circle.in","r",stdin);
	freopen("circle.out","w",stdout);
	scanf("%d",&N);
	for(int i=1;i<N;i++)
		if(check(i))
		{
			ans+=4;
		}			
	printf("%d",ans+4);
}
