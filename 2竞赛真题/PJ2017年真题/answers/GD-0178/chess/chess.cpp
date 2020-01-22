//chess
//hrf
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int MAXM=109;
int n,m,a[MAXM][MAXM],f[MAXM][MAXM];
void in(){
	int x,y,c;
	cin>>m>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&x,&y,&c);
		a[x][y]=c;
	}
}
void change(int x,int y,int i,int j){
	if(a[i+1][j]!=-1&&a[x][y]==a[i+1][j])f[i+1][j]=min(f[i+1][j],f[i][j]);
	if(a[i-1][j]!=-1&&a[x][y]==a[i-1][j])f[i-1][j]=min(f[i-1][j],f[i][j]);
	if(a[i][j-1]!=-1&&a[x][y]==a[i][j-1])f[i][j-1]=min(f[i][j-1],f[i][j]);
	if(a[i][j+1]!=-1&&a[x][y]==a[i][j+1])f[i][j+1]=min(f[i][j+1],f[i][j]);
	//yise
	if(a[i][j+1]!=-1&&a[x][y]!=a[i][j+1])f[i][j+1]=min(f[i][j+1],f[i][j]+1);
	if(a[i][j-1]!=-1&&a[x][y]!=a[i][j-1])f[i][j-1]=min(f[i][j-1],f[i][j]+1);
	if(a[i+1][j]!=-1&&a[x][y]!=a[i+1][j])f[i+1][j]=min(f[i+1][j],f[i][j]+1);
	if(a[i-1][j]!=-1&&a[x][y]!=a[i-1][j])f[i-1][j]=min(f[i-1][j],f[i][j]+1);
}
int go();
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	memset(f,190000,sizeof(f));
	for(int i=1;i<=MAXM;i++)
	for(int j=1;j<=MAXM;j++)
	  a[i][j]=-1;
	in();
	go();
	return 0;
}
int go(){
	int i=1,j=1;
	f[i][j]=0;
	for(int i=1;i<=m;i++)
	for(int j=1;j<=m;j++)
	{
		//yise
		 if(a[i][j]!=-1)//se
		{
	    if(a[i-1][j]!=a[i][j]&&a[i-1][j]!=-1)f[i-1][j]=min(f[i-1][j],f[i][j]+1);
	    if(a[i][j-1]!=a[i][j]&&a[i][j-1]!=-1)f[i][j-1]=min(f[i][j-1],f[i][j]+1);
	    if(a[i][j+1]!=a[i][j]&&a[i][j+1]!=-1)f[i][j+1]=min(f[i][j+1],f[i][j]+1);
	    if(a[i+1][j]!=a[i][j]&&a[i+1][j]!=-1)f[i+1][j]=min(f[i+1][j],f[i][j]+1);
	    //tongse
	    	if(a[i+1][j]==a[i][j])f[i+1][j]=min(f[i+1][j],f[i][j]);
	        if(a[i][j-1]==a[i][j])f[i][j-1]=min(f[i][j-1],f[i][j]);
	        if(a[i][j+1]==a[i][j])f[i][j+1]=min(f[i][j+1],f[i][j]);
	        if(a[i-1][j]==a[i][j])f[i-1][j]=min(f[i-1][j],f[i][j]);
	    //kongge
	    if(a[i-1][j]==-1){f[i-1][j]=min(f[i-1][j],f[i][j]+2);change(i,j,i-1,j);}
	    if(a[i][j-1]==-1){f[i][j-1]=min(f[i][j-1],f[i][j]+2);change(i,j,i,j-1);}
	    if(a[i][j+1]==-1){f[i][j+1]=min(f[i][j+1],f[i][j]+2);change(i,j,i,j+1);}
	    if(a[i+1][j]==-1){f[i+1][j]=min(f[i+1][j],f[i][j]+2);change(i,j,i+1,j);}
	    }
	}
	if(f[m][m]==0)cout<<-1;
	else  cout<<f[m][m];
	return 0;
}
