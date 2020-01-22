#include<cstdio>

using namespace std;
int a,b,c,ans;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	#endif
	scanf("%d%d%d",&a,&b,&c);
	ans=a/5+b/10*3+c/2;
	printf("%d\n",ans);
	return 0;
}
