#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
#include<math.h>
using namespace std;
long long ad,n,m,i,x,y,v,q[10],w[10],a[110][110],b[110][110],pp,p1;
void f(long long r, long long t,long long  p,long long ui)
{
   
	if (r==n&&t==n) {
		if (p<ad) {
		pp=1;ad=p;}
		return;
	}
	if ((r<1||r>n)||(t<1||t>n))
	  return;
	for (int i=1;i<=4;i++)
	{
		if (a[r+q[i]][t+w[i]]!=0&&r+q[i]>=1&&t+w[i]>=1&&r+q[i]<=n&&t+w[i]<=n&&b[r+q[i]][t+w[i]]==0)
		{
			if (a[r+q[i]][t+w[i]]!=a[r][t])
			  p1=1;else p1=0;
			b[r+q[i]][t+w[i]]=1;
			f(r+q[i],t+w[i],p+p1,0);
			b[r+q[i]][t+w[i]]=0;
		}else
		{
			if(ui==0&&r+q[i]>=1&&t+w[i]>=1&&r+q[i]<=n&&t+w[i]<=n&&b[r+q[i]][t+w[i]]==0)
			 {
			 	b[r+q[i]][t+w[i]]=1;a[r+q[i]][t+w[i]]=a[r][t];
			 	f(r+q[i],t+w[i],p+2,1);
			 	b[r+q[i]][t+w[i]]=0;a[r+q[i]][t+w[i]]=0;
			 }
		}
	}
	
	
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%lld %lld",&n,&m);ad=2147483647;
	q[1]=0;q[2]=-1;q[3]=1;q[4]=0;
	w[1]=1;w[2]=0;w[3]=0;w[4]=-1;
	for (i=1;i<=m;i++)
	{
		
		scanf("%lld%lld%lld",&x,&y,&v);
		if (v==1) a[x][y]=1;
		if (v==0) a[x][y]=2;
	
	}
	b[1][1]=1;
	if (a[n-1][n-1]==0)cout<<-1;else
	{
	
	f(1,1,0,0);
	 printf("%lld",ad);
	 }
	return 0;
}
