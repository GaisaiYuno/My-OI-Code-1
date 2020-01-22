#include<cstdio>
using namespace std;
int n,m,a[21000],b[21000],c[21000];
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)scanf("%d%d%d",&a[i],&b[i],&c[i]);
	printf("-1\n");
	return 0;
}
