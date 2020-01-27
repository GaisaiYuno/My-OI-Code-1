#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int N=500100,oo=2e9;
inline int read(){
	int x=0,f=0,c=getchar();
	for(;c>'9'||c<'0';f=c=='-',c=getchar());
	for(;c>='0'&&c<='9';c=getchar())
	x=(x<<1)+(x<<3)+c-'0';return f?-x:x;
}
inline void write(ll x){
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
struct cqz{int i,x,y;}p[N];
inline bool operator<(cqz i,cqz j){
	if(i.x!=j.x)return i.x<j.x;
	if(i.i!=j.i)return i.i<j.i;
	return i.y<j.y;
}
int n,L,h[N],ne[N],to[N],ans,f[N],m,b[N];
int nxt[N];
void addl(int x,int y){
	ne[++L]=h[x];h[x]=L;to[L]=y;
	ne[++L]=h[y];h[y]=L;to[L]=x;
}
void dfs(int x,int fa){
	if(fa){
	if(p[fa].x<p[x].x){
		p[x].y=p[x].x;
		p[x].i=p[fa].i;
		p[x].x=p[fa].x;
		p[x].y=min(p[x].y,p[fa].y);
	}else p[x].y=min(p[x].y,p[fa].x);}
	for(int k=h[x];k;k=ne[k])
	if(to[k]!=fa)dfs(to[k],x);
}
int get(int x){return  nxt[x]==x?x:nxt[x]=get(nxt[x]);}
void solve(int L,int R){
	int tp,i,sm=0,now=p[L].x;
	tp=get(f[L-1]+1);
	for(i=L;i<=R;i++){
		if(b[tp]>now)now=min(b[tp],p[i].y);
		if(b[tp]<=now){
			sm++;tp=get(tp+1);
		}
		if(sm>R-L+1)return;
		if(tp==m+1){
			ans=min(ans,now-p[i].x);
			return;
		}
	}
}
int main(){
	freopen("oceanus.in","r",stdin);
	freopen("oceanus.out","w",stdout);
	int i,j,k;
	n=read();
	for(i=1;i<=n;i++){
		p[i].x=read();
		p[i].y=oo;
		p[i].i=i;
	}for(i=1;i<n;i++)addl(read(),read());
	dfs(1,0);p[1].y=oo;
	sort(p+1,p+n+1);
	m=read();
	for(i=1;i<=m;i++)
		b[i]=read(),nxt[i]=i;
	nxt[m+1]=m+1;
	sort(b+1,b+m+1);
	if(m>n)goto fuck;
	b[0]=b[m+1]=oo;
	for(i=1;i<=n;i++){
		f[i]=f[i-1];
		if(p[i].x>=b[f[i]+1])f[i]++;
	}
	if(f[n]==m)goto heiheihei;
	ans=oo;k=m;
	for(i=n;i;){
		for(j=i;p[j].i==p[i].i;j--);
		solve(j+1,i);
		for(;i>j;i--){
			while(k&&b[k]>p[i].x)k--;
			if(p[i].x>=b[k])nxt[k]=k+1,k--;
		}
	}
	if(ans==oo)goto fuck;
	else printf("%d\n",ans);
	return 0;fuck:puts("-1");
	return 0;heiheihei:puts("0");
}
