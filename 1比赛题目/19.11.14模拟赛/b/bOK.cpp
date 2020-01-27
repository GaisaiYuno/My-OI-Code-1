#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>
#include<utility>
#define maxn 200000
using namespace std;
inline void qread(int &x){
	x=0;
	int sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	x=x*sign;
}
inline void qprint(int x){
	if(x<0){
		putchar('-');
		qprint(-x);
	}else if(x==0){
		putchar('0');
		return;
	}else{
		if(x>=10) qprint(x/10);
		putchar('0'+x%10);
	}
}
int n,m;
int a[maxn+5];

struct edge{
	int from;
	int to;
	int next;
}E[maxn*2+5];
int sz=1;
int head[maxn+5];
void add_edge(int u,int v){
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].next=head[u];
	head[u]=sz;
}
namespace diameter{
	int deep[maxn+5];
	int maxd=0;
	int id=0;
	void dfs(int x,int fa){
		deep[x]=deep[fa]+1;
		if(deep[x]>maxd){
			maxd=deep[x];
			id=x;
		}
		for(int i=head[x];i;i=E[i].next){
			int y=E[i].to;
			if(y!=fa){
				dfs(y,x);
			}
		}
	}
	int find_point(int s){
		for(int i=1;i<=n;i++) deep[i]=0;
		maxd=id=0;
		dfs(s,0);
		return id;
	}
	pair<int,int> get_diameter(){
		int s=find_point(1);
		int t=find_point(s);
		return make_pair(s,t);
	}
}
namespace long_chain_decomposition{
	int deep[maxn+5];
	int maxd[maxn+5];
	int son[maxn+5]; 
	int fa[maxn+5];
	void dfs1(int x,int f){
		deep[x]=deep[f]+1;
		fa[x]=f;
		maxd[x]=1;
		for(int i=head[x];i;i=E[i].next){
			int y=E[i].to;
			if(y!=f){
				dfs1(y,x);
				maxd[x]=max(maxd[x],maxd[y]+1);
				if(maxd[y]>maxd[son[x]]) son[x]=y;
			}
		}
	}
	
	int ans=0;
	stack<int>s;
	int cnt[maxn+5];
	void add(int x){
		s.push(x);
		cnt[a[x]]++;
		if(cnt[a[x]]==1) ans++;
	} 
	void del(){
		int x=s.top();
		s.pop();
		cnt[a[x]]--;
		if(cnt[a[x]]==0) ans--;
	}
	
	int res[maxn+5];
	void dfs2(int x){
		if(son[x]==0){
			res[x]=max(res[x],ans);
			return;
		}
		int ymaxd=0;
		//在所有轻儿子中找深度最大的
		for(int i=head[x];i;i=E[i].next){
			int y=E[i].to;
			if(y!=fa[x]&&y!=son[x]){
				ymaxd=max(ymaxd,maxd[y]);
			}
		}
		//去掉距离x小于这个深度的栈里的点 
		while(!s.empty()&&deep[x]-deep[s.top()]<=ymaxd) del();//距离为deep[x]-deep[s[top]]
		add(x);//把x加回去 
		dfs2(son[x]);//递归处理重儿子 
		for(int i=head[x];i;i=E[i].next){
			int y=E[i].to;
			if(y!=fa[x]&&y!=son[x]){
				while(!s.empty()&&deep[x]-deep[s.top()]<=maxd[son[x]]) del();//如果距离比到重儿子距离小，就删除 
				add(x);
				dfs2(y);
			}
		}
		while(!s.empty()&&deep[x]-deep[s.top()]<=maxd[son[x]]) del();
		res[x]=max(res[x],ans);
	}
	void solve(int root){
		for(int i=1;i<=n;i++) deep[i]=maxd[i]=son[i]=fa[i]=0;
		dfs1(root,0);
		ans=0;
		for(int i=1;i<=m;i++) cnt[i]=0;
		while(!s.empty()) s.pop();
		dfs2(root);
	}
}


int main(){
	int u,v;
	qread(n);
	qread(m);
	for(int i=1;i<n;i++){
		qread(u);
		qread(v);
		add_edge(u,v);
		add_edge(v,u);
	}
	for(int i=1;i<=n;i++) qread(a[i]);
	pair<int,int>tmp=diameter::get_diameter();
	long_chain_decomposition::solve(tmp.first);
	long_chain_decomposition::solve(tmp.second);
	for(int i=1;i<=n;i++){
		qprint(long_chain_decomposition::res[i]);
		putchar('\n');
	}
}



/*
5 4
1 2
2 3
3 4
3 5
1 2 1 2 4

7 1
1 2
2 3
3 4
4 5
5 6
6 7
1 1 1 1 1 1 1
*/
