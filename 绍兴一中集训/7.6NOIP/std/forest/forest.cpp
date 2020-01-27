#include<cstdio>
#include<set>
using namespace std;
const int N=100100;
typedef long long ll;
int i,j,k,n,m,q,ch,o,x,y;
int num[N],f[N];
ll t[N],val[N],dev[N],add[N];
multiset <ll> Ans,Son[N];
set <ll>::iterator it;
void R(int &x)
{
	x=0;ch=getchar();
	while (ch<'0' || '9'<ch) ch=getchar();
	while ('0'<=ch && ch<='9') x=x*10+ch-'0',ch=getchar();
}
void R(ll &x)
{
	x=0;ch=getchar();
	while (ch<'0' || '9'<ch) ch=getchar();
	while ('0'<=ch && ch<='9') x=x*10+ch-'0',ch=getchar();
}
void W(ll x)
{
	if (x>=10) W(x/10);
	putchar(x%10+'0');
}
void rev(int x)
{
	if (Son[x].empty()) return;
	it=Son[x].begin();
	Ans.insert(*it+add[x]);
	it=Son[x].end();it--;
	Ans.insert(*it+add[x]);
}
void del(int x)
{
	if (Son[x].empty()) return;
	it=Son[x].begin();
	Ans.erase(Ans.find(*it+add[x]));
	it=Son[x].end();it--;
	Ans.erase(Ans.find(*it+add[x]));
}
void Rev(int x)
{
	Son[f[x]].insert(val[x]+dev[x]);
}
void Del(int x)
{
	Son[f[x]].erase(Son[f[x]].find(val[x]+dev[x]));
}
int main()
{
	freopen("forest.in","r",stdin);
	freopen("forest.out","w",stdout); 
	R(n);R(q);
	for (i=1;i<=n;i++) R(t[i]);
	for (i=1;i<=n;i++)
	{
		R(f[i]);
		num[f[i]]++;
	}
	for (i=1;i<=n;i++)
	{
		add[i]=t[i]/(num[i]+2);
		val[i]=t[i]-(num[i]+1)*add[i];
		dev[f[i]]+=add[i];
	}
	for (i=1;i<=n;i++) Rev(i);
	for (i=1;i<=n;i++) rev(i);
	for (i=1;i<=q;i++)
	{
		R(o);
		if (o==1)
		{
			R(x);R(y);
			if (f[x]==y) continue;
			del(f[x]);del(f[f[x]]);del(f[f[f[x]]]);
			Del(x);Del(f[x]);Del(f[f[x]]);
			dev[f[x]]-=add[x];num[f[x]]--;
			dev[f[f[x]]]-=add[f[x]];
			add[f[x]]=t[f[x]]/(num[f[x]]+2);
			val[f[x]]=t[f[x]]-(num[f[x]]+1)*add[f[x]];
			dev[f[f[x]]]+=add[f[x]];
			Rev(f[x]);Rev(f[f[x]]);
			rev(f[x]);rev(f[f[x]]);rev(f[f[f[x]]]);
			f[x]=y;
			del(f[x]);del(f[f[x]]);del(f[f[f[x]]]);
			Del(f[x]);Del(f[f[x]]);
			dev[f[x]]+=add[x];num[f[x]]++;
			dev[f[f[x]]]-=add[f[x]];
			add[f[x]]=t[f[x]]/(num[f[x]]+2);
			val[f[x]]=t[f[x]]-(num[f[x]]+1)*add[f[x]];
			dev[f[f[x]]]+=add[f[x]];
			Rev(x);Rev(f[x]);Rev(f[f[x]]);
			rev(f[x]);rev(f[f[x]]);rev(f[f[f[x]]]);
			continue;
		}
		if (o==2)
		{
			R(x);
			W(dev[x]+val[x]+add[f[x]]);puts("");
			continue;
		}
		it=Ans.begin();
		W(*it);putchar(' ');
		it=Ans.end();it--;
		W(*it);puts("");
	}
	return 0;
}
