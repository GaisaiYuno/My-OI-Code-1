#include<iostream>
#include<cstdio>
#include<cstring> 
#define mod 99824353
#define maxn 100000
using namespace std;
typedef long long ll;
inline void qread(int &x){
	x=0;
	int sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	x=x*sign;
}
inline void qprint(int x){
	if(x<0){
		putchar('-');
		qprint(-x);
	}else if(x==0){
		putchar('0');
		return;
	}else{
		if(x>=10) qprint(x/10);
		putchar('0'+x%10); 
	}
}
int n,m;
int a[maxn+5]; 

struct segment_tree{
	struct node{
		int l;
		int r;
		int val; 
	}tree[maxn*4+5];
	void push_up(int pos){
		tree[pos].val=tree[pos<<1].val|tree[pos<<1|1].val;
	} 
	void build(int l,int r,int pos){
		tree[pos].l=l;
		tree[pos].r=r;
		if(l==r){
			tree[pos].val=a[l];
			return;
		}
		int mid=(l+r)>>1;
		build(l,mid,pos<<1);
		build(mid+1,r,pos<<1|1);
		push_up(pos);
	}
	int query(int L,int R,int pos){
		if(L<=tree[pos].l&&R>=tree[pos].r){
			return tree[pos].val;
		}
		int mid=(tree[pos].l+tree[pos].r)>>1;
		int ans=0;
		if(L<=mid) ans|=query(L,R,pos<<1);
		if(R>mid) ans|=query(L,R,pos<<1|1);
		return ans;
	}
}T;
void dfs(int d,int maxd,int cnt,int k,int now,int need,int &ans){
	if(cnt==k){
		if(now==need) ans++;
		return;
	}
	if(d>maxd) return;
	dfs(d+1,maxd,cnt+1,k,now|a[d],need,ans);
	dfs(d+1,maxd,cnt,k,now,need,ans);
	
}
int brute_force(int l,int r,int k,int t){
	int ans=0;
	dfs(l,r,0,k,0,t,ans);
	return ans;
}

ll dp[2][maxn+5][100];
ll work_dp(int l,int r,int k,int t){
	int now=0;
	for(int i=0;i<=1;i++){
		for(int j=0;j<=k;j++){
			for(int s=0;s<64;s++) dp[i][j][s]=0;
		}
	}
	dp[0][0][0]=1;
	for(int i=l;i<=r;i++){
		for(int j=0;j<=k;j++){
			for(int s=0;s<64;s++) dp[now^1][j][s]=0;
		}
		for(int j=0;j<=k;j++){
			for(int s=0;s<64;s++){
				dp[now^1][j][s]+=dp[now][j][s];
				if(j+1<=k){
					dp[now^1][j+1][s|a[i]]+=dp[now][j][s];
					dp[now^1][j+1][s|a[i]]%=mod;
				}
			}
		}
		now^=1;
	}
	return dp[now][k][t];
}
int main(){
	int sz,x;
	int l,r,k,t;
	qread(n);
	qread(m);
	for(int i=1;i<=n;i++){
		qread(sz);
		for(int j=1;j<=sz;j++){
			qread(x);
			a[i]|=(1<<x);
		}
	}
	T.build(1,n,1);
	
	for(int i=1;i<=m;i++){
		qread(l);
		qread(r);
		qread(k);
		qread(sz);
		t=0;
		for(int j=1;j<=sz;j++){
			qread(x);
			t|=(1<<x);
		}
		if(r-l+1<k) qprint(0);
		else if(r-l+1==k){
			if(T.query(l,r,1)==t) qprint(1);
			else qprint(0);
		}else{
			qprint(work_dp(l,r,k,t));
//			else qprint(brute_force(l,r,k,t));
		}
		putchar('\n');
	}
}

