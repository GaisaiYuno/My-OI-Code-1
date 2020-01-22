#include<cstdio>
#include<cstring>
typedef long long LL;
LL n,q,a[1010],b[1010],t1[1010],t2[1010];
char st[1010];
LL change(LL f[],LL t[],LL o)
{
	LL len=strlen(st),x=0;
	for(LL i=0;i<len;i++) { x=x*10+st[i]-'0'; t[o]++; }
	return x;
}
void qsort(LL l,LL r)
{
	LL i=l,j=r,m=a[(l+r)/2];
	while(i<=j)
	{
		while(a[i]<m) i++;
		while(a[j]>m) j--;
		if(i<=j) { LL t=a[i]; a[i]=a[j]; a[j]=t; i++; j--; }
	}
	if(i<r) qsort(i,r);
	if(l<j) qsort(l,j);
}
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%lld %lld",&n,&q);
	memset(t1,0,sizeof(t1)); memset(t2,0,sizeof(t2));
	for(LL i=1;i<=n;i++) { scanf("%s",st); a[i]=change(a,t1,i); }
	qsort(1,n);
	for(LL i=1;i<=q;i++)
	{
		LL k; scanf("%lld %s",&k,st); b[i]=change(b,t2,i);
		bool pd=true;
		for(LL j=1;j<=n;j++)
		{
			if(!pd) break;
			for(LL x=1;x<=t2[i];x++)
			{
				LL ans=1;
				for(LL y=1;y<=t2[i];y++) ans*=10;
				LL c=a[j]%ans;
				if(c==b[i]) { printf("%lld\n",c); pd=false; }
				if(!pd) break;
			}
		}
		if(pd) printf("-1\n");
	}
	return 0;
}
