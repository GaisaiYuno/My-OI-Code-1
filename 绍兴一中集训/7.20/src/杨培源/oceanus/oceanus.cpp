#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set> 
#define maxn 200000
using namespace std;
int n,m;
int a[maxn+5];
int b[maxn+5];
struct edge{
	int from;
	int to;
	int next;
}E[maxn*2+5];
int sz=0;
int head[maxn+5]; 
void add_edge(int u,int v){
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].next=head[u];
	head[u]=sz;
}

struct node{
	int h;
	int id;
	node(){
		
	}
	node(int _h,int _id){
		h=_h;
		id=_id;
	}
	friend bool operator < (node p,node q){
		if(p.h==q.h) return p.id<q.id;
		return p.h<q.h;
	}
}p[maxn+5];

namespace flower{
	int ans[maxn+5];
	void solve(){
		int cnt0=0;
		for(int i=1;i<=m;i++){
			int tp=lower_bound(p+1,p+1+n,node(b[i],0))-p;
			int pos=p[tp].id;
			if(tp==n+1){
				pos=n;
				cnt0++;
				if(cnt0>1||ans[n]){
					printf("-1\n");
					return ;
				}
			}
			if(ans[pos]){
				printf("-1\n");
				return;
			}
			ans[pos]=b[i];
		}
		
		int addp=0;
		int addv=0;
		int cnt=0;
		set<int>vis;
		for(int i=1;i<=n;i++){
			if(i==1){
				if(a[i]<ans[i]){
					addp=i;
					addv=max(addv,ans[i]);
					vis.insert(addp);
				}
			}else{
				if(a[i]<ans[i]){
					addp=i;
					addv=max(addv,ans[i]);
					vis.insert(addp);
				}
				if(a[1]<ans[i]){
					addp=1;
					addv=max(addv,ans[i]);
					vis.insert(addp);
				}
			}
		}
		if(vis.size()>1) printf("-1\n");
		else printf("%d\n",addv-a[addp]);
	}
}

namespace line{
	int ans[maxn+5];
	void solve(){
		int cnt0=0;
		for(int i=1;i<=m;i++){
			int tp=lower_bound(p+1,p+1+n,node(b[i],0))-p;
			int pos=p[tp].id;
			if(tp==n+1){
				pos=n;
				cnt0++;
				if(cnt0>1||ans[n]){
					printf("-1\n");
					return ;
				}
			}
			if(ans[pos]){
				printf("-1\n");
				return;
			}
			ans[pos]=b[i];
		}
		
		
		set<node>s;
		set<int>s2;
		set<int>vis;
		int addp=0;
		int addv=0;
		int cnt=0;
		for(int i=1;i<=n;i++){
			s.insert(node(ans[i],i));
			s2.insert(ans[i]); 
			set<int>::iterator it2=s2.lower_bound(ans[i]);
			if(it2==s2.begin()) continue;
			else if(it2==(++s2.begin())){
				int val=*(++s2.begin());
				set<node>::iterator it=s.lower_bound(node(val,0));
				addp=it->id;
				addv=max(addv,val);
				vis.insert(addp);
			}else{
				printf("-1\n");
				return ;
			}
		}
		if(vis.size()>1) printf("-1\n");
		else printf("%d\n",addv-a[addp]);
	}
}

namespace brute_force{
	void solve(){
		printf("-1\n");
	}
}
int main(){
	freopen("oceanus.in","r",stdin);
	freopen("oceanus.out","w",stdout);
	bool is_flower=true,is_line=true;
	int u,v;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		p[i].id=i;
		p[i].h=a[i]; 
	} 
	for(int i=1;i<n;i++){
		scanf("%d %d",&u,&v);
		if(u!=1||v!=i+1) is_flower=false;
		if(v!=u+1) is_line=false;
		add_edge(u,v);
		add_edge(v,u);
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%d",&b[i]);
	}
	sort(p+1,p+1+n);
	if(is_flower) flower::solve();
	else if(is_line) line::solve();
	else brute_force::solve();
}
/*
3
4 2 8
1 2
1 3
2
17 15

4
1 5 4 3
1 2
1 3
1 4
3
5 4 3
*/ 
