//http://codeforces.com/problemset/problem/464/E
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue> 
#include<cmath>
#define maxn 500000
#define maxm 500000
#define maxlog 25
#define mod 1000000007
#define INF 0x3f3f3f3f
using namespace std;
int n,m,dg;//dg�Ƕ�����λ�� 
long long pow2[maxn+5];
struct segment_tree{//��ϯ��ά������ֵλ ,�±�[1,n]�ӵ�λ����λ�洢������ 
#define lson(x) tree[x].ls
#define rson(x) tree[x].rs
	struct node{
		int ls;
		int rs;
		long long sum;//������ֵȡģmod֮���ֵ
		//�ȿ����������´𰸣�Ҳ���Ե���hash�ж����˶������Ƿ���� 
	}tree[maxn*maxlog+5];
	int ptr;
	void push_up(int x,int l,int r){
		int mid=(l+r)>>1;
		tree[x].sum=tree[lson(x)].sum+tree[rson(x)].sum*pow2[mid-l+1]%mod;
		tree[x].sum%=mod;
	}
	int insert(int &x,int last,int upos,int l,int r){
		x=++ptr;
		tree[x]=tree[last];
		if(l==r){
			tree[x].sum^=1;//+1��1��0��0��1����λ�����ٴ��� 
			return tree[last].sum;
		}
		int mid=(l+r)>>1;
		int res;
		if(upos<=mid){
			//upos<=mid,�����λ��[mid+1,r]��Ӧ�ĸ�λҲ�ᱻ��λ������Ҫ�ݹ���ȥ�޸� 
			//���Ǽ��������xi��=1����ô��Ҫ��λO(m/2+m/4+m/8+...+1)��O(m) 
			res=insert(tree[x].ls,tree[last].ls,upos,l,mid); 
			//���res������0��˵��֮ǰ[l,mid]����ֵ��Ҫ������λ 
			if(res) res=insert(tree[x].rs,tree[last].rs,upos,mid+1,r);
		}else{
			res=insert(tree[x].rs,tree[last].rs,upos,mid+1,r);
		} 
		push_up(x,l,r);
		return res;
	}
	bool cmp(int x,int y,int l,int r){//�Ƚ�x,y������ϯ����Ӧ�Ķ����ƴ�С 
		if(l==r){
			return tree[x].sum<tree[y].sum;
		} 
		int mid=(l+r)>>1;
		if(tree[tree[x].rs].sum==tree[tree[y].rs].sum) return cmp(tree[x].ls,tree[y].ls,l,mid);//�Ӹ�λ����λ����λ��ͬ�ͱȵ�λ
		else return cmp(tree[x].rs,tree[y].rs,mid+1,r); 
	}
#undef lson
#undef rson
}T;

struct edge{
	int from;
	int to;
	int next;
	int len;
}E[maxm*2+5];
int head[maxn+5];
int ecnt=1;
void add_edge(int u,int v,int w){
	ecnt++;
	E[ecnt].from=u;
	E[ecnt].to=v;
	E[ecnt].len=w;
	E[ecnt].next=head[u];
	head[u]=ecnt;
} 

struct heap_node{
	int id;
	int rt;//��Ӧ��������ϯ�������� 
	heap_node(){
		
	}
	heap_node(int _id,int _rt){
		id=_id;
		rt=_rt;
	}
	friend bool operator < (heap_node p,heap_node q){
		return !T.cmp(p.rt,q.rt,0,dg); 
	}
}; 
priority_queue<heap_node>q;
int vis[maxn+5];
int disrt[maxn+5];
int pre[maxn+5];
long long dijkstra(int s,int t){
	memset(disrt,0x3f,sizeof(disrt));
	disrt[s]=0;
	q.push(heap_node(s,disrt[s]));
	while(!q.empty()){
		heap_node x=q.top();
		q.pop();
		if(vis[x.id]) continue;
		vis[x.id]=1;
		for(int i=head[x.id];i;i=E[i].next){
			int y=E[i].to;
			int tmprt;
			T.insert(tmprt,disrt[x.id],E[i].len,0,dg);
			if(disrt[y]==INF||T.cmp(tmprt,disrt[y],0,dg)){
				disrt[y]=tmprt;
				pre[y]=i;
				q.push(heap_node(y,disrt[y]));
			}
		}
	}
	if(disrt[t]==INF) return -1;
	else return T.tree[disrt[t]].sum;
}

int cnt=0;
int res[maxn+5];
void get_ans(int s,int t){
	int x=t;
	while(x!=s){
		res[++cnt]=x;
		x=E[pre[x]].from;
	}
	res[++cnt]=x;
}

int main(){
	int u,v,w;
	int s,t;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&u,&v,&w);
		add_edge(u,v,w);
		add_edge(v,u,w);
		dg=max(dg,w);
	}
	scanf("%d %d",&s,&t);
	
	dg+=log2(m)+1;//��λ 
	pow2[0]=1;
	for(int i=1;i<=dg;i++) pow2[i]=pow2[i-1]*2%mod; 
	
	long long ans=dijkstra(s,t);
	printf("%I64d\n",ans);
	if(ans==-1) return 0;
	
	cnt=0;
	get_ans(s,t);
	printf("%d\n",cnt);
	for(int i=cnt;i>=1;i--){
		printf("%d ",res[i]);
	}
} 
