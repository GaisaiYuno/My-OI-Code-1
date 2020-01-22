#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100005
#define mod 99999997 
using namespace std;
int n;
struct node{
	int x;
	int id;
	friend bool operator < (node a,node b){
		return a.x<b.x;
	}
}a[maxn],b[maxn];
int q[maxn];
struct BIT{
	long long c[maxn];
	inline int lowbit(int x){
		return x&(-x);
	}
	void update(int x,int v){
		while(x<=n){
			c[x]+=v;
			c[x]%=mod;
			x+=lowbit(x);
		}
	}
	long long query(int x){
		int ans=0;
		while(x>0){
			ans+=c[x];
			ans%=mod;
			x-=lowbit(x);
		}
		return ans;
	}
}T;
long long inv_pair(int *arr){
	long long ans=0;
	for(int i=n;i>=1;i--){
		ans+=T.query(arr[i]-1);
		ans%=mod;
		T.update(arr[i],1);
	}
	return ans;
}
int main(){
//	freopen("2.in","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i].x);
		a[i].id=i;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i].x);
		b[i].id=i;
	}
	sort(a+1,a+1+n);
	sort(b+1,b+1+n);
	for(int i=1;i<=n;i++) {
		q[a[i].id]=b[i].id;	
	}
	printf("%lld\n",inv_pair(q));
}
