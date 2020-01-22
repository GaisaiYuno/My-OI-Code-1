#include<cstdio>
#include<queue>
using namespace std;
typedef long long ll;
struct Node
{ll x,s;}node[500001];
deque<Node> que;
ll maxn[500001];
ll n,k,d;
ll tot;
char ch;
bool flag;
ll min(ll x,ll y)
{return x<y? x:y;}
ll abs(ll x)
{return x<0? -x:x;}
void read(ll &x)
{
	for (flag&=0,ch=getchar();ch<'0'||ch>'9';ch=getchar())
		if (ch=='-')
			flag|=1;
	for (x=0;ch<='9'&&ch>='0';ch=getchar())
		x=(x<<3)+(x<<1)+(ch^48);
	x=flag? -x:x;
}
bool check1(ll x)
{
	while (!que.empty())
		que.pop_back();
	for (int i=1;i<=n;i++)
	{
		while (!que.empty()&&node[i].x-que.front().x>d+d-x)
			que.pop_front();
		if ((i==1||!que.empty())&&node[i].x-que.front().x>=x)
			maxn[i]=node[i].s+(que.empty()? 0:que.front().s);
		else
			continue;
		if (maxn[i]>=k)
			return true;
		while (!que.empty()&&que.back().s<=maxn[i])
			que.pop_back();
		que.push_back((Node){node[i].x,maxn[i]});
	}
	return false;
}
bool check2(ll x)
{
	while (!que.empty())
		que.pop_back();
	for (int i=1;i<=n;i++)
	{
		while (!que.empty()&&node[i].x-que.front().x>x)
			que.pop_front();
		if ((i==1||!que.empty())&&node[i].x-que.front().x>=d+d-x)
			maxn[i]=node[i].s+(que.empty()? 0:que.front().s);
		else
			continue;
		if (maxn[i]>=k)
			return true;
		while (!que.empty()&&que.back().s<=maxn[i])
			que.pop_back();
		que.push_back((Node){node[i].x,maxn[i]});
	}
	return false;
}
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	read(n);
	read(d);
	read(k);
	for (int i=1;i<=n;i++)
	{
		read(node[i].x);
		tot+=node[i].x;
		read(node[i].s);
	}
	return check1(2);
	ll l=1,r=d-1,mid;
	while (l<r)
	{
		mid=l+r+1>>1;
		if (check1(mid))
			l=mid;
		else
			r=mid-1;
	}
	ll tmp=l;
	if (!check1(tmp))
		tmp=-1;
	l=d;
	r=tot;
	while (l<r)
	{
		mid=l+r>>1;
		if (check2(mid))
			r=mid;
		else
			l=mid+1;
	}
	if (!check2(l))
		l=-1;
	if (tmp==-1&&l==-1)
		puts("-1");
	else
		printf("%lld\n",min(abs(tmp-d),abs(l-d)));
	fclose(stdin);
	fclose(stdout);
	return 0;
}
