#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstring>
#include<cstdlib>
int s[500005],w[500005],l[500005];
long long k,v;
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	
	int n,m,q=0,min=10000000,i,h,g,max=-55555555,u=0,b=0,a,c=0;
	scanf("%d%d%lld",&n,&m,&k);
	for (i=1;i<=n;i++)
	{
		scanf("%d%d",&s[i],&w[i]);
	}i=1;
	while (i<m)
	{
		g=m+i;
		h=m-i;
		for (int j=1;j<=n;j++)
		{
				for (u=0;u<=n;u++)
				if ((s[j+u]>=h+u)&&(s[j+u]<=g+u)&&(w[j]>0)) {a=j+u;}
				else if (s[j+u]>g+u){q+=w[a];u=s[a];break;}
		}
		if (q>=k) {c++;l[c]=i;b=1;}
		q=0;i++;
	}
	for (i=1;i<=c;i++)
	if (l[c]<min) min=l[c];
	if (min<10000000) printf("%d",min);
	if (b==0) printf("%d",-1); 
	
	return 0;
}
