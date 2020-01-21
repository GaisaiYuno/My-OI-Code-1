//http://119.29.55.79/contest/84/problem/3 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath> 
#define eps 1e-8
#define INF 1e18
#define maxn 100000
using namespace std;
typedef long long ll; 
typedef double db;
int n;
db S;
db A[maxn+5],B[maxn+5],R[maxn+5];
struct Vector{
	int id;
	db x;
	db y;
	Vector(){
		
	}
	Vector(int _id,db _x,db _y){
		id=_id; 
		x=_x;
		y=_y;
	}
}a[maxn+5];
typedef Vector point;
db slope(point p,point q){
	db down=p.x-q.x;
	db up=p.y-q.y;
	if(fabsl(down)<=eps) return INF;
	else return up/down;
}

int cmp1(point p,point q){
	db k1=(fabs(A[p.id])>eps)?-B[p.id]/A[p.id]:INF;
	db k2=(fabs(A[q.id])>eps)?-B[q.id]/A[q.id]:INF;
	return k1<k2;//按斜率排序，保证斜率单调	
}
int cmp2(point p,point q){//按x,y归并排序 
	if(p.x==q.x) return p.y<q.y;
	else return p.x<q.x;
}

int head,tail;
point q[maxn+5];
point tmp[maxn+5];
db dp[maxn+5];

db get_x(int j){
	return dp[j]/(A[j]*R[j]+B[j]);
}
db get_y(int j){
	return dp[j]*R[j]/(A[j]*R[j]+B[j]);
}
void cdq_divide(int l,int r){
	if(l==r){
		dp[a[l].id]=max(dp[a[l].id],dp[a[l].id-1]);
		a[l].x=get_x(a[l].id);
		a[l].y=get_y(a[l].id);
		return; 
	}
	int mid=(l+r)>>1;
	int pl=l,pr=mid+1;
	for(int i=l;i<=r;i++){
		if(a[i].id<=mid) tmp[pl++]=a[i];
		else tmp[pr++]=a[i];	
	} 
	for(int i=l;i<=r;i++) a[i]=tmp[i];
	
	cdq_divide(l,mid);
	head=1,tail=0;
	for(int i=l;i<=mid;i++){
		while(head<tail&&slope(q[tail-1],q[tail])<=slope(q[tail-1],a[i])) tail--;
		q[++tail]=a[i];
	} 
	
	for(int k=r;k>mid;k--){
		int i=a[k].id;
		db s2=(fabs(A[i])>eps)?-B[i]/A[i]:INF;
		while(head<tail&&slope(q[head],q[head+1])>=s2) head++;
		int j=q[head].id;
		dp[i]=max(dp[i],A[i]*get_y(j)+B[i]*get_x(j));
//		dp[i]=max(dp[i],dp[i-1]);
	}
	cdq_divide(mid+1,r);
	
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
	// freopen("5.in","r",stdin); 
	scanf("%d %lf",&n,&S);
	for(int i=1;i<=n;i++){
		scanf("%lf %lf %lf",&A[i],&B[i],&R[i]);
	}
	dp[0]=S;
	for(int i=0;i<=n;i++){
		a[i].id=i; 
	}
	sort(a,a+1+n,cmp1);
	cdq_divide(0,n);
	printf("%.3lf\n",dp[n]); 
} 
