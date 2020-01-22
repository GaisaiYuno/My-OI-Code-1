#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;

const int maxn=100005;

struct snowboots {
	int s,d,id;
} a[maxn]; //Ñ¥×Ó 

struct block{
	int s,d;
} b[maxn]; //µØ×© 

int n,m;
int fa[maxn];

bool cmpa(snowboots x,snowboots y)
{
	return x.s>y.s;
}
bool cmpf(block x,block y)
{
	return x>y;
}

int find(int x)
{
	if (x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}

int main()
{
	freopen("snowboots.in","r",stdin);
	freopen("snowboots.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for (int i=1; i<=n; i++)
		scanf("%d",&f[i]);
	for (int i=1; i<=m; i++)
	{
		scanf("%d%d",&a[i].s,&a[i].d);
		a[i].id=i;
	}
		
	sort(a+1,a+1+m,cmpa);
	sort(f+1,f+1+n,cmpf);
	
	for (int i=1; i<=n; i++)
	{
		if ()
	}
		
	return 0;
}
