#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#define maxn 100005
#define mod 1000000007
using namespace std;
set<int>S;
struct edge {
	int from;
	int to;
	int next;
} E[maxn<<1];
int size=0;
int head[maxn];
void add_edge(int u,int v) {
	size++;
	E[size].from=u;
	E[size].to=v;
	E[size].next=head[u];
	head[u]=size;
}

int n,m;
int a[maxn];
int fact(int n){
	long long ans=1;
	for(int i=3;i<=n;i++){
		ans=ans%mod*i%mod;
	}
	return ans;
}
int main() {
	freopen("lighthouse.in","r",stdin);
	freopen("lighthouse.out","w",stdout);
	int u,v;
	scanf("%d %d",&n,&m);
	for(int i=1; i<=n; i++) a[i]=i;
	for(int i=1; i<=m; i++) {
		scanf("%d %d",&u,&v);
		add_edge(u,v);
		add_edge(v,u);
		S.insert(u);
		S.insert(v);
	}
	if(m==0){
		printf("%lld\n",fact(n-1)%mod);
	}else if(m==1){
		long long ans1=fact(n-1)%mod;
		long long ans2=fact(n-2)*2%mod;
		ans1-=ans2;
		if(ans1<0) ans1+=mod;
		printf("%lld\n",ans1%mod);
	}else if(m==2){
		long long ans=fact(n-3)%mod;
		ans=ans*(n-3)%mod;
		ans=ans*(n-4)%mod;
		printf("%lld\n",ans%mod);
	}else if(m==3&&S.size()==3){
		long long ans=fact(n-3)%mod;
		ans=ans*(n-4)%mod;
		ans=ans*(n-5)%mod;
		printf("%lld\n",ans%mod);
	}else if(n<=12) {
		int ans=0;
		a[n+1]=1;
		do {
			int cnt=0;
			bool flag=true;
			for(int i=1; i<=n; i++) {
				int p=a[i],q=a[i+1];
				for(int j=1; j<=size; j++) {
					if(E[j].from==p&&E[j].to==q) {
						flag=false;
						break;
					}
				}
				if(!flag) break;
			}
			if(flag) ans++;
//		for(int i=1;i<=n;i++){
//			printf("%d ",a[i]);
//		}
//		printf("cnt=%d\n",cnt);
		} while(next_permutation(a+2,a+1+n));
		printf("%d\n",ans>>1);
	}

}
