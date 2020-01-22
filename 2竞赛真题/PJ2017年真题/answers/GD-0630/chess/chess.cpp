#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
int n,m,x,y,a[102][102],f[102][102];bool k[102][102],b[102][102];
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
    scanf("%d %d",&n,&m);
    for (int i=1;i<=m;i++) 
    {
    	int c;
    	scanf("\n");
    	scanf("%d %d %d",&x,&y,&c);
    	a[x][y]=c+1;b[x][y]=true;
    }
    for (int i=0;i<=101;i++) 
    {
        for (int j=0;j<=101;j++) f[i][j]=10000000;
        a[i][0]=12345;
        a[0][i]=12345;
        a[n+1][i]=12345;
        a[i][n+1]=12345;
    }
    f[1][1]=0;
    for (int i=1;i<=n;i++)
    {
    	for (int j=1;j<=n;j++)
    	{
    		if (i!=1||j!=1)
    		{
    		if (a[i][j]!=0)
    		{
    			if (!b[i-1][j])
    			{if (!(k[i-1][j])&&a[i-1][j]!=a[i][j]) {f[i][j]=min(f[i][j],f[i-1][j]+1);}
    			else f[i][j]=min(f[i][j],f[i-1][j]);}
    			if (!b[i+1][j])
    			{if (!(k[i+1][j])&&a[i+1][j]!=a[i][j]) {f[i][j]=min(f[i][j],f[i+1][j]+1);}
    			else f[i][j]=min(f[i][j],f[i+1][j]);}
    			if (!b[i][j-1])
    			{if (!(k[i][j-1])&&a[i][j-1]!=a[i][j]) {f[i][j]=min(f[i][j],f[i][j-1]+1);}
    			else f[i][j]=min(f[i][j],f[i][j-1]);}
    			if (!b[i][j+1])
    			{if (!(k[i][j+1])&&a[i][j+1]!=a[i][j]) {f[i][j]=min(f[i][j],f[i][j+1]+1);}
    			else f[i][j]=min(f[i][j],f[i][j+1]);}
    			
    			if (a[i+1][j]==a[i][j]) f[i][j]=min(f[i][j],f[i+1][j]);else f[i][j]=min(f[i][j],f[i+1][j]+1);
    			if (a[i-1][j]==a[i][j]) f[i][j]=min(f[i][j],f[i-1][j]);else f[i][j]=min(f[i][j],f[i-1][j]+1);
    			if (a[i][j+1]==a[i][j]) f[i][j]=min(f[i][j],f[i][j+1]);else f[i][j]=min(f[i][j],f[i][j+1]+1);
    			if (a[i][j-1]==a[i][j]) f[i][j]=min(f[i][j],f[i][j-1]);else f[i][j]=min(f[i][j],f[i][j-1]+1);
    		}
    		if (a[i][j]==0)
    		{
    		int o=0;
    	    if ((b[i-1][j])&&(f[i-1][j]+2<f[i][j]))
			{f[i][j]=f[i-1][j]+2;a[i][j]=a[i-1][j];}
    		if ((b[i+1][j])&&(f[i+1][j]+2<f[i][j])) 
			{f[i][j]=f[i+1][j]+2;a[i][j]=a[i+1][j];}
    		if ((b[i][j-1])&&(f[i][j-1]+2<f[i][j]))
			{f[i][j]=f[i][j-1]+2;a[i][j]=a[i][j-1];}
    		if ((b[i][j+1])&&(f[i][j+1]+2<f[i][j]))
			{f[i][j]=f[i][j+1]+2;a[i][j]=a[i][j+1];}
			
			if ((b[i-1][j])&&(f[i-1][j]+2==f[i][j])) o++;
    		if ((b[i+1][j])&&(f[i+1][j]+2==f[i][j])) o++;
    		if ((b[i][j-1])&&(f[i][j-1]+2==f[i][j])) o++;
    		if ((b[i][j+1])&&(f[i][j+1]+2==f[i][j])) o++;
    		if (o>1) k[i][j]=true;
    		}
    	    }
    	}
    }
    if (f[n][n]!=10000000) cout<<f[n][n];else cout<<-1;
    return 0;
}
