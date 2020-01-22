#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int zy,xc,ks;
int sum=0;
int main()
{   
    freopen("score.in","r",stdin);
    freopen("score.out","w",stdout);
    scanf("%d%d%d",&zy,&xc,&ks);
	zy/=10;
	xc/=10;
	ks/=10;
	sum+=zy*2+xc*3+ks*5;
	printf("%d",sum);
	return 0;	  
}
