#include<cstdio>
#include<algorithm>
using namespace std;
bool f,flag;
int n,m,i,j,cd;
long long a[10001],b,syp1,syp2;
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (i=1;i<=n;i++)
	  scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for (i=1;i<=m;i++)
	{
	  scanf("%d%lld",&cd,&b);
	  f=0;flag=0;
	  for (j=1;j<=n;j++)
	  {
	    syp1=b;syp2=a[j];
	  	flag=0;
	  	do
	  	{
	  	  if (syp1%10!=syp2%10) {flag=1;break;}
	  	  syp1/=10;syp2/=10;
	  	}while (syp1>0&&syp2>0);
	  	if (syp1>0)flag=1;
	  	if (flag==0) 
		  {printf("%d\n",a[j]);f=1;break;}
	  }
	  if (f==0) printf("-1\n");
    }
    return 0;
}
