#include<cstdio>
using namespace std;
int main(){
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	int a,b,c,ans=0;
	scanf("%d%d%d",&a,&b,&c);
	ans=a*20+b*30+c*50;
	ans/=100;
	printf("%d\n",ans);
	fclose(stdin);fclose(stdout);
	return 0;
}
