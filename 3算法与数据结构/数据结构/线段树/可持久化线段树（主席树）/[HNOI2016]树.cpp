//大毒瘤！！！！！！！ 
// https://www.luogu.org/problem/P3248
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 100000
#define maxlogn 20 
using namespace std;
typedef long long ll;
int n,m,q;
struct persist_segment_tree{
#define lson(x) tree[x].ls
#define rson(x) tree[x].rs
	struct node{
		int ls;
		int rs;
		int cnt;
	}tree[maxn*maxlogn+5];
	int root[maxn+5];
	int ptr;
	void push_up(int x){
		tree[x].cnt=tree[lson(x)].cnt+tree[rson(x)].cnt;
	}
	void update(int &x,int last,int upos,int l,int r){
		x=++ptr;
		tree[x]=tree[last];
		if(l==r){
			tree[x].cnt++;
			return;
		}
		int mid=(l+r)>>1;
		if(upos<=mid) update(tree[x].ls,tree[last].ls,upos,l,mid);
		else update(tree[x].rs,tree[last].rs,upos,mid+1,r);
		push_up(x); 
	}
	int query(int xl,int xr,int k,int l,int r){
		if(l==r) return l;
		int mid=(l+r)>>1;
		int cnt=tree[lson(xr)].cnt-tree[lson(xl)].cnt;
		if(k<=cnt) return query(tree[xl].ls,tree[xr].ls,k,l,mid);
		else return query(tree[xl].rs,tree[xr].rs,k-cnt,mid+1,r);
	}

#undef lson
#undef rson
}CT;

namespace template_tree{
	struct edge{
		int from;
		int to;
		int next;	
	}E[maxn*2+5];
	int esz=1;
	int head[maxn+5];
	void add_edge(int u,int v){
		esz++;
		E[esz].from=u;
		E[esz].to=v;
		E[esz].next=head[u];
		head[u]=esz;
		esz++;
		E[esz].from=v;
		E[esz].to=u;
		E[esz].next=head[v];
		head[v]=esz;
	}
	
	int log2n;
	int anc[maxn+5][maxlogn+5];
	int deep[maxn+5];
	int tim;
	int dfnl[maxn+5],dfnr[maxn+5];
	int hash_dfn[maxn+5]; 
	void dfs(int x,int fa){
		deep[x]=deep[fa]+1;
		dfnl[x]=++tim;
		hash_dfn[tim]=x;
		anc[x][0]=fa;
		for(int i=1;i<=log2n;i++) anc[x][i]=anc[anc[x][i-1]][i-1];
		for(int i=head[x];i;i=E[i].next){
			int y=E[i].to;
			if(y!=fa){
				dfs(y,x);
			}
		}
		dfnr[x]=tim;
	} 
	int lca(int x,int y){
		if(deep[x]<deep[y]) swap(x,y);
		for(int i=log2n;i>=0;i--){
			if(deep[anc[x][i]]>=deep[y]){
				x=anc[x][i];
			}
		}
		if(x==y) return x;
		for(int i=log2n;i>=0;i--){
			if(anc[x][i]!=anc[y][i]){
				x=anc[x][i];
				y=anc[y][i];
			}
		}
		return anc[x][0];
	}
	int get_dist(int u,int v){
		return deep[u]+deep[v]-2*deep[lca(u,v)];
	}
	int get_son_kth(int x,int k){//查询子树中第k大 
		return CT.query(CT.root[dfnl[x]-1],CT.root[dfnr[x]],k,1,n); 
	}
	void build(){
		log2n=log2(n)+1;
		dfs(1,0);
		for(int i=1;i<=n;i++) CT.update(CT.root[i],CT.root[i-1],hash_dfn[i],1,n);
	}
} 

namespace real_tree{
	struct edge{
		int from;
		int to;
		int len;
		int next;	
	}E[maxn*2+5];
	int esz=1;
	int head[maxn+5];
	void add_edge(int u,int v,int w){
		esz++;
		E[esz].from=u;
		E[esz].to=v;
		E[esz].next=head[u];
		E[esz].len=w;
		head[u]=esz;
		esz++;
		E[esz].from=v;
		E[esz].to=u;
		E[esz].next=head[v];
		E[esz].len=w;
		head[v]=esz;
	}
	
	int log2n;
	int deep[maxn+5];
	ll dist[maxn+5];
	int anc[maxn+5][maxlogn+5];
	ll dsum[maxn+5][maxlogn+5];//x向上走2^i辈祖先的距离 
	void dfs(int x,int fa){
		deep[x]=deep[fa]+1;
		anc[x][0]=fa;
		for(int i=1;i<=log2n;i++){
			anc[x][i]=anc[anc[x][i-1]][i-1];
			dsum[x][i]=dsum[x][i-1]+dsum[anc[x][i-1]][i-1];
		}
		for(int i=head[x];i;i=E[i].next){
			int y=E[i].to;
			if(y!=fa){
				dist[y]=dist[x]+E[i].len;
				dsum[y][0]=E[i].len;
				dfs(y,x);
			}
		}
	} 
	
	struct oper{
		int x;
		ll to;
	}op[maxn+5];
	ll idl[maxn+5],idr[maxn+5];//这个大节点包含小节点的编号范围 
	int from[maxn+5];//大节点来自模板树上的节点编号 
	ll link[maxn+5];//记录一下大节点x接到了哪里 
	int sz;
	int get_root(ll x){//找到包含小节点的大节点
	 	//二分出包含小节点的区间 
		int l=1,r=sz;
		int mid;
		int ans=0;
		while(l<=r){
			mid=(l+r)>>1;
			if(idr[mid]>=x){
				ans=mid;
				r=mid-1;
			}else l=mid+1;
		}
		return ans;
	} 
	int get_tpid(ll x){//找到小节点x在模板树里对应的节点
		//实际上就是找模板树子树from[rt]里第x-idl[rt]+1小的节点，用主席树做 
		 int rt=get_root(x);
		 return template_tree::get_son_kth(from[rt],x-idl[rt]+1); 
	}
	void build(){
		sz=1;
		ll cnt=n;
		from[1]=1;
		idl[1]=1;
		idr[1]=n; 
		for(int i=1;i<=m;i++){
			sz++;
			int rt=get_root(op[i].to);
//			int len=template_tree::get_dist(from[rt],get_tpid(op[i].to));
			int len=template_tree::get_dist(from[rt],get_tpid(op[i].to))+1;
			add_edge(sz,rt,len);
//			printf("db: %d %d %d\n",sz,rt,len);
			link[sz]=op[i].to;
			from[sz]=op[i].x;
			idl[sz]=cnt+1;
			idr[sz]=cnt+template_tree::dfnr[op[i].x]-template_tree::dfnl[op[i].x]+1;
			cnt=idr[sz];
		}
		log2n=log2(sz)+1;
		dfs(1,0);
	}
	ll get_dist(ll x,ll y){
		int rtx=get_root(x);
		int rty=get_root(y);
		ll ans=0;
		if(rtx==rty){
			return template_tree::get_dist(get_tpid(x),get_tpid(y));
		}else{
			if(deep[rtx]<deep[rty]){
				swap(x,y);
				swap(rtx,rty);
			}
			ans+=template_tree::get_dist(get_tpid(x),from[rtx]);//x到rtx的距离 
			x=rtx;
			for(int i=log2n;i>=0;i--){
				if(deep[anc[x][i]]>deep[rty]){//差一步不要跳 
					ans+=dsum[x][i];
					x=anc[x][i]; 
				}
			}
			if(anc[x][0]==rty) return ans+1+template_tree::get_dist(get_tpid(link[x]),get_tpid(y));
			//如果是一条链，需要特判,这里不能在大树上跳一步到rty,因为经过rty不是最短路径，
			//如果x到rty有一条边，即x对应的子树的根是接在rty中的某个小节点的子树上的 
			//应从x对应子树的根，跳长度为1到link[x],再从link[x]到y
			
			ans+=template_tree::get_dist(get_tpid(y),from[rty]);//y到rty的距离 
			y=rty;
			if(deep[x]>deep[rty]){ 
				ans+=dsum[x][0];
				x=anc[x][0];
			}//如果不是一条链，且深度不等，才跳到同一深度 
			for(int i=log2n;i>=0;i--){
				if(anc[x][i]!=anc[y][i]){
					ans+=dsum[x][i];
					ans+=dsum[y][i];
					x=anc[x][i];
					y=anc[y][i];
				}
			} 
			//最后一步
			x=link[x];
			y=link[y];
			ans+=2; 
			ans+=template_tree::get_dist(get_tpid(x),get_tpid(y)); 
			return ans;
		} 
	}
}


int main(){
	int u,v;
	ll xx,yy;
	scanf("%d %d %d",&n,&m,&q);
	for(int i=1;i<n;i++){
		scanf("%d %d",&u,&v);
		template_tree::add_edge(u,v);
	}
	template_tree::build();
	for(int i=1;i<=m;i++){
		scanf("%d %lld",&real_tree::op[i].x,&real_tree::op[i].to);
	}
	real_tree::build();
	for(int i=1;i<=q;i++){
		scanf("%lld %lld",&xx,&yy);
		printf("%lld\n",real_tree::get_dist(xx,yy));
	}
}

