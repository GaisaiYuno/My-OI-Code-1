#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<map>
#define maxn 100005
#define maxlog 32
#define INF 10000005
using namespace std;
int a[maxn];
inline int gcd(int a,int b) {
	return b==0?a:gcd(b,a%b);
}
struct sparse_table {
	int st[maxn][maxlog];
	void init(int *a,int n) {
		for(int i=1; i<=n; i++) st[i][0]=a[i];
		for(int j=1; (1<<j)<=n; j++) {
			for(int i=1; i+(1<<j)-1<=n; i++) {
				st[i][j]=gcd(st[i][j-1],st[i+(1<<(j-1))][j-1]);
			}
		}
	}
	int query(int l,int r) {
		if(l==r) return st[l][0];
		int k=log2(r-l+1);
		return gcd(st[l][k],st[r-(1<<k)+1][k]);
	}
};
int n,q;
sparse_table gcda;
map<int,long long>ans;
int bin_search(int L,int R,int sta,int v){
	int l=L,r=R;
	int ans=INF;
	while(l<=r){
		int mid=(l+r)>>1;
		if(gcda.query(sta,mid)==v){
			l=mid+1;
		}else{
			r=mid-1;
			ans=min(ans,mid-1);
		}
	}
	if(ans==INF) return r;
	else return ans;
}
int main() {
//	freopen("input.txt","r",stdin);
	scanf("%d",&n);
	for(int i=1; i<=n; i++) scanf("%d",&a[i]);
	gcda.init(a,n);
	ans.clear();
	int now_gcd,now_pos;
	for(int i=1; i<=n; i++) {
		now_gcd=a[i];
		now_pos=i;
		while(1) {
			int pre_pos=now_pos;
			now_pos=bin_search(pre_pos,n,i,now_gcd);
			now_gcd=gcda.query(i,now_pos);
			ans[now_gcd]+=now_pos-pre_pos+1;
			if(now_pos<n) {
				now_pos++;
				now_gcd=gcda.query(i,now_pos);
			} else break;

		}
	}
	scanf("%d",&q);
	int x;
	while(q--) {
		scanf("%d",&x);
		printf("%I64d\n",ans[x]);
	}
}
