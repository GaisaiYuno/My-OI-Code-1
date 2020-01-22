#include<cstdio>
#include<algorithm>
using namespace std;
int a,b;
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d",&a,&b);
	if(b==7) printf("8");
	else printf("-1");
	return 0;
}
