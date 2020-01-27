#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 100005
#define INF 0x7f7f7f7f
using namespace std;
inline int qread(){
	int x=0,sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	} 
	return x*sign;
}

char out[30];
inline void qprint(long long x){
	if(x==0){
		putchar('0');
	}else{
		int ptr=0;
		while(x>0){
			out[++ptr]=x%10+'0';
			x/=10;
		}
		for(int i=ptr;i>=1;i--){
			putchar(out[i]);
		}
	}
	putchar('\n');
}
int n;
long long a[maxn];
struct edge{
	int from;
	int to;
	int next;
}E[maxn<<1];
int sz=0;
int head[maxn];
void add_edge(int u,int v){
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].next=head[u];
	head[u]=sz;
}

int cnt=0;
long long ans=0;
int route[maxn];
int dfs(int x,int fin,int fa,long long minv){
	if(x==fin){
		return 1;
	}
	bool flag=false;
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		long long v=min(minv,a[x]);
		if(y!=fa){
			if(dfs(y,fin,x,v)){
				flag=true;
				ans=max(ans,a[y]-v);
				route[++cnt]=y;
			}
		}
	}
	if(flag) return 1;
	else return 0;
}
int q;
int main(){
	freopen("city.in","r",stdin);
	freopen("city.out","w",stdout);
	n=qread();
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int u,v,w;
	for(int i=1;i<=n-1;i++){
		v=qread();
		u=qread();
		add_edge(u,v);
		add_edge(v,u);
	}
	q=qread();
	for(int i=1;i<=q;i++){
		u=qread();
		v=qread();
		w=qread();
		cnt=0;
		memset(route,0,sizeof(route));
		ans=0;
		dfs(u,v,0,INF);
		route[++cnt]=u; 
		for(int i=1;i<=cnt;i++){
			a[route[i]]+=w;
		}
		qprint(ans);
	}
}
