#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
int n,d,k;
#define maxn 500010
ll maxv[maxn*4];
ll query(int k,int l,int r,int L,int R){
	if(l==L&&r==R)return maxv[k];
	int mid=(l+r)>>1;
	if(R<=mid)return query(k<<1,l,mid,L,R);
	else if(mid<L)return query(k<<1|1,mid+1,r,L,R);
	else return max(query(k<<1,l,mid,L,mid),query(k<<1|1,mid+1,r,mid+1,R));
}
void update(int k,int l,int r,int pos,int x){
	if(l==r){
		maxv[k]=x;
		return;
	}
	int mid=(l+r)>>1;
	if(pos<=mid)update(k<<1,l,mid,pos,x);
	else update(k<<1|1,mid+1,r,pos,x);
	maxv[k]=max(maxv[k<<1],maxv[k<<1|1]);
}
struct dd{
	int x,s;
}a[maxn];
ll f[maxn];
bool check(int x){
	int high=d+x,low=max(1,d-x);
	f[0]=0;
	int l=0,r=0;
	for(int i=1;i<=n;++i){
		if(l>r)continue;
		ll now=query(1,0,n,l,r);
		f[i]=now+a[i].s;
		if(f[i]>=k)return true;
		update(1,0,n,i,f[i]);
		if(i!=n){
			while(a[i+1].x-a[l].x>high)l++;
			while(a[i+1].x-a[r+1].x>=low)r++;
		}
	}
	return false;
}
int main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d%d%d",&n,&d,&k);
	int l=0,r;
	for(int i=1;i<=n;++i){
		scanf("%d%d",&a[i].x,&a[i].s);
	}
	r=a[n].x+1;
	while(l!=r){
		int mid=(l+r)>>1;
		if(check(mid))r=mid;
		else l=mid+1;
	}
	if(l!=a[n].x+1)printf("%d\n",l);
	else puts("-1");
	return 0;
}/*
7 4 10
2 6
5 -3
10 3
11 -3
13 1
17 6
20 2
*/
