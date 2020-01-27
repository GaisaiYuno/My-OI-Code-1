#include<iostream>
#include<cstdio>
#include<cstring>
#include<deque>
#include<algorithm>
#define maxn 100000
#define maxk 100
using namespace std;
typedef long long ll;
struct seg {
	int l;
	int r;
	seg() {

	}
	seg(int _l,int _r) {
		l=_l;
		r=_r;
	}
	friend bool operator < (seg a,seg b) {
		if(a.l==b.l) return a.r>b.r;
		else return a.l<b.l;
	}
} a[maxn+5],b[maxn+5];

struct segment_tree{
	struct node{
		int l;
		int r;
		ll val;
		ll mark;
	}tree[maxn*4+5];
	void push_up(int pos){
		tree[pos].val=tree[pos<<1].val+tree[pos<<1|1].val; 
	}
	void build(int l,int r,int pos){
		tree[pos].l=l;
		tree[pos].r=r;
		tree[pos].val=tree[pos].mark=0;
		if(l==r) return;
		int mid=(l+r)>>1;
		build(l,mid,pos<<1);
		build(mid+1,r,pos<<1|1);
		push_up(pos);
	}
	void push_down(int pos){
		if(tree[pos].mark){
			tree[pos<<1].mark+=tree[pos].mark;
			tree[pos<<1|1].mark+=tree[pos].mark;
			tree[pos<<1].val+=tree[pos].mark;
			tree[pos<<1|1].val+=tree[pos].mark;
			tree[pos].mark=0;
		}
	} 
	void update(int L,int R,int val,int pos){
		if(L<=tree[pos].l&&R>=tree[pos].r){
			tree[pos].val+=val;
			tree[pos].mark+=val;
			return;
		}
		push_down(pos);
		int mid=(tree[pos].l+tree[pos].r)>>1;
		if(L<=mid) update(L,R,val,pos<<1);
		if(R>mid) update(L,R,val,pos<<1|1);
		push_up(pos);
	}
	ll query(int L,int R,int pos){
		if(L<=tree[pos].l&&R>=tree[pos].r){
			return tree[pos].val;
		}
		push_down(pos);
		int mid=(tree[pos].l+tree[pos].r)>>1;
		ll ans=0;
		if(L<=mid) ans=max(ans,query(L,R,pos<<1));
		if(R>mid) ans=max(ans,query(L,R,pos<<1|1));
		return ans;
	}
}T;
struct node {
	int id;
	int val;
	node() {

	}
	node(int _id,int _val) {
		id=_id;
		val=_val;
	}
};
deque<node>q[maxn+5];
int maxp[maxn+5];
int dp[maxn+5][maxk+5];
int n,k;
int main() {
	scanf("%d %d",&n,&k);
	for(int i=1; i<=n; i++) scanf("%d %d",&b[i].l,&b[i].r);
	sort(b+1,b+1+n);
	int rb=0;
	int cnt=0;
	for(int i=1; i<=n; i++) {
		if(b[i].r>rb) {
			a[++cnt]=b[i];
			rb=a[i].r;
		} else k--;//���������������ֱ��ɾ��
	}
	T.build(1,n,1);
	n=cnt;
	for(int i=1; i<=n; i++) {
		for(int j=0; j<=min(i-1,k); j++) {
			int now=i-j-1;
			//�������ཻʱ,dp[i][j]=dp[x][y]+a[i].r-a[x].r (y=j-(i-x-1))
			//��Ϊ����ת�ƹ�����dp[x][y]������x-y=i-j-1,���Կ�n���������У�q[val]�洢x-y=val��ֵ,�Ӵ�С
			//��dp[x][y]-a[x].r
			//���ཻʱdp[i][j]=dp[x][y]+a[i].r-a[i].l
			while(!q[now].empty()&&a[q[now].front().id].r<a[i].l) { //�ȴ����ཻ��
				maxp[now]=max(maxp[now],q[now].front().val+a[q[now].front().id].r); //�����dp[x][y]-a[x].r,��dp[x][y]Ҫ�ӻ���
				q[now].pop_front();
			}
			dp[i][j]=max(dp[i][j],maxp[now]+a[i].r-a[i].l);
			if(!q[now].empty()) dp[i][j]=max(dp[i][j],q[now].front().val+a[i].r);//ȥ�����ཻ�ģ���ͷ�����ཻ������
			now=i-j;
			while(!q[now].empty()&&q[now].back().val<dp[i][j]-a[i].r) q[now].pop_back();
			q[now].push_back(node(i,dp[i][j]-a[i].r));
		}
	}
	int ans=0;
	for(int i=1; i<=n; i++) {
		for(int j=0; j<=min(i-1,k); j++) {//ö���ĸ����������һ����ȡ�� 
			if (j+n-i==k) ans=max(ans,dp[i][j]);
		}
	}


	printf("%d\n",ans);
}
