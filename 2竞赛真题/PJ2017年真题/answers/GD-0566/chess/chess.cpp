#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int m,n,c[105][105],x,y,an[105][105],i,j,p[105][105];
int js(int a,int b)
{ 
	int x1=10000000;
	if(c[a][b]==-1){
	if(p[a-1][b]==1&&p[a][b-1]==1) {return 10000000;}
	if(an[a-1][b]<an[a][b-1])
	{x1=an[a-1][b]+2;c[a][b]=c[a-1][b];p[a][b]=1;}	
	    else
	    {x1=an[a][b-1]+2;c[a][b]=c[a][b-1];p[a][b]=1;}
    return x1;
	}
    
	if(c[a][b]==c[a][b-1]) x1=an[a][b-1];
	if(c[a][b]==c[a-1][b]) {x1=min(an[a-1][b],x1);return x1;}
	if(c[a][b]!=c[a][b-1])x1=min(x1,an[a][b-1]+1);
	if(c[a][b]!=c[a-1][b])x1=min(x1,an[a-1][b]+1);
	return x1;
}
int main()
{	
freopen("chess.in","r",stdin);
freopen("chess.out","w",stdout);
	cin>>m>>n;
	for(i=0;i<=m+1;i++)
	for(j=0;j<=m+1;j++)
	{
		c[i][j]=-1;
		an[i][j]=10000000;
	}
	an[1][1]=0;
	for(i=1;i<=n;i++){//ÊäÈë 
		scanf("%d%d",&x,&y);
		scanf("%d",&c[x][y]);
	}
	for(i=2;i<=m;i++)
	{
		if(c[i-1][1]!=10000000){
			if(c[i][1]==c[i-1][1]) an[i][1]=an[i-1][1];
		else 
		if(c[i][1]==-1&&p[i-1][1]==0) {
			an[i][1]=an[i-1][1]+2;p[i][1]=1;c[i][1]=c[i-1][1];}
			else c[i][1]=c[i-1][1]+1;}
			if(c[1][i-1]!=10000000){
				if(c[1][i]==c[1][i-1]) an[1][i]=an[1][i-1];
		else if(c[1][i]==-1&&p[1][i-1]==0) {
			an[1][i]=an[1][i-1]+2;p[1][i]=1;c[1][i]=c[1][i-1];}
			else c[1][i]=c[1][i-1]+1;
			}
		}
	for(i=2;i<=m;i++)
	for(j=i;j<=m;j++)
	{
		an[i][j]=js(i,j);
		an[j][i]=js(j,i);
	}
	if(an[m][m]==10000000) printf("-1\n");
	else printf("%d\n",an[m][m]);
return 0;
	return 0;
}
