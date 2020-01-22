#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<math.h>
#define re register int
#define fast static int
using namespace std;
typedef long long ll;
ll read()
{
	register ll x=0,f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9')
	{
		if(ch=='-')	f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9')
	{
		x=10*x+ch-'0';
		ch=getchar();
	}
	return x*f;
}
const int Size=300005;
const int INF=0x3f3f3f3f;
bool White(ll x,ll y)
{
	bool f1=(x&1),f2=(y&1);
	return (f1 && f2) || (!f1 && !f2);
}
ll S(ll lx,ll ly,ll rx,ll ry)
{
	return (rx-lx+1)*(ry-ly+1);
}
ll Cal(ll lx,ll ly,ll rx,ll ry)	//计算白色数量 
{
	bool whi1=White(lx,ly);
	bool whi2=White(rx,ly);
	bool whi3=White(lx,ry);
	ll Long=(ry-ly+1)/2+((ry-ly+1)&1);
	ll Short=(ry-ly+1)/2;
	ll Longnum=(rx-lx+1)/2,Shortnum=(rx-lx+1)/2;
	if((rx-lx+1)&1)
	{
		if(whi1 && whi2)
		{
			Longnum++;
		} else {
			Shortnum++;
		}
	}
	return Long*Longnum+Short*Shortnum;
}
struct Rect
{
	ll lx,ly;
	ll rx,ry;
} R1,R2,Common;
ll n,m;
void init()
{
	n=read();
	m=read();
	R1.lx=read(); R1.ly=read(); R1.rx=read(); R1.ry=read();
	R2.lx=read(); R2.ly=read(); R2.rx=read(); R2.ry=read();
}
bool Check(Rect A,Rect B)
{
	if(A.lx>=B.lx)	swap(A,B);
	if(A.ly<=B.ly)
	{
		if(A.rx>=B.lx && A.ry>=B.ly)
		{
			Common.lx=B.lx; Common.ly=B.ly;
			Common.rx=min(A.rx,B.rx); Common.ry=min(A.ry,B.ry);
			return true;
		}
		return false;
	}
	else
	{
		if(A.rx>=B.lx && A.ly<=B.ry)
		{
			Common.lx=B.lx; Common.ly=A.ly;
			Common.rx=min(A.rx,B.rx); Common.ry=min(A.ry,B.ry);
			return true;
		}
		return false;
	}
}
int main()
{
	int t=read();
	while(t--)
	{
		init();
		ll ans=Cal(1,1,m,n);
		ans=ans-Cal(R1.lx,R1.ly,R1.rx,R1.ry)+S(R1.lx,R1.ly,R1.rx,R1.ry);
		ans=ans-Cal(R2.lx,R2.ly,R2.rx,R2.ry);
		if(Check(R1,R2))
		{
			ans=(ans-S(Common.lx,Common.ly,Common.rx,Common.ry)+Cal(Common.lx,Common.ly,Common.rx,Common.ry));
		}
		printf("%I64d %I64d\n",ans,S(1,1,m,n)-ans);
	}
	return 0;
}
