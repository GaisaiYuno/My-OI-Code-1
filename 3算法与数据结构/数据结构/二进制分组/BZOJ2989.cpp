/*
�����Ʒ���Ļ���˼���ǰ��޸Ĳ����������Ʒ��飬�����޸ľ���β����һ��������֮ǰ�ĺϲ���
����֮ǰ��23��16+4+2+1����������һ����ͱ��16+4+2+1+1,��1��1�ϲ������ 
������ѯ����ÿ�����ڲ�ѯ���ټ������ͺ��ˡ�
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<utility> 
#include<vector> 
#define maxn 100000
#define maxlogn 32
#define INF 0x3f3f3f3f
using namespace std;
int n,q;
int a[maxn+5];
struct mem_pool{//��д�ڴ�أ�����ɾ���ĵ��ֹMLE 
	 int top=0;
	 int stk[maxn*2*maxlogn+5];
	 inline void ini(int n){
	 	for(int i=n;i>=1;i--) stk[++top]=i;
	 } 
	 inline int New(){
	 	return stk[top--];
	 }
	 inline void del(int x){
	 	stk[++top]=x;
	 }
}pool;

//��x������ɢ������x����Ϊ�±꽨n�ÿɳ־û��߶���ά��ǰ׺�ͣ�y����Ϊ�߶����±�
//�ڵ�x-k(��ɢ����)����x+k���߶����ϲ�����[y-k,y+k]�Ϳ��Եõ���άǰ׺�� 
int root[maxlogn+5][maxn*2+5];//root[i][j],��i���������������jС��x������ڵ��߶��� 
struct persist_segment_tree{
	#define lson(x) tree[x].ls
	#define rson(x) tree[x].rs
	struct node{
		int ls;
		int rs;
		int val;
	}tree[maxn*2*maxlogn+5];
	bool is_del[maxn*2*maxlogn+5];
	//��Ϊһ���㲻�ܱ�ɾ������(��ϯ���ϵ�һ������ܱ�����ڵ�ָ��)������
	int New(){
		int x=pool.New();
		is_del[x]=0;
		return x;
	}
	void push_up(int x){
		tree[x].val=tree[lson(x)].val+tree[rson(x)].val;
	}
	void update(int &x,int last,int upos,int l,int r){
		x=New();
		tree[x]=tree[last];
		if(l==r){
			tree[x].val++;
			return;
		}
		int mid=(l+r)>>1;
		if(upos<=mid) update(tree[x].ls,tree[last].ls,upos,l,mid);
		else update(tree[x].rs,tree[last].rs,upos,mid+1,r);
		push_up(x);
	} 
	int query(int xl,int xr,int ql,int qr,int l,int r){
		if(ql<=l&&qr>=r){
			return tree[xr].val-tree[xl].val;
		}
		int mid=(l+r)>>1;
		int ans=0;
		if(ql<=mid) ans+=query(tree[xl].ls,tree[xr].ls,ql,qr,l,mid);
		if(qr>mid) ans+=query(tree[xl].rs,tree[xr].rs,ql,qr,mid+1,r);
		return ans; 
	}
	void del(int x){
		if(is_del[x]) return;
		is_del[x]=1;
		pool.del(x);
		if(tree[x].ls) del(tree[x].ls);
		if(tree[x].rs) del(tree[x].rs);
		tree[x].val=tree[x].ls=tree[x].rs=0; 
	}
}T;

int top=0;
vector< pair<int,int> >v[maxlogn+5];//�洢ÿ��������޸Ĳ��� 
int sz[maxlogn+5]; 
void rebuild(int id){//�ع�ĳ���� 
	for(int i=1;i<=sz[id];i++){
		//�ѵ�i��y������� 
		T.update(root[id][i],root[id][i-1],v[id][i-1].second,1,maxn*2);
	} 
} 
void insert(pair<int,int> p){
	sz[++top]=1;
	v[top].push_back(p);
	rebuild(top);
	while(top>1&&sz[top-1]==sz[top]){//���ƶ����Ƽӷ���λ��ȥ�ϲ� 
		for(int i=0;i<sz[top];i++) v[top-1].push_back(v[top][i]);
		sort(v[top-1].begin(),v[top-1].end());//�����൱����ɢ��
		v[top].clear();
		for(int i=1;i<=sz[top];i++){
			if(root[top-1][i]) T.del(root[top-1][i]);//��ɾ���������ٱ����ع�
			if(root[top][i]) T.del(root[top][i]); 
		}
		sz[top-1]+=sz[top];
		rebuild(top-1);
		top--;
	}
} 
int query(pair<int,int>p,int k){
	int x=p.first,y=p.second,l,r;
	int ans=0;
	for(int i=1;i<=top;i++){
		l=upper_bound(v[i].begin(),v[i].end(),make_pair(x-k,0))-v[i].begin();
		//��������<=��+1(root�±��1��ʼ)��ֱ��upper_boundҲ���� 
		r=upper_bound(v[i].begin(),v[i].end(),make_pair(x+k,INF))-v[i].begin();
		if(l<=r) ans+=T.query(root[i][l],root[i][r],max(y-k,0),min(y+k,maxn*2),1,maxn*2);
	}
	return ans;
}

char s[10];
int main(){
	int x,k;
	scanf("%d %d",&n,&q);
	pool.ini(maxn*2*maxlogn);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		insert(make_pair(a[i]+i,a[i]-i+maxn));//Ϊ�˷�ֹ������Ҫ+maxn��ע������Ҫ������ 
	}
	for(int i=1;i<=q;i++){
		scanf("%s",s);
		if(s[0]=='M'){
			scanf("%d %d",&x,&k);
			a[x]=k;
			insert(make_pair(a[x]+x,a[x]-x+maxn));
		}else{
			scanf("%d %d",&x,&k);
			printf("%d\n",query(make_pair(a[x]+x,a[x]-x+maxn),k));
		}
	}
}

