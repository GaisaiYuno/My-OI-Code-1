#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100000
#define maxv 1000000000
using namespace std;
typedef long long ll;
int n;
int a[maxn+5];
struct fenwick_tree{
	int c[maxn*4+5];
	inline int lowbit(int x){
		return x&(-x);
	}
	void update(int pos,int val){
		for(int i=pos;i<=n*4;i+=lowbit(i)) c[i]+=val;
	}
	int sum(int pos){
		int ans=0;
		for(int i=pos;i>0;i-=lowbit(i)) ans+=c[i];
		return ans;
	}
	inline void insert(int val){
		update(val+n*2,1);
	}
	inline int query(int val){
		return sum(val+n*2);
	}
	inline void clear(){
		for(int i=0;i<=n*4;i++) c[i]=0;
	}
}T;
int p[maxn+5];
bool check(int x){
	p[0]=0;
	for(int i=1;i<=n;i++){
		if(a[i]>x) p[i]=p[i-1]+1;
		else p[i]=p[i-1];
	}
	ll sum=0;//满足区间的中位数不超过x的区间数量
	T.clear();
	T.insert(0);
	for(int i=1;i<=n;i++){
		T.insert(i-2*p[i]);
		sum+=T.query(i-2*p[i]-1);
	}
	if(sum>=1ll*n*(n+1)/4+1) return 1;//一共n*(n+1)/2个区间，中位数就是n*(n+1)/4+1 
	else return 0;
}

int main(){
	scanf("%d",&n);
	int l=maxv,r=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		l=min(l,a[i]);
		r=max(r,a[i]);
	}
	int ans=maxv,mid;
//	check(5);
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid)){
			ans=mid;
			r=mid-1;
		}else l=mid+1; 
	}
	printf("%d\n",ans);
}

