#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define ll long long
#define fu(a,b,c) for(ll a=b;a<=c;a++)
#define fd(a,b,c) for(ll a=b;a>=c;a--)
#define zhh 300005
#define inf 0x7fffffff
using namespace std;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,k,ans,a1,maa,mii=inf;
int a[zhh];
void dfs(int ha,int l1,int l2){
	if(ha>n) return;
	if(abs(a[ha]-l2)>k||abs(a[ha]-l1)>k) return;
	a1++;
	dfs(ha+1,min(l1,a[ha+1]),max(l2,a[ha+1]));
}
int main(){
	freopen("bed.in","r",stdin);
	freopen("bed.out","w",stdout);
	n=read(),k=read();
	fu(i,1,n){
		a[i]=read();
		maa=max(maa,a[i]);
		mii=min(mii,a[i]);
	}
	if(maa-mii<=k){
		cout<<n;
		return 0;
	}
	ans=-inf;
	fu(i,1,n-1){
		a1=0;
		dfs(i,a[i],a[i]);
		ans=max(ans,a1);
	}
	cout<<ans;
	return 0;
}
