#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#include<utility>
#include<cmath>
#define maxn 200000
using namespace std;
int n,r,q;
vector<int>E[maxn+5];
inline void add_edge(int u,int v){
	E[u].push_back(v);
	E[v].push_back(u);
}
vector< pair<int,int> >q1[maxn+5],q2[maxn+5];

int a[maxn+5];
int cnt[maxn+5];
int ans[maxn+5];
void dfs1(int x,int fa){
	cnt[a[x]]++;
	//r2=a[x]
	for(auto p : q1[a[x]]) ans[p.second]+=cnt[p.first];//查询祖先里的r1有多少个 
	for(int y : E[x]){
		if(y!=fa) dfs1(y,x);
	}
	cnt[a[x]]--;//只保留当前节点到根的链 
}
void dfs2(int x,int fa){
	cnt[a[x]]++;
	 //r1=a[x]
	for(auto p : q2[a[x]]) ans[p.second]-=cnt[p.first];//把祖先和祖先的其他子树去掉 
	for(int y : E[x]){
		if(y!=fa) dfs2(y,x);
	}
	for(auto p : q2[a[x]]) ans[p.second]+=cnt[p.first];//容斥，查询子树里的r2有多少个 
}

map< pair<int,int> ,int>qvis; 
int real_id[maxn+5];
int main(){
	int f,r1,r2;
	scanf("%d %d %d",&n,&r,&q);
	scanf("%d",&a[1]);
	for(int i=2;i<=n;i++){
		scanf("%d %d",&f,&a[i]);
		add_edge(f,i);
	}
	for(int i=1;i<=n;i++) cnt[a[i]]++;
	int bsz=sqrt(n);
	for(int i=1;i<=q;i++){
		scanf("%d %d",&r1,&r2);
		int id=i;
		if(qvis.count(make_pair(r1,r2))) id=qvis[make_pair(r1,r2)];//询问去重
		else{
			qvis[make_pair(r1,r2)]=i;
			if(cnt[r2]<bsz){
				q1[r2].push_back(make_pair(r1,i));
//				printf("q1[%d]: (r1=%d,r2=%d,i=%d)",r2,r1,r2,i);
			}
			else{
				q2[r1].push_back(make_pair(r2,i));
//				printf("q2[%d]: (r1=%d,r2=%d,i=%d)",r1,r1,r2,i);
			}
			printf("\n");
			//我们发现复杂度和q1[a[x].size(),q2[a[x]].size()有关 
			//若cnt[r2]<sqrt(n),就把r2相同的分在一起
			//若cnt[r1]<sqrt(n),就把r1相同的分在一起 
			//如果cnt[r1],cnt[r2]均大于sqrt(n),这样的询问不会超过(n/cnt[r1])*(n/cnt[r2])个,因为去了重
			//总复杂度是 cnt[r1]*(n/cnt[r1])*(n/cnt[r2])=O(nsqrt(n))
		} 
		real_id[i]=id;
	}
	for(int i=1;i<=n;i++)  cnt[i]=0;
	dfs1(1,0);
	for(int i=1;i<=n;i++) cnt[i]=0;
	dfs2(1,0);
	for(int i=1;i<=q;i++) printf("%d\n",ans[real_id[i]]); 
}

