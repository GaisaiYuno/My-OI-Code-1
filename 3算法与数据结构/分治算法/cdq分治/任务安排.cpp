//http://119.29.55.79/contest/84/problem/2 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath> 
#define eps 1e-9
#define INF 1e19
#define maxn 1000000
using namespace std;
typedef long long ll; 
int n;
ll S;
ll c[maxn+5];
ll t[maxn+5];
ll sumc[maxn+5];
ll sumt[maxn+5];
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
	return sumt[p.id]<sumt[q.id];//按sumt排序，保证斜率单调	
}
int cmp2(point p,point q){//按x,y归并排序 
	if(p.x==q.x) return p.y<q.y;
	else return p.x<q.x;
}

int head,tail;
point q[maxn+5];
point tmp[maxn+5];
ll dp[maxn+5];

void cdq_divide(int l,int r){
	if(l==r){
		a[l].x=sumc[a[l].id];
		a[l].y=dp[a[l].id];
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
	//cdq得到[l,mid]的dp值后，建出凸壳
	head=1,tail=0;
	for(int i=l;i<=mid;i++){
		while(head<tail&&slope(q[tail-1],q[tail])>slope(q[tail-1],a[i])) tail--;
		q[++tail]=a[i];
	} 
	//更新[mid+1,r]的dp值
	for(int k=mid+1;k<=r;k++){
		int i=a[k].id;
		while(head<tail&&slope(q[head],q[head+1])<S+sumt[i]) head++;//注意不是sumt[i],因为一开始按sumt排过序
		int j=q[head].id; 
		dp[i]=min(dp[i],dp[j]+sumt[i]*(sumc[i]-sumc[j])+S*(sumc[n]-sumc[j]));
	} 
	cdq_divide(mid+1,r);//继续向右cdq
	
	int num=l-1;
	pl=l,pr=mid+1;
	while(pl<=mid&&pr<=r){//按x,y归并排序 
		if(cmp2(a[pl],a[pr])) tmp[++num]=a[pl++];
		else tmp[++num]=a[pr++];
	}  
	while(pl<=mid) tmp[++num]=a[pl++];
	while(pr<=r) tmp[++num]=a[pr++];
	for(int i=l;i<=r;i++) a[i]=tmp[i];
}

int main(){
	scanf("%d %lld",&n,&S);
	for(int i=1;i<=n;i++){
		scanf("%lld %lld",&t[i],&c[i]);
	} 
	for(int i=1;i<=n;i++){
		sumt[i]=sumt[i-1]+t[i];
		sumc[i]=sumc[i-1]+c[i];
	}
	for(int i=0;i<=n;i++) a[i].id=i;
	sort(a+1,a+1+n,cmp1);
	memset(dp,0x3f,sizeof(dp));
	dp[0]=0; 
	cdq_divide(0,n);//要把0算进去 
	printf("%lld\n",dp[n]);
} 
