#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
#define oo 2000000000
#define max(a,b)(a>b?a:b)
#define min(a,b)(a<b?a:b)
int n,d,k,x[500005],s[500005],Max,f[500005];
struct DP{
	int s,x;
	bool operator < (const DP &a) const{
		return s<a.s;
	}
};
priority_queue <DP> que;
bool check(int t)
{
	int st=max(d-t,1),en=min(d+t,Max),j=-1;
	while (!que.empty()) que.pop();
	memset(f,0,sizeof(f));
	for (int i=1;i<=n;i++)
	{
		while (x[i]-x[j+1]>=st&&j+1<i)
		{
			DP temp;
			j++;
			temp.x=x[j];
			temp.s=f[j];
			que.push(temp);
		}
		if (!que.empty())
		{
			DP temp=que.top();
			while (!que.empty()&&x[i]-temp.x>en)
			{
				que.pop();
				temp=que.top();
			}
			if (!que.empty())
			{
				f[i]=temp.s+s[i];
				ans=max(ans,f[i]);
			}
		}
	}
	return ans>=k;
}
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d%d%d",&n,&d,&k);
	for (int i=1;i<=n;i++)
	{
		scanf("%d%d",&x[i],&s[i]);
		Max=max(Max,x[i]);
	}
	int lo=-1,hi=1000000005;
	bool OK=false;
	while (lo+1<hi)
	{
		int mid=(lo+hi)/2;
		if (check(mid))
		{
			hi=mid;
			OK=true;
		}
		else
			lo=mid;
	}
	if (OK)
		printf("%d",hi);
	else
		printf("-1");
	return 0;
}
