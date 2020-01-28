#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 10000005
#define maxm 25
#define mod 1000000007
using namespace std;
int n,m;
inline long long fast_pow(long long x,long long k) {
	long long ans=1;
	while(k) {
		if(k&1) ans=ans*x%mod;
		x=x*x%mod;
		k>>=1;
	}
	return ans%mod;
}
inline long long inv(long long x) {
	return fast_pow(x,mod-2);
}
struct edge {
	int from;
	int to;
} E[maxm];
int fa[maxn];
long long fact[maxn],pow2[maxn];
int find(int x) {
	if(fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}
void merge(int x,int y) {
	fa[find(x)]=fa[y];
}

void init() {
	for(int i=0; i<=n; i++) fa[i]=i;
	fact[0]=1;
	for(int i=1; i<=n; i++) {
		fact[i]=fact[i-1]*i%mod;
	}
	pow2[0]=1;
	for(int i=1; i<=n; i++) {
		pow2[i]=pow2[i-1]*2%mod;
	}
}

int deg[maxn];
int sz;
long long get_hmd(int s) { //s为删掉边的子集
	for(int i=0; i<m; i++) {
		if(s&(1<<i)) {
			if(deg[E[i].from]>2||deg[E[i].to]>2) return 0;// 度数大于2
		}
	}
	bool is_ring=false;
	for(int i=0; i<m; i++) {
		if(s&(1<<i)) {
			if(find(E[i].from)==find(E[i].to)) is_ring=true;
			else merge(E[i].from,E[i].to);
		}
	}

	int k=0;//链的个数
	for(int i=0; i<m; i++) {
		if(s&(1<<i)) {
			if(fa[E[i].from]==E[i].from) {
				k++;
				fa[E[i].from]=0;
			}
			if(fa[E[i].to]==E[i].to) {//是链的端点
				k++;
				fa[E[i].to]=0;
			}
		}
	}
//	printf("%d %d\n",s,k);
	for(int i=0; i<m; i++) {
		fa[E[i].from]=E[i].from;
		fa[E[i].to]=E[i].to;
	}

	if(is_ring) {
		if(sz!=n||k>1) return 0;
		else return 1;//S本身就是一个哈密顿回路
	} else {
		return pow2[k-1]*fact[n-sz-1]%mod;
	}
}

int main() {
	scanf("%d %d",&n,&m);
	for(int i=0; i<m; i++) {
		scanf("%d %d",&E[i].from,&E[i].to);
	}
	init();
	long long tmp=0;
	long long ans=0;
	ans=fact[n-1]*inv(2)%mod;
	for(int i=1; i<(1<<m); i++) {
		sz=0;
		if(i==5) {
			i=5;
		}
		for(int j=0; j<m; j++) {
			if(i&(1<<j)) {
				sz++;
				deg[E[j].from]++;
				deg[E[j].to]++;
			}
		}
		if(sz&1) tmp=-get_hmd(i);
		else tmp=get_hmd(i);
//		printf("%lld\n",tmp);
		ans+=tmp%mod;
		ans=(ans+mod)%mod;
		for(int i=0; i<m; i++) {
			deg[E[i].from]=0;
			deg[E[i].to]=0;
		}
	}
	printf("%lld\n",ans);
}
