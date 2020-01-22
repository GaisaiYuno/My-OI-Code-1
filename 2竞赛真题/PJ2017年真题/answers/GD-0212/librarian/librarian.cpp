#include<iostream>
#include<cstdio>
#include<math.h>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
int a[10000005],b[10000005],x[10000005],y[10000005],c[1000],u[10000005];
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	int o,w,su,n,m,i,j,k,mina,s,t,q;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	for(i=1;i<=n;i++)
	{
		s=a[i];
		t=0;
		while(s>0)
		{
			s=s/10;
			t++;
		}
		u[i]=t;
	}
	for(i=1;i<=m;i++)
	{
		scanf("%d %d",&x[i],&y[i]);
		q=0;
		mina=9999999;
		o=0;
		for(j=1;j<=n;j++)
		{		
			if(u[j]>=x[i])
			{
				o++;
				s=a[j];
				k=0;
				while(s>0&&k!=x[i])
				{
					k++;
					c[k]=s%10;
					s=s/10;
				}
				t=1;
				w=0;
				su=0;
				while(k>0)
				{	
					w++;
					k--;
					su=t*c[w]+su;
					t=t*10;
				}
				if(su==y[i])
				{
					if(a[j]<mina) mina=a[j];
				}
				else q++;
			}
		}
		if(q==o) cout<<"-1"<<endl;
		else printf("%d\n",mina);
	}
	return 0;
}
