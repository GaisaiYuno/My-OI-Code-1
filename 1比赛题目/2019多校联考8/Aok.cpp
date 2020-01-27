#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm> 
#define maxn 100005
using namespace std;
typedef long long ll;
int n;
ll X;
ll tot;
struct node{
	ll l;
	ll r;
	ll b;
	ll s;
	friend bool operator < (node p,node q){
		return p.s>q.s;
	}
}a[maxn+5];
ll calc(int id,ll t){
	if(t<=a[id].b) return t*a[id].l;
	else return a[id].b*a[id].l+(t-a[id].b)*a[id].r;
} 

bool check(ll mid){
	ll ans=0,sum=0;
	int cnt=mid/X;
	ll rest=mid%X;
	for(int i=1;i<=cnt;i++) sum+=a[i].s;
	//ö������ĵ÷�Ϊmid%x,
	for(int i=cnt+1;i<=n;i++){
		//������cnt�������  
		ans=max(ans,sum+calc(i,rest));
	} 
	for(int i=1;i<=cnt;i++){
		//Ҳ������ǰcnt�����ʱ��Ҫ��ѡ��cnt+1�� 
		ans=max(ans,sum+a[cnt+1].s-a[i].s+calc(i,rest)); 
	} 
	return ans>=tot;
}
int main(){
	scanf("%d %lld",&n,&X);
	for(int i=1;i<=n;i++){
		scanf("%lld %lld %lld",&a[i].b,&a[i].l,&a[i].r);
		a[i].s=calc(i,X);
		tot+=a[i].l*a[i].b;
	} 
	sort(a+1,a+1+n);
	ll l=1,r=n*X,mid;
	ll ans=0;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid)){
			ans=mid;
			r=mid-1;
		}else l=mid+1;
	}
	printf("%lld\n",ans);
}

