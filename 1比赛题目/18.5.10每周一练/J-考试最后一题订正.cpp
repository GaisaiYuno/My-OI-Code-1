#include<iostream>
#include<cstdio> 
#include<cstring>
#define maxn 35005
#define maxk 55
using namespace std;
int n,k;
int a[maxn];
int hash[maxn],last[maxn];
int dp[maxk][maxn]; 	//dp[i][j]表示前j个数分成i段的方法数 
struct node{
	int l;
	int r;
	int v;
	int mark;
}tree[maxn<<2];
void push_up(int pos){
	tree[pos].v=max(tree[pos<<1].v,tree[pos<<1|1].v);
}
void build(int i,int l,int r,int pos){
	tree[pos].l=l;
	tree[pos].r=r;
	tree[pos].mark=0;
    if(l==r){
    	tree[pos].v=dp[i][l-1];
    	return;
	}
	int mid=(l+r)>>1;
	build(i,l,mid,pos<<1);
	build(i,mid+1,r,pos<<1|1);
	push_up(pos);
}
void push_down(int pos){
	if(tree[pos].mark!=0){
		tree[pos<<1].mark+=tree[pos].mark;
		tree[pos<<1|1].mark+=tree[pos].mark;
		tree[pos<<1].v+=tree[pos].mark;
		tree[pos<<1|1].v+=tree[pos].mark;
		tree[pos].mark=0;
	}
}
void update(int L,int R,int v,int pos){
	if(L<=tree[pos].l&&R>=tree[pos].r){
		tree[pos].v+=v;
		tree[pos].mark+=v;
		return;
	}
	push_down(pos);
	int mid=(tree[pos].l+tree[pos].r)>>1;
	if(L<=mid)update(L,R,v,pos<<1);
	if(R>mid)update(L,R,v,pos<<1|1);
	push_up(pos); 
}
int query(int L,int R,int pos){
	if(L<=tree[pos].l&&R>=tree[pos].r){
		return tree[pos].v;
	}
	push_down(pos);
	int mid=(tree[pos].l+tree[pos].r)>>1;
	int ans=0;
	if(L<=mid)ans=max(ans,query(L,R,pos<<1));
	if(R>mid) ans=max(ans,query(L,R,pos<<1|1));
	return ans;
}
int main(){
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		last[i]=hash[a[i]];//last[i]->a[i]上一次出现的位置 
		hash[a[i]]=i;//hash[x]-> x上一次出现的位置 
	}
	//dp[i][j]=max(dp[i-1][x-1]+num[x][j],dp[i][j]) (i<=x<=j,num[x][j]->[x,j]不同数的个数
	//线段树维护 dp[i-1][x-1]+num[x][j]，变成区间查询最大值问题
	//加入a[j],从last[j]+1到j的所有num值都要+1 ,用线段树区间更新 
	for(int i=1;i<=k;i++){
		build(i-1,1,n,1);
		for(int j=i;j<=n;j++){
			update(last[j]+1,j,1,1);
			dp[i][j]=query(i,j,1);
		} 
//		printf("(i=%d)",i); 
//		for(int j=1;j<=n;j++) printf("%d ",dp[i][j]);
//		printf("\n");
	}
	printf("%d\n",dp[k][n]);
}
