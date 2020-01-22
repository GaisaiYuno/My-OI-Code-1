#include<queue>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define fo(i,l,r) for(int i=l;i<=r;i++)
#define of(i,l,r) for(int i=l;i>=r;i--)
#define fin(x) freopen(x,"r",stdin)
#define fou(x) freopen(x,"w",stdout)
using namespace std;

inline int rd()
{
	int x=0,f=1;
	char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=-1;
	for(;ch>='0'&&ch<='9';ch=getchar())x=x*10+ch-'0';
	return x*f;
}

const int N=(int)5e5+10;
typedef long long ll;

struct node{
	int x,w;
}a[N];

int n,dis,k,l,r,ans=2147483647,u,v;
ll d[N],sum=0;
bool f[N];

bool get(int g)
{
	memset(d,-0x7f,sizeof d);
	memset(f,0,sizeof f);
	d[0]=0;f[0]=1;
	queue<int>q;
	q.push(0);
	while(!q.empty()){
		u=q.front();v=u+1;q.pop();
		while(a[v].x-a[u].x<max(dis-g,0)&&v<=n)v++;
		for(v;v<=n;v++){
			if(a[v].x-a[u].x>dis+g)break;
			if(d[u]+a[v].w>d[v]){
				d[v]=d[u]+a[v].w;
				if(d[v]>=k)return 1;
				if(!f[v]){
					f[v]=1;
					q.push(v);
				}
			}
		}
		f[u]=0;
	}
	return 0;
}

int main()
{
	fin("jump.in");fou("jump.out");
	n=rd();dis=rd();k=rd();
	fo(i,1,n)a[i].x=rd(),a[i].w=rd(),sum=max(sum,sum+a[i].w);
	if(sum<k){puts("-1");return 0;}
	l=0;r=a[n].x-dis;
	while(l<=r){
		int mid=(l+r)>>1;
		if(get(mid))ans=min(ans,mid),r=mid-1;
		else l=mid+1;
	}
	printf("%d\n",ans);
	return 0;
}
