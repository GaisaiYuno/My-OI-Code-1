#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstring>
#include<cstdlib>
int s[1005][1005],w[1005][1005];
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	
	int n,m,q=1,t,r,l,k=0,i,j,f=0;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%d",&t,&r,&l);
		if (l==0) 
		{
			s[t][r]=1;
			w[t+1][r]+=3;
			w[t][r+1]+=3;
			w[t-1][r]+=3;
			w[t][r-1]+=3;
		}
		else 
		{
			s[t][r]=2;
			w[t][r+1]+=3;
			w[t+1][r]+=3;
			w[t-1][r]+=3;
			w[t][r-1]+=3;
		}
	}i=1;j=1;
	while ((i<=n)&&(k==0)||(j<=n)&&(k==0))
	{
		l=s[i][j];
		if ((s[i][j+1]==l)&&(j<n)){j++;q=1;}
		else if ((s[i+1][j]==l)&&(i<n)){i++;q=1;}
		else if ((s[i][j+1]>0)&&(j<n)){j++;f++;q=1;}
		else if ((s[i+1][j]>0)&&(i<n)){i++;f++;q=1;}
		else if ((w[i][j+1]>3)&&(j<n)&&(q==1)){j++;f+=2;q=0;s[i][j]=l;}
		else if ((w[i+1][j]>3)&&(i<n)&&(q==1)){i++;f+=2;q=0;s[i][j]=l;}
		else if ((s[i][j+1]==0)&&(q==1)&&(j<n)){j++;f+=2;q=0;s[i][j]=l;}
		else if ((s[i+1][j]==0)&&(q==1)&&(i<n)){j++;f+=2;q=0;s[i][j]=l;}
		else {k=1;f=0;}
	}
	if (f>0)printf("%d",f);
	else printf("%d",-1);
	
	return 0;
}
