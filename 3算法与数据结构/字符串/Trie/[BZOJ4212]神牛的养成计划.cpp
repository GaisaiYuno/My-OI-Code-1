#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
struct Trie {
	vector<int>E[maxl+5];
	bool vis[maxl+5];
	char ch[maxl+5][maxc+1];
	int sz=0;
	inline void add_edge(int u,int v) {
		E[u].push_back(v);
		E[v].push_back(u);
	}
	void insert(char *s,int type) {
		int n=strlen(s+1);
		int x=0;
		if(type==1) {
			for(int i=1; i<=n; i++) {
				char c=s[i]-'a';
				if(!ch[x][c]) {
					ch[x][c]=++sz;
					add_edge(x,sz);
				}
				x=ch[x][c];
				vis[x]=1;
			}
		}else{
			for(int i=n; i>=1; i--) {
				char c=s[i]-'a';
				if(!ch[x][c]) {
					ch[x][c]=++sz;
					add_edge(x,sz);
				}
				x=ch[x][c];
				vis[x]=1;
			}
		}

	}
} Tpre,Tsuf;

struct persist_segment_tree{
#define lson(x) (tree[x].ls)
#define rson(x) (tree[x].rs) 
	struct node{
		int ls;
		int rs;
		int cnt;
	}tree[maxl*maxlogn+5];
	int root[maxl+5];
	int ptr;
	inline void push_up(int x){
		tree[x].cnt=tree[lson(x)].cnt+tree[rson(x)].cnt;
	} 
	void insert(int &x,int last,int val,int l,int r){
		x=++ptr;
		tree[x]=tree[last];
		if(l==r){
			tree[x].cnt++;
			return;
		}
		int mid=(l+r)>>1;
		if(val<=mid) insert(lson(x),lson(last),val,l,mid);
		else insert(rson(x),rson(last),val,mid+1,r);
		push_up(x);
	}
	int query(int x,int L,int R,int l,int r){
		if(L<=l&&R>=r) return tree[x].cnt;
		int mid=(l+r)>>1;
		int ans=0;
		if(L<=mid) ans+=query(lson(x),L,R,l,mid);
		if(R>mid) ans+=query(rson(x),L,R,mid+1,r);
		return ans;
	}
}Tval;

struct dfn_tree{
	vector<int>* E;
	int tim;
	int dfnl[maxl+5],dfnr[maxl+5];
	void ini(vector<int>* x){
		E=x;
	}
	void dfs(int x,int fa){
		dfnl[x]=++tim;
		for(int i=0;i<E[x].size();i++){
			int y=E[x][i];
			if(y!=fa){
				dfs(y,x);
			}
		} 
		dfnr[x]=tim;
	}
}
int main() {

}

