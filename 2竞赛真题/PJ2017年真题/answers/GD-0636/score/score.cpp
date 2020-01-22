#include<iostream>
#include<cstdio>
using namespace std;
int a,b,c;
int ans=0;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	scanf("%d%d%d",&a,&b,&c);
	ans+=a*20/100;
	ans+=b*30/100;
	ans+=c*50/100;
	printf("%d \n",ans);
	return 0;
}
