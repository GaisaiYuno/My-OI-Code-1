#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define maxn 1000005
#define mod 1000000007
#define maxk 105
using namespace std;
int n;
long long m;
int k;
struct matrix {
	int n;
	int m;
	long long a[maxk][maxk];
	matrix() {
		memset(a,0,sizeof(a));
	}
	matrix(int x,int y) {
		n=x;
		m=y;
		memset(a,0,sizeof(a));
	}
	void print() {
		for(int i=1; i<=k+1; i++) {
			for(int j=1; j<=k+1; j++) {
				printf("%lld ",a[i][j]%mod);
			}
			printf("\n");
		}
		printf("\n");
	}
	long long* operator [] (int x){
		return a[x];
	}
	friend matrix operator *(matrix x,matrix y) {
		matrix c=matrix(k+1,k+1);
		for(int i=1; i<=k+1; i++) {
			for(int u=1; u<=k+1; u++) {
				for(int j=1; j<=k+1; j++) {
					c[i][j]+=x[i][u]*y[u][j]%mod;
					c[i][j]%=mod; 
				}
			}
		}
		return c;
	}
};
matrix fast_pow(matrix x,long long kk) {
	matrix ans=matrix(x.n,x.m);
	for(int i=1; i<=x.n; i++) {
		ans[i][i]=1;
	}
	while(kk) {
		if(kk&1) ans=ans*x;
		x=x*x;
		kk>>=1;
	}
	return ans;
}
int a[maxn];
int pos[maxn];
int rank[maxn];
long long cur[maxn];
int cmp(int x,int y){
	return pos[x]<pos[y];
}
long long dp[maxk];
struct node {
	long long id;
	long long v;
	node() {

	}
	node(long long i,long long x) {
		id=i;
		v=x;
	}
	friend bool operator <(node a,node b) {
		return a.v>b.v;
	}
};
priority_queue<node>q;
int main() {
	scanf("%d %lld %d",&n,&m,&k);
	for(int i=1; i<=n; i++) scanf("%d",&a[i]);
	long long sum=0,tmp=0;
	for(int i=1; i<=n; i++) {
		tmp=sum;
		sum=(2*sum+1-dp[a[i]]+mod)%mod;
		dp[a[i]]=(tmp+1)%mod;
		pos[a[i]]=i;
		rank[i]=i;
	}
	for(int i=1;i<=k;i++) rank[i]=i;
	sort(rank+1,rank+k+1,cmp);
	matrix d=matrix(1,k+1);
//	for(int i=1;i<=k;i++) printf("%d ",dp[i]);
//	printf("\n");
//	for(int i=1;i<=k;i++) printf("%d ",rank[i]);
//	printf("\n");
	for(int i=1;i<=k;i++){
		d[1][i]=dp[rank[i]];
	}
	d[1][k+1]=1;
//	d.print();
	matrix cons=matrix(k+1,k+1);
	for(int i=1;i<=k;i++){
		memset(cur,0,sizeof(cur));
		cur[i]=1;
		sum=1;
		for(int j=1;j<=k;j++){
			tmp=sum;
			sum=(2*sum-cur[j]+mod)%mod;
			cur[j]=tmp;
		}
		for(int j=1;j<=k;j++) cons[i][j]=cur[j];
	}
//	printf("%d\n",sum);
	memset(cur,0,sizeof(cur));
	sum=0;
	for(int i=1;i<=k;i++){
		tmp=sum;
		sum=(2*sum-cur[i]+1+mod)%mod;
		cur[i]=(tmp+1)%mod;
	}
	for(int i=1;i<=k;i++) cons[k+1][i]=cur[i];
	cons[k+1][k+1]=1;
	matrix ans=matrix(1,k+1);
//	cons.print();
//	d.print();
	matrix t=fast_pow(cons,m/k);
//	t.print();
	d=d*t;
//	d.print();
	sum=0;
	for(int i=1;i<=k;i++){
		dp[i]=d[1][i];
		sum=(sum+dp[i])%mod;
	}
	for(int i=1;i<=m%k;i++){
		int tmp=sum;
		sum=(2*sum-dp[i]+1+mod)%mod;
		dp[i]=(tmp+1)%mod;
	}
	printf("%lld\n",sum);
	
}

