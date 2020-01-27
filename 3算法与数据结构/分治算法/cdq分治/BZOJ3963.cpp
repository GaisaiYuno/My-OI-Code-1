//http://119.29.55.79/contest/84/problem/4
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define INF 0x3f3f3f3f3f3f3f3f
#define maxn 100000
#define eps 1e-7
using namespace std;
typedef long long ll;
int T;
int n,C,m;
struct input{
	ll d,p,r,g;
	friend bool operator < (input p,input q){
		return p.d<q.d;
	}
}in[maxn+5];
ll D[maxn+5],P[maxn+5],R[maxn+5],G[maxn+5];
ll dp[maxn+5];

struct Vector{
	int id;
	double x;
	double y;
	Vector(){
		
	}
	Vector(int _id,double _x,double _y){
		id=_id; 
		x=_x;
		y=_y;
	}
}a[maxn+5];
typedef Vector point;
double slope(point p,point q){
	double down=p.x-q.x;
	double up=p.y-q.y;
	if(fabs(down)<=eps) return INF;
	else return up/down;
}

int cmp1(point p,point q){
	return -D[p.id]<-D[q.id];
}
int cmp2(point p,point q){
	if(p.x==q.x) return p.y<q.y;
	else return p.x<q.x;
}

int head,tail;
point q[maxn+5];
point tmp[maxn+5];

void cdq_divide(int l,int r){
	if(l==r){
		int j=a[l].id;
		a[l].x=G[j];
		a[l].y=dp[j]-D[j]*G[j]+R[j];
		return;
	}
	int mid=(l+r)>>1;
	int pl=l,pr=mid+1;
	for(int i=l;i<=r;i++){//按编号分类，编号小的先更新，放在左边 
		if(a[i].id<=mid) tmp[pl++]=a[i];
		else tmp[pr++]=a[i]; 
	}
	for(int i=l;i<=r;i++) a[i]=tmp[i];
	
	cdq_divide(l,mid);

	head=1,tail=0;
	for(int i=l;i<=mid;i++){
		if(dp[a[i].id]<0) continue;
		while(head<tail&&slope(q[tail-1],q[tail])<=slope(q[tail-1],a[i])) tail--;
		q[++tail]=a[i];
	} 

	for(int k=r;k>mid;k--){
		int i=a[k].id;
		while(head<tail&&slope(q[head],q[head+1])>=-D[i]+1) head++;
		int j=q[head].id;
		dp[i]=max(dp[i],dp[j]+(D[i]-D[j]-1)*G[j]-P[i]+R[j]);
	} 
	cdq_divide(mid+1,r);
	
	int num=l-1;
	pl=l,pr=mid+1;
	while(pl<=mid&&pr<=r){ 
		if(cmp2(a[pl],a[pr])) tmp[++num]=a[pl++];
		else tmp[++num]=a[pr++];
	}  
	while(pl<=mid) tmp[++num]=a[pl++];
	while(pr<=r) tmp[++num]=a[pr++];
	for(int i=l;i<=r;i++) a[i]=tmp[i];
}

void ini(){
	memset(in,0,sizeof(in));
	memset(D,0,sizeof(D));
	memset(P,0,sizeof(P));
	memset(dp,0,sizeof(dp));
	memset(G,0,sizeof(G));
	memset(R,0,sizeof(R));
}
int main(){
	int cas=0;
#ifdef LOCAL
	freopen("1.in","r",stdin);
	freopen("1.ans","w",stdout); 
#endif
	while(scanf("%d %d %d",&n,&C,&m)!=EOF){
		cas++;
		if(n==0) break;
		ini();
		for(int i=1;i<=n;i++){
			scanf("%lld %lld %lld %lld",&in[i].d,&in[i].p,&in[i].r,&in[i].g); 
		}
		sort(in+1,in+1+n);
		for(int i=1;i<=n;i++){
			D[i]=in[i].d;
			P[i]=in[i].p;
			R[i]=in[i].r;
			G[i]=in[i].g;
		}
		D[n+1]=m+1;
		dp[0]=C;
		for(int i=1;i<=n+1;i++) dp[i]=-INF;
		for(int i=0;i<=n+1;i++){
			a[i].id=i;
			a[i].x=0;
			a[i].y=0;
		}
		sort(a+1,a+1+n+1,cmp1);
		cdq_divide(0,n+1);
		ll ans=0;
		for(int i=0;i<=n+1;i++){
//			printf("%lld ",dp[i]);
			 ans=max(ans,dp[i]);
		}
		printf("Case %d: %lld\n",cas,ans);
	}
}
