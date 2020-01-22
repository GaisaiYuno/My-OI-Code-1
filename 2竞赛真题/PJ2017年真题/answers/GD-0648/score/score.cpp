#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	int a,b,c,ans;
	scanf("%d%d%d",&a,&b,&c);
	int x=a/10,y=b/10,z=c/10;
	ans=x*2+y*3+z*5;
	printf("%d",ans);
	return 0;
}
