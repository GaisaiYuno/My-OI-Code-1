#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
struct data{
	int x;
	int s;
};
data a[501000];
int n,d;long long k;
int l=0,r,mid;
long long maxs;
long long f[501000];
bool check(int g){
	for(int i=1;i<=n;++i) f[i]=-0x7fffffff;
	long long maxsum=0;
	f[0]=0;
	for(register int i=1;i<=n;++i){
		register int j;
		int ll=0,rr=i;
		while(ll<rr){
			j=(ll+rr)/2;
			if(a[i].x-a[j].x<d-g) rr=j;
			else ll=j+1;
		}
		while(a[i].x-a[j].x<=d+g&&j>-1){
			if(a[i].x-a[j].x>=d-g) f[i]=max(f[i],f[j]);
			--j;
		}
		f[i]+=a[i].s;
		if(f[i]>k)  return 1;
	}
	return 0;
}
int main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	cin>>n>>d>>k;
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i].x);
		scanf("%d",&a[i].s);
		r=max(r,a[i].x);
		maxs+=max(0,a[i].s);
	}
	if(maxs<k){
		cout<<-1;
		return 0;
	}
	while(l<r){
		mid=(l+r)/2;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	cout<<l;
	return 0;
}
