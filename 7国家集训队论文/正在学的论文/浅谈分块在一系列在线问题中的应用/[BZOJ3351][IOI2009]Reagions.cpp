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
	for(auto p : q1[a[x]]) ans[p.second]+=cnt[p.first];//��ѯ�������r1�ж��ٸ� 
	for(int y : E[x]){
		if(y!=fa) dfs1(y,x);
	}
	cnt[a[x]]--;//ֻ������ǰ�ڵ㵽������ 
}
void dfs2(int x,int fa){
	cnt[a[x]]++;
	 //r1=a[x]
	for(auto p : q2[a[x]]) ans[p.second]-=cnt[p.first];//�����Ⱥ����ȵ���������ȥ�� 
	for(int y : E[x]){
		if(y!=fa) dfs2(y,x);
	}
	for(auto p : q2[a[x]]) ans[p.second]+=cnt[p.first];//�ݳ⣬��ѯ�������r2�ж��ٸ� 
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
		if(qvis.count(make_pair(r1,r2))) id=qvis[make_pair(r1,r2)];//ѯ��ȥ��
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
			//���Ƿ��ָ��ӶȺ�q1[a[x].size(),q2[a[x]].size()�й� 
			//��cnt[r2]<sqrt(n),�Ͱ�r2��ͬ�ķ���һ��
			//��cnt[r1]<sqrt(n),�Ͱ�r1��ͬ�ķ���һ�� 
			//���cnt[r1],cnt[r2]������sqrt(n),������ѯ�ʲ��ᳬ��(n/cnt[r1])*(n/cnt[r2])��,��Ϊȥ����
			//�ܸ��Ӷ��� cnt[r1]*(n/cnt[r1])*(n/cnt[r2])=O(nsqrt(n))
		} 
		real_id[i]=id;
	}
	for(int i=1;i<=n;i++)  cnt[i]=0;
	dfs1(1,0);
	for(int i=1;i<=n;i++) cnt[i]=0;
	dfs2(1,0);
	for(int i=1;i<=q;i++) printf("%d\n",ans[real_id[i]]); 
}

