#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#define zhh 500005
#define ll long long
#define fu(a,b,c) for(ll a=b;a<=c;a++)
#define fd(a,b,c) for(ll a=b;a>=c;a--)
using namespace std;
inline ll read(){
	ll x=0,f=1;
	char edge=getchar();
	while(edge>'9'||edge<'0'){
		if(edge=='-') f=-1;
		edge=getchar();
	}
	while(edge>='0'&&edge<='9'){
		x=x*10+edge-'0';
		edge=getchar();
	}
	return x*f;
}
ll n,m,x,y,tot,z,ans,an1;
ll head[zhh],nxt[zhh<<1],v[zhh<<1],edge[zhh<<1];
ll dis[zhh],e[zhh],lu[zhh],cnt[zhh];
bool vis[zhh];
queue<ll>q;
void ad(ll x,ll y,ll z){
    v[++tot]=y;edge[tot]=z;nxt[tot]=head[x];head[x]=tot;
}
void spfa(){
    memset(dis,0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
	vis[1]=1;
	dis[1]=0;
    while(!q.empty()) q.pop();
	q.push(1);
	while(q.size()){
		ll nw=q.front();
		q.pop();
		vis[nw]=0;
		for(ll i=head[nw];i;i=nxt[i]){
			if(dis[v[i]]>dis[nw]+edge[i]){
				dis[v[i]]=dis[nw]+edge[i];
				lu[v[i]]=nw;
				e[v[i]]=i;
				if(!vis[v[i]]){
					vis[v[i]]=1;
					q.push(v[i]);
				}
			}
		}
	}
}
void spfa2(){
    memset(dis,0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
	dis[1]=0;
	vis[1]=1;
    while(!q.empty()) q.pop();
	q.push(1);
    while(q.size()){
        ll nw=q.front();
		q.pop();
        vis[nw]=0;
        for(ll i=head[nw];i;i=nxt[i]){
            if(dis[v[i]]>dis[nw]+edge[i]){
                dis[v[i]]=dis[nw]+edge[i];
                if(!vis[v[i]]){
                    vis[v[i]]=1;
                    q.push(v[i]);
                }
            }
        }
    }
}
void init(){
	tot=-1;
	memset(head,-1,sizeof(head));
	memset(nxt,-1,sizeof(nxt));
}
int main(){
	freopen("roadblock.in","r",stdin);
	freopen("roadblock.out","w",stdout);
	n=read(),m=read();
	init();
    fu(i,1,m){
        x=read(),y=read(),z=read();
        ad(x,y,z);
		ad(y,x,z);
    }
    spfa();
	an1=dis[n];
    ll xx=n;
    while(xx!=1){
        edge[e[xx]]*=2,edge[e[xx]^1]*=2;
        spfa2();
        ans=max(ans,dis[n]);
        edge[e[xx]]/=2,edge[e[xx]^1]/=2;
        xx=lu[xx];
    }
    cout<<ans-an1;
    return 0;
}
