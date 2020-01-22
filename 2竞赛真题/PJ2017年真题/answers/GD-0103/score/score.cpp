#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
using namespace std;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	int a,b,c,ans;
	scanf("%d %d %d",&a,&b,&c);
	ans=(a*2+b*3+c*5)/10;
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
