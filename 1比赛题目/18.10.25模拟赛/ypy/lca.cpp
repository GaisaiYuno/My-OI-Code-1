#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define maxlog 32
#define maxn 50005
#define mod 201314
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

inline void qprint(int x){
	if(x==0) return;
	qprint(x/10);
	putchar(x%10+'0');
}
int n,q;
struct edge{
	int from;
	int to;
	int next;
}E[maxn<<1];
int head[maxn];
int sz=0;
void add_edge(int u,int v){
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].next=head[u];
	head[u]=sz;
} 

int log2n;
int deep[maxn];
int anc[maxn][maxlog];
void dfs(int x,int fa){
	deep[x]=deep[fa]+1;
	anc[x][0]=fa;
	for(register int i=1;i<=log2n;i++){
		anc[x][i]=anc[anc[x][i-1]][i-1];
	}
	for(register int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(y!=fa){
			dfs(y,x);
		} 
	}
}

int lca(int x,int y){
	if(deep[x]<deep[y]) swap(x,y);
	for(register int i=log2n;i>=0;i--){
		if(deep[anc[x][i]]>=deep[y]){
			x=anc[x][i];
		} 
	}
	if(x==y) return x;
	for(register int i=log2n;i>=0;i--){
		if(anc[x][i]!=anc[y][i]){
			x=anc[x][i];
			y=anc[y][i];
		}
	}
	return anc[x][0];
}

long long solve(int l,int r,int z){
	long long ans=0; 
	for(register int i=l;i<=r;i++){
		ans=ans+deep[lca(i,z)];
		ans%=mod;
	}
	return ans;
}

int main(){
	freopen("lca.in","r",stdin);
	freopen("lca.out","w",stdout); 
	int x,l,r,z,ans;
	n=qread();
	q=qread();
	log2n=log2(n);
	for(register int i=2;i<=n;i++){
		x=qread();
		x++;
		add_edge(i,x);
		add_edge(x,i);
	}
	dfs(1,0);
	for(register int i=1;i<=q;i++){
		l=qread();
		r=qread();
		z=qread();
		l++;
		r++;
		z++;
		ans=solve(l,r,z);
		if(ans>0)qprint(ans);
		else putchar('0');
		putchar('\n');
	}
}
//For my love Selina
