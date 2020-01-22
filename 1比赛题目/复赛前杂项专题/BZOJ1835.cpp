#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm> 
#include<vector>
#define maxn 100000
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
struct segment_tree{
	struct node{
		int l;
		int r;
		ll val;
		ll mark;
	}tree[maxn*4+5];
	void push_up(int pos){
		tree[pos].val=min(tree[pos<<1].val,tree[pos<<1|1].val); 
	}
	void build(int l,int r,ll *a,int pos){
		tree[pos].l=l;
		tree[pos].r=r;
		tree[pos].val=tree[pos].mark=0;
		if(l==r){
			tree[pos].val=a[l];
			return;
		}
		int mid=(l+r)>>1;
		build(l,mid,a,pos<<1);
		build(mid+1,r,a,pos<<1|1);
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
	void update(int L,int R,ll val,int pos){
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
		if(L>R) return 0;
		if(L<=tree[pos].l&&R>=tree[pos].r){
			return tree[pos].val;
		}
		push_down(pos);
		int mid=(tree[pos].l+tree[pos].r)>>1;
		ll ans=INF;
		if(L<=mid) ans=min(ans,query(L,R,pos<<1));
		if(R>mid) ans=min(ans,query(L,R,pos<<1|1));
		return ans;
	}
}T;

int n,k;
ll d[maxn+5];
ll c[maxn+5];
ll s[maxn+5];
ll w[maxn+5];
int lb[maxn+5],rb[maxn+5];
vector<int>pos[maxn+5];

ll dp[maxn+5];//dp[i][j] i个村,j个基站，第i个村放基站
//dp[i][j]=c[i]+min(dp[k][j-1]+cost(i,k)) cost(i,k)为补偿的费用 
//j可以滚动掉 
int main(){
	scanf("%d %d",&n,&k);
	for(int i=2;i<=n;i++) scanf("%lld",&d[i]);
	for(int i=1;i<=n;i++) scanf("%lld",&c[i]);
	for(int i=1;i<=n;i++) scanf("%lld",&s[i]);
	for(int i=1;i<=n;i++) scanf("%lld",&w[i]);
	n++;
	k++;
	d[n]=w[n]=INF;//防止边界错误 
	for(int i=1;i<=n;i++){
		lb[i]=lower_bound(d+1,d+1+n,d[i]-s[i])-d;
		rb[i]=upper_bound(d+1,d+1+n,d[i]+s[i])-d-1;
		pos[rb[i]].push_back(i);
	} 
	ll sumw=0;
	ll ans=INF;
	for(int i=1;i<=n;i++){
		dp[i]=sumw+c[i];
		for(int j=0;j<(int)pos[i].size();j++){
			int x=pos[i][j];
		//rb[x]=i,那么i->i+1时,x就一定不能被i+1覆盖到了
		//所以补偿费用要加上w[x] 
			sumw+=w[x];
		}
		
	}
	ans=min(ans,dp[n]);
	for(int j=2;j<=k;j++){
		T.build(0,n,dp,1);//把上一层的dp数组建树 
		for(int i=1;i<=n;i++){
			dp[i]=T.query(0,i-1,1)+c[i];
			for(int u=0;u<(int)pos[i].size();u++){
				int x=pos[i][u];
				T.update(0,lb[x]-1,w[x],1);
			}
			//dp[p](p<st[x])+w[x] 在st[x]-1之前放基站一定不能覆盖到w[x],且i之后放也覆盖不到w[x] 
		}
		ans=min(ans,dp[n]); 
	}
	printf("%lld\n",ans);
}

