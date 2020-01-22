#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstring>
#include<cstdlib>
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	
	int n,m,k,q=0,r,t;
	scanf("%d%d%d",&n,&m,&k);
	q=n*0.2;
	r=m-m*0.7;
	t=k*0.5;
	printf("%d",q+r+t);
	
	return 0;
}
