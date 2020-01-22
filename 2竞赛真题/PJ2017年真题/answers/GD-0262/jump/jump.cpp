#include<map>
#include<queue>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct node{
	int x;
	long long c;
}f[500010];
int l,r;
int n,d,k,up,down;
long long sum,dp[500010];
int min(int x,int y) { return x<y?x:y; }
int max(int x,int y) { return x>y?x:y; }
bool cmp(node x,node y) { return x.x<y.x; }
int rd()
{
	int f=1,y; char c;
	while ((c=getchar())>'9'||c<'0') if (c=='-') f=-1; y=c-'0';
	while ((c=getchar())<='9'&&c>='0') y=(y<<1)+(y<<3)+c-'0';
	return y*f;
}
int check(int o)
{
	long long maxn=-1;
	int head=1,tail=1;
	map<long long,int> mp;
	priority_queue<int,vector<int>,less<int> >Q;
	down=max(1,d-o); up=d+o; 
	memset(dp,-0x7f,sizeof(dp)); dp[1]=0; Q.push(dp[1]); mp[dp[1]]++;
	for (int i=2;i<=n;i++)
	{
		while (head>=tail&&f[i].x-f[tail].x>up) 
		{
			mp[dp[tail]]--;
			tail++;
		}
		while (head<i-1&&f[i].x-f[head+1].x>=down&&f[i].x-f[head+1].x<=up) 
		{
			head++;
			Q.push(dp[head]);
			mp[dp[head]]++;
		}
		while (!Q.empty()&&!mp[Q.top()]) Q.pop();
		if (Q.empty()) return maxn;
		dp[i]=f[i].c+Q.top();
		maxn=max(dp[i],maxn);
	}
	return maxn;
}
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	n=rd(); d=rd(); k=rd();
	for (int i=1;i<=n;i++)
	{
		f[i].x=rd();
		f[i].c=rd();
		if (f[i].c>0) sum+=f[i].c;
	}
	if (sum<k) { puts("-1"); return 0; }
	f[++n].x=0; f[n].c=0;
	sort(f+1,f+1+n,cmp);
	l=0; r=f[n].x;
//	printf("%d\n",check(84));
	while (l<r)
	{
		int mid=(l+r)>>1;
		if (check(mid)>=k) r=mid;
		else l=mid+1;
	}
	printf("%d",l);
}
