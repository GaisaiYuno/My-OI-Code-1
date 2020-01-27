#include<iostream>
#include<cstdio> 
#include<cstring>
#define maxn 35005
#define maxk 55
using namespace std;
int n,k;
int a[maxn];
int hash[maxn],last[maxn];
int dp[maxk][maxn]; 	//dp[i][j]��ʾǰj�����ֳ�i�εķ����� 
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
		last[i]=hash[a[i]];//last[i]->a[i]��һ�γ��ֵ�λ�� 
		hash[a[i]]=i;//hash[x]-> x��һ�γ��ֵ�λ�� 
	}
	//dp[i][j]=max(dp[i-1][x-1]+num[x][j],dp[i][j]) (i<=x<=j,num[x][j]->[x,j]��ͬ���ĸ���
	//�߶���ά�� dp[i-1][x-1]+num[x][j]����������ѯ���ֵ����
	//����a[j],��last[j]+1��j������numֵ��Ҫ+1 ,���߶���������� 
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
