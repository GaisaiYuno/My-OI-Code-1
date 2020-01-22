#include<iostream>
#include<cstdio>
using namespace std;
int q[500050],w[500050],l,r,mid,l2,r2,mid2,l3,r3,mid3,n,d,k,first,end;
long long tree[2000050],f[500050],maxm;
void down(int now,int L,int R,int e,long long v)
{
	if (L>e||R<e) return;
	if (L==R&&L==e)
	{
		tree[now]=v;
		return;
	}
	down(now*2,L,(L+R)/2,e,v);
	down(now*2+1,(L+R)/2+1,R,e,v);
	tree[now]=max(tree[now*2],tree[now*2+1]);
}
long long query(int now,int L,int R,int ff,int ee)
{
	if (L>ee||R<ff) return -100000000000000;
	if (ff<=L&&R<=ee) return tree[now];
	return max(query(now*2,L,(L+R)/2,ff,ee),query(now*2+1,(L+R)/2+1,R,ff,ee));
}
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d%d%d",&n,&d,&k);
	for (int i=2;i<=n+1;i++)	
	{
		scanf("%d%d",&q[i],&w[i]);
		q[i]++;
	}
	q[1]=1;
	l=0; r=q[n+1]+1;
	while (l+1<r)
	{
		mid=(l+r)/2;
		for (int i=1;i<=2000010;i++) tree[i]=-100000000000000;
		for (int i=1;i<=n+1;i++) f[i]=-100000000000000;
		f[1]=0;
		down(1,1,n+1,1,0);
		maxm=-100000000000000;
		for (int i=2;i<=n+1;i++)
		{
			first=max(1,q[i]-(d+mid));end=min(q[i]-1,q[i]-(d-mid));
			l2=0;r2=i;
			while (l2+1<r2)
			{
				mid2=(l2+r2)/2;
				if (q[mid2]>=first) r2=mid2; else l2=mid2;
			}
			l3=0;r3=i;
			while (l3+1<r3)
			{
				mid3=(l3+r3)/2;
				if (q[mid3]>end) r3=mid3; else l3=mid3;
			}
			f[i]=query(1,1,n,r2,l3)+w[i];
			down(1,1,n+1,i,f[i]);
			maxm=max(maxm,f[i]);
		}
		if (maxm>=k) r=mid;else l=mid;
	}
	if (r==q[n+1]+1) cout<<-1; else cout<<r;
	return 0;
}
