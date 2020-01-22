#include<cstdio>
#include<cstring>
using namespace std;
FILE *fin=fopen("chess.in","rb"),*fout=fopen("chess.out","wb");
int q[100100][2],n,m,l,r,a[101][101],e[101][101],i,x,y,c,f[101][101],ds;
void ia(int &sa)
{
	sa++;
	if (sa>100000) sa=1;
}
int cn(int sa,int sb)
{
	if(sa<1||sb<1||sa>m||sb>m) return 0;
	return 1;
}
int moneys(int sa,int sb)
{
	 if (sb==0)
	 return 2;
	 if (sa==sb)
	 return 0;
	 return 1;
}
void cg(int x,int y)
{
	if (cn(x,y+1)==1
	&&a[x][y]+a[x][y+1]>0
	&&(ds=f[x][y]+moneys(e[x][y],a[x][y+1]))<f[x][y+1])
		{
			if (e[x][y+1]==0)e[x][y+1]=a[x][y];
			q[r][0]=x;q[r][1]=y+1;
			ia(r);
			f[x][y+1]=ds;
		}
	if (cn(x+1,y)==1
	&&a[x][y]+a[x+1][y]>0
	&&(ds=f[x][y]+moneys(e[x][y],a[x+1][y]))<f[x+1][y])
		{
			if (e[x+1][y]==0)e[x+1][y]=a[x][y];
			q[r][0]=x+1;q[r][1]=y;
			ia(r);
			f[x+1][y]=ds;
		}
	if (cn(x,y-1)==1
	&&a[x][y]+a[x][y-1]>0
	&&(ds=f[x][y]+moneys(e[x][y],a[x][y-1]))<f[x][y-1])
		{
			if (e[x][y-1]==0)e[x][y-1]=a[x][y];
			q[r][0]=x;q[r][1]=y-1;
			ia(r);
			f[x][y-1]=ds;
		}
	if (cn(x-1,y)==1
	&&a[x][y]+a[x-1][y]>0
	&&(ds=f[x][y]+moneys(e[x][y],a[x-1][y]))<f[x-1][y])
		{
			if (e[x-1][y]==0)e[x-1][y]=a[x][y];
			q[r][0]=x-1;q[r][1]=y;
			ia(r);
			f[x-1][y]=ds;
		}
}
int main()
{
	fscanf(fin,"%d%d",&m,&n);
	for(i=1;i<=n;i++)
	{
		fscanf(fin,"%d%d%d",&x,&y,&c);
		a[x][y]=c+1;e[x][y]=c+1;
	}
	memset(f,0x77,sizeof(f));
	q[1][0]=1;
	q[1][1]=1;
	l=1;r=2;
	f[1][1]=0;
	while(l!=r)
	{
		cg(q[l][0],q[l][1]);
		e[x][y]=a[x][y];
		ia(l);
	}
	fprintf(fout,"%d",(f[m][m]==f[0][0])?-1:f[m][m]);
	fclose(fin);fclose(fout);
	return 0;
}
