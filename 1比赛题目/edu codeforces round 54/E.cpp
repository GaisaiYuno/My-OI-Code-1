//���ô��ǵ�˼�룬ÿ�εݹ����һ����xʱ�����´�x���µ�����ѯ�ʣ���deep[x]+d�Ľڵ���� 
//��״�������i���ڵ�浱ǰ���Ϊi�Ľڵ�ı�ǣ����ڻ���ʱɾ����ǣ���֤��ǰ���Ϊi�Ĵ��˱�ǽڵ�ֻ��1�� 
//ע�⣺ÿ�θ���x�ľ���Ϊd�Ľڵ�ʱֻ����deep[x]+d
//       ��ѯxʱҪ��ѯx�������е�ֵ֮�ͣ����нڵ�֮�� ����Ϊ���x�������еĽڵ㱻���ˣ�xһ��Ҳ�����ˣ�
//����ʱɾ����ǣ�����ÿ�β�ѯʱ����֤��x�������еĽڵ� 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#define maxn 300005
using namespace std;
int n,m;
vector<int>E[maxn];
struct quest {
	int u;
	int d;
	int v;
	quest(){
		
	}
	quest(int x,int dist,int val){
		u=x;
		d=dist;
		v=val;
	}
};
vector<quest>q[maxn];

struct fenwick_tree {
	long long c[maxn];
	inline int lowbit(int x) {
		return x&-x;
	}
	void update(int x,long long v) {
		while(x<=n) {
			c[x]+=v;
			x+=lowbit(x);
		}
	}
	long long sum(int x) {
		long long ans=0;
		while(x>0){
			ans+=c[x];
			x-=lowbit(x);
		}
		return ans;
	}
	long long query(int l,int r){
		return sum(r)-sum(l-1);
	}
}T;

int deep[maxn];
void dfs1(int x,int fa){
	deep[x]=deep[fa]+1;
	for(int i=0;i<E[x].size();i++){
		int y=E[x][i];
		if(y!=fa) dfs1(y,x);
	}
}

long long ans[maxn];
void dfs2(int x,int fa){
	for(int i=0;i<q[x].size();i++){
		T.update(min(deep[q[x][i].u]+q[x][i].d,n),q[x][i].v);
	}
	ans[x]=T.query(deep[x],n);
	for(int i=0;i<E[x].size();i++){
		int y=E[x][i];
		if(y!=fa){
			dfs2(y,x);
		}
	}
	for(int i=0;i<q[x].size();i++){
		T.update(min(deep[q[x][i].u]+q[x][i].d,n),-q[x][i].v);
	}
}

int main(){
	int u,v,w;
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		scanf("%d %d",&u,&v);
		E[u].push_back(v);
		E[v].push_back(u);
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&u,&v,&w);
		q[u].push_back(quest(u,v,w));
	}
	dfs1(1,0);
	dfs2(1,0);
	for(int i=1;i<=n;i++){
		printf("%I64d ",ans[i]);
	}
}
