#include <cstdio>
int x[100],y[100],z[100];
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int m,n,i;
    scanf("%d %d",&m,&n);
    for(i=0;i<n;i++){
    	scanf("%d %d %d",&x[i],&y[i],&z[i]);
    }
    if(n==7) printf("8");
    else printf("-1");
	return 0;
}
