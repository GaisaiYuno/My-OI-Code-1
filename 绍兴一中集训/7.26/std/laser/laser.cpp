#include <cstdio>
#include <map>
#include <algorithm>

using namespace std;

const int N=11;
map <long long,int> M[N];
map <long long,int> T;
int n,m,i,j,k,q,tx,ty,s,num;
int x[N],y[N],dx[N],dy[N];
bool pd;

int gcd(int a,int b){return b==0?a:gcd(b,a%b);}
int main()
{
	freopen("laser.in","r",stdin);
	freopen("laser.out","w",stdout);
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
		scanf("%d%d",&tx,&ty);
		if (tx<0) tx=-tx,ty=-ty;
		y[i]=-tx,x[i]=ty;
		tx=abs(y[i]),ty=abs(x[i]),k=gcd(tx,ty);
		y[i]=y[i]/k,x[i]=x[i]/k;
		for (j=1;j<i;j++)
			if ((x[i]==x[j]) && (y[i]==y[j]))
			{
				i--,n--;
				break;
			}
	}
	scanf("%d",&m);
	for (i=1;i<=m;i++)
	{
		scanf("%d%d",&tx,&ty);
		for (j=1;j<=n;j++)
			M[j][1LL*tx*x[j]+1LL*ty*y[j]]++;
		T[tx*(long long) (1e9+1)+ty]++;
	}
	scanf("%d",&q);
	for (i=1;i<=q;i++)
	{
		s=0;
		scanf("%d%d",&tx,&ty);
		for (j=1;j<=n;j++)
			s=s+M[j][1LL*tx*x[j]+1LL*ty*y[j]];
		s=s-(n-1)*T[tx*(long long) (1e9+1)+ty];
		printf("%d\n",s);
	}
	return 0;
}
