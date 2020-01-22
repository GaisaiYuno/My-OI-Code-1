#include<cstdio>
#include<cstdlib>
#include<cstring>

int n,m;
int q[1010];
int tot=0;

bool pdd(int x,int t)
{
	if(t>x)return false;
	while(t>0)
	{
		int t1=x%10,t2=t%10;
		if(t1!=t2)return false;
		t/=10;
		x/=10;
	}
	return true;
}

void pd(int t)
{
	tot=-1;
	int x=t%10;
	for(int i=1;i<=n;i++)
	{
		int y=q[i]%10;
		if(x==y && pdd(q[i],t)==true)
		{
			tot=q[i];
			return;
		}
	}
	return;
}

void kp(int l,int r)
{
	int i=l,j=r,t,m=(q[l]+q[r])/2;
	while(i<=j)
	{
		while(q[i]<m)i++;
		while(q[j]>m)j--;
		if(i<=j)
		{
			t=q[i];q[i]=q[j];q[j]=t;
			i++;j--;
		}
	}
	if(i<r)kp(i,r);
	if(l<j)kp(l,j);
}

int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	scanf("%d",&q[i]);
	kp(1,n);
	for(int i=1;i<=m;i++)
	{
		int x,yy;
		scanf("%d %d",&yy,&x);
		pd(x);
		printf("%d\n",tot);
	}
}
