#include<cstdio>
#include<iostream>
using namespace std;
bool tf[101][101];
int n,m,g[101][101],step[101][101];
void dfs(int a,int b)
{
	if((a+1>=1 && a+1<=m) && (b>=1 && b<=m))
	{
		if(!tf[a+1][b] && g[a+1][b]!=-1) g[a+1][b]=-1;
		if(g[a+1][b]!=-1)
		{
			if(g[a+1][b]==g[a][b] && step[a][b]<step[a+1][b]){step[a+1][b]=step[a][b]; dfs(a+1,b);}
			if(g[a+1][b]!=g[a][b] && step[a][b]+1<step[a+1][b]){step[a+1][b]=step[a][b]+1; dfs(a+1,b);}
		}	
		else
			if(tf[a][b] && step[a][b]+2<step[a+1][b]){g[a+1][b]=g[a][b]; step[a+1][b]=step[a][b]+2; dfs(a+1,b);}
	}
	if((a>=1 && a<=m) && (b+1>=1 && b+1<=m))
	{
		if(!tf[a][b+1] && g[a][b+1]!=-1) g[a][b+1]=-1;
		if(g[a][b+1]!=-1)
		{
			if(g[a][b+1]==g[a][b] && step[a][b]<step[a][b+1]){step[a][b+1]=step[a][b]; dfs(a,b+1);}
			if(g[a][b+1]!=g[a][b] && step[a][b]+1<step[a][b+1]){step[a][b+1]=step[a][b]+1; dfs(a,b+1);}
		}	
		else
			if(tf[a][b] && step[a][b]+2<step[a][b+1]){g[a][b+1]=g[a][b]; step[a][b+1]=step[a][b]+2; dfs(a,b+1);}
	}
	if((a-1>=1 && a-1<=m) && (b>=1 && b<=m))
	{
		if(!tf[a-1][b] && g[a-1][b]!=-1) g[a-1][b]=-1;
		if(g[a-1][b]!=-1)
		{
			if(g[a-1][b]==g[a][b] && step[a][b]<step[a-1][b]){step[a-1][b]=step[a][b]; dfs(a-1,b);}
			if(g[a-1][b]!=g[a][b] && step[a][b]+1<step[a-1][b]){step[a-1][b]=step[a][b]+1; dfs(a-1,b);}
		}	
		else
			if(tf[a][b] && step[a][b]+2<step[a-1][b]){g[a-1][b]=g[a][b]; step[a-1][b]=step[a][b]+2; dfs(a-1,b);}
	}
	if((a>=1 && a<=m) && (b-1>=1 && b-1<=m))
	{
		if(!tf[a][b-1] && g[a][b-1]!=-1) g[a][b-1]=-1;
		if(g[a][b-1]!=-1)
		{
			if(g[a][b-1]==g[a][b] && step[a][b]<step[a][b-1]){step[a][b-1]=step[a][b]; dfs(a,b-1);}
			if(g[a][b-1]!=g[a][b] && step[a][b]+1<step[a][b-1]){step[a][b-1]=step[a][b]+1; dfs(a,b-1);}
		}	
		else
			if(tf[a][b] && step[a][b]+2<step[a][b-1]){g[a][b-1]=g[a][b]; step[a][b-1]=step[a][b]+2; dfs(a,b-1);}
	}
	return;
}
int main()
{
	int x,y,c,i,j;
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d",&m,&n);
	for(i=1;i<=m;i++)
		for(j=1;j<=m;j++){g[i][j]=-1; step[i][j]=9999999; tf[i][j]=false;}
	step[1][1]=0; for(i=1;i<=n;i++){scanf("%d%d%d",&x,&y,&c); g[x][y]=c; tf[x][y]=true;} dfs(1,1); 
	if(step[m][m]!=9999999) printf("%d",step[m][m]);
	else printf("-1");
	fclose(stdin); fclose(stdout); return 0;
}
