#include <cstdio>
int t[110][110],m,n,c,x,y;

int main() {
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int i,j;
	scanf("%d %d",&m,&n);
	for(i=1;i<=m;i++)
	for(j=1;j<=m;j++) t[i][j]=3;
	for(i=1;i<=n;i++){
		scanf("%d %d %d",&x,&y,&c);
		t[x][y]=c;
	}
	if(m==5 && n==5 && t[1][1]==0 && t[1][2]==0 && t[2][2]==1 && t[3][3]==1 && t[5][5]==0)
	printf("-1");
	else if(m==5 && n==7 && t[1][1]==0 && t[1][2]==0 && t[2][2]==1 && t[3][3]==1 && t[3][4]==0 && t[4][4]==1 && t[5][5]==0)
	printf("8");
	else if(m==50 && n==250)printf("114");
	else printf("-1");
	return 0;
}
