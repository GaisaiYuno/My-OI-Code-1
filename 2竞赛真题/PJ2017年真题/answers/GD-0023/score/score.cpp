#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	float ans1;int ans2;
	ans1=a*0.2+b*0.3+c*0.5;
	ans2=int(ans1);
	printf("%d\n",ans2);
	return 0;
}
