#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#define zhh 5000005
#define ll long long
#define fu(a,b,c) for(ll a=b;a<=c;a++)
#define fd(a,b,c) for(ll a=b;a>=c;a--)
using namespace std;
const ll inf=0x7fffffffffffffff;
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
struct node{
	int to,nt;
	ll w;
}ed[zhh];
//struct s_t{
//	ll l,r;
//}tr[zhh*4];
int head[zhh];
int tot,ma,n,q,s;
bool vis[zhh];
ll dis[zhh];
void ad(int u,int v,ll w){
	ed[++tot].to=v;ed[tot].w=w;ed[tot].nt=head[u];head[u]=tot;
}
void build(int c,int l,int r,int fl,int t){
	if(t==2) ma=max(ma,c+fl);
	if(l==r){
		if(t==2) ad(c+fl,l,0);
		else ad(l,c+fl,0);
		return;
	}
	if(t==2){
		ad(c+fl,c*2+fl,0);
		ad(c+fl,c*2+1+fl,0);
	}
	else{
		ad(c*2+fl,c+fl,0);
		ad(c*2+1+fl,c+fl,0);
	}
	int md=l+r>>1;
	build(c*2,l,md,fl,t);
	build(c*2+1,md+1,r,fl,t);
}
void ad1(int c,int a,int b,ll w,int l,int r,int fl,int u,int t){
	if(a<=l&&r<=b){
		if(t==2){
			ad(u,c+fl,w);
		}
		else{
			ad(c+fl,u,w);
		}
	}
	else{
		int md=l+r>>1;
		if(a<=md){
			ad1(c*2,a,b,w,l,md,fl,u,t);
		}
		if(b>md){
			ad1(c*2+1,a,b,w,md+1,r,fl,u,t);
		}
	}
}
struct xgd{
	int s;
	ll va;
	xgd(ll ss,ll d){
		s=ss,va=d;
	}
	bool operator <(const xgd &x)const{
		return va>x.va;
	}
};
priority_queue<xgd>mq;
void dij(int s){
	fu(i,0,5000000) dis[i]=inf;
	dis[s]=0;
	mq.push(xgd(s,0));
	while(!mq.empty()){
		xgd nw=mq.top();mq.pop();
		int x=nw.s;
		if(vis[x]) continue;
		vis[x]=1;
		for(int i=head[x];i;i=ed[i].nt){
			int y=ed[i].to;
			ll w=ed[i].w;
            if(dis[y]>nw.va+w){
				mq.push(xgd(y,nw.va+w));
				dis[y]=nw.va+w;
			}
		}
	}
}
int main() {
//	freopen("legacy.in","r",stdin);
//	freopen("legacy.out","w",stdout);
	n=read(),q=read(),s=read();
	build(1,1,n,n+1,2);
	build(1,1,n,ma+1,3);
	fu(i,1,q){
		ll t=read();
		if(t==1){
			ll u=read(),v=read(),w=read();
			ad(u,v,w);
		}
		else{
			ll u=read(),l=read(),r=read(),w=read();
			if(t==2){
				ad1(1,l,r,w,1,n,n+1,u,2);
			}	
			else{
				ad1(1,l,r,w,1,n,ma+1,u,3);
			}
		}
	}
	dij(s);
	fu(i,1,n){
		if(dis[i]==inf){
			cout<<"-1"<<" ";
		}
		else cout<<dis[i]<<" ";
	}
	return 0;
}
