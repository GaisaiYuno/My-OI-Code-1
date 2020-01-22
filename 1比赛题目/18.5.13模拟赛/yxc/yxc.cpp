#include<iostream>
#include<cstdio>
#include<cstring>
#define ForMyLove return 0;
#define maxn 35005
#define maxk 55
using namespace std;
int a[maxn];
int vis[maxn];
int dp[maxk][maxn];
int n,k;
int get_v(int l,int r){
	memset(vis,0,sizeof(vis));
	int maxv=0,minv=maxn;
	for(int i=l;i<=r;i++){
		vis[a[i]]++;
		maxv=max(maxv,a[i]);
		minv=min(minv,a[i]);
	}
	int ans=0;
	for(int i=minv;i<=maxv;i++){
		if(vis[i]!=0) ans++;
	}
	return ans;
}
int main(){
	freopen("yxc.in","r",stdin);
	freopen("yxc.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			for(int x=0;x<j;x++)
			dp[i][j]=max(dp[i-1][x]+get_v(x+1,j),dp[i][j]);
		}
	}
	printf("%d\n",dp[k][n]);
	ForMyLove
}
/*
#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 35005
using namespace std;
int a[maxn],dp[maxn];
int vis[maxn];
int n,k;
int get_v(int l,int r){
	memset(vis,0,sizeof(vis));
	int maxv=0,minv=maxn;
	for(int i=l;i<=r;i++){
		vis[a[i]]++;
		maxv=max(maxv,a[i]);
		minv=min(minv,a[i]);
	}
	int ans=0;
	for(int i=minv;i<=maxv;i++){
		if(vis[i]!=0) ans++;
	}
	return ans;
}
struct node{
	int l;
	int r;
	int v;
}tree[maxn<<2];
void push_up(int pos){
	tree[pos].v=max(tree[pos<<1].v,tree[pos<<1|1].v);
}
void build(int l,int r,int pos,int i){
	tree[pos].l=l;
	tree[pos].r=r;
	if(l==r){
		tree[pos].v=dp[l]+get_v(l+1,i);
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,pos<<1,i);
	build(mid+1,r,pos<<1|1,i);
	push_up(pos);
}
int query(int L,int R,int l,int r,int pos){
	if(L<=l&&R>=r){
		return tree[pos].v;
	}
	int ans=0;
	int mid=(l+r)>>1;
	if(L<=mid) ans=max(ans,query(L,R,l,mid,pos<<1));
	if(R>mid) ans=max(ans,query(L,R,mid+1,r,pos<<1|1));
	return ans;
}
int main(){
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) dp[i]=get_v(1,i);
	for(int i=2;i<=n;i++){
		build(1,i,1,i);
		for(int j=1;j<=i;j++) dp[j]=query(1,j,1,i,1);
	}
	printf("%d\n",dp[n]);
}
*/
