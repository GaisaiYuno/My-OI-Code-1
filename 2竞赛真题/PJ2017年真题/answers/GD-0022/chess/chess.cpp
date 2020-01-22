#include<cstdio>
#include<cstring>
int qi[103][103],m,x,y,q,n,o,qwe[3][1000],u=0;
int ans=-1;
int b[8]={0,1,0,-1,1,0,-1,0};
void he(int e,int r,int mon,int mo)
{
	if(e==m&&r==m)
	{
		if(ans==-1)	ans=mon;
		else{
			if(ans>mon)	ans=mon;
		}
		return;
	}
	int t=qi[e][r];
	qi[e][r]=4;
	for(int i=0;i<4;i++)
	{
		if(qi[e+b[2*i]][r+b[2*i+1]]==0)	o=0;
		else if(qi[e+b[2*i]][r+b[2*i+1]]==1)
		{
			qwe[0][u]=e+b[2*i];
			qwe[1][u]=r+b[2*i+1];
			qwe[2][u]=2;
			u++;
			qi[e+b[2*i]][r+b[2*i+1]]=qi[e][r];
			he(e+b[2*i],r+b[2*i+1],mon+2,1);
		}
		else if(qi[e+b[2*i]][r+b[2*i+1]]<4)
		{
			if(qi[e+b[2*i]][r+b[2*i+1]]!=t)	he(e+b[2*i],r+b[2*i+1],mon+1,0);
			else	he(e+b[2*i],r+b[2*i+1],mon,0);
		}
	}
	if(mo==0)	qi[e][r]=t;
	else	qi[e][r]=6;
	return;
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	memset(qi,0,sizeof(qi));
	scanf("%d%d",&m,&n);
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			qi[i+1][j+1]=1;
		}
	}
	for(int i=0;i<n;i++)
	{
		scanf("%d%d%d",&x,&y,&q);
		qi[x][y]=q+2;
	}
	he(1,1,0,0);
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
