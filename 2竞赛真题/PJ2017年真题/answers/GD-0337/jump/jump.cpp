# include<cstdio>
# include<cstring>
using namespace std;
const int N = 5e5 + 10;
typedef long long ll;
struct sa
{
	ll dis,val;
}a[N];
ll f[N];
ll k,g,zs;
int n,d;
ll min(ll a,ll b)
{ return a > b ? a : b; }
void dfs(int dep,ll val,ll g)
{
	f[dep] = val;
	if (val > zs) zs = val;
	if (dep >= n)
		return;
	for (int i = dep + 1;i <= n; i++)
	{
		if (g == 0 && a[i].dis - a[dep].dis > d) return;
		if (a[i].dis - a[dep].dis > (g + d)) return;
		if (a[i].dis - a[dep].dis < min(d - g,1)) continue;
		if (val + a[i].val <= f[i]) continue;
		dfs(i,val + a[i].val,g);
	}
}
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d%d%lld",&n,&d,&k);
	for (int i = 1;i <= n; i++)
		scanf("%lld%lld",&a[i].dis,&a[i].val);
	ll l = 0,r = N,ret = 0;
	while (l < r)
	{
		ll mid = (l + r) >> 1;
		zs = -0x3f3f3f3f;
		memset(f,-0x3f,sizeof(f));
		dfs(0,0,mid);
		if (zs >= k) r = mid - 1,ret = mid;
		else l = mid + 1;
	}
	dfs(0,0,ret);
	if (zs >= k) printf("%lld\n",ret);
	else puts("-1");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
