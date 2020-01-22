#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
#include<deque>
using namespace std;
int a,b,c,ans=0;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	scanf("%d%d%d",&a,&b,&c);
	ans+=(a/10)*2;
	ans+=(b/10)*3;
	ans+=(c/10)*5;
	printf("%d\n",ans);
	return 0;
}

