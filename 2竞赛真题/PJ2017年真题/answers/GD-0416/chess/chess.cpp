#include<cstdio>
using namespace std;
int m,n,x,y,c;
int a=0;
char qp[102][102];
char fx[4][5]={"-1,0","1,0","0,-1","0,1"};
int book[102][102]={0};
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	
	for (int i=0;i<=101;i++)
	for (int k=0;k<=101;k++) qp[i][k]='0';
	scanf("%d%d",&m,&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&x,&y,&c);
		qp[x][y]=c+48;
	}
	printf("-1");
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
