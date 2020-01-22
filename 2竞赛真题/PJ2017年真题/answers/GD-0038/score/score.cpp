#include<bits/stdc++.h>
using namespace std;
int a,b,c,ans;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	scanf("%d%d%d",&a,&b,&c);
	ans=a*2/10+b*3/10+c*5/10;
	printf("%d",ans);
	return 0;
}
