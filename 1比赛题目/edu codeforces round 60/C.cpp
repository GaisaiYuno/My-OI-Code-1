#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100005
#define INF 1e18
//#define int long long
int n;
char a[maxn];
struct point{
	long long x;
	long long y;
	point(){
		
	}
	point(long long xx,long long yy){
		x=xx;
		y=yy;
	}
	friend point operator + (point p,point q){
		return point(p.x+q.x,p.y+q.y);
	} 
	friend point operator - (point p,point q){
		return point(p.x-q.x,p.y-q.y);
	} 
	friend point operator * (point p,long long v){
		return point(p.x*v,p.y*v);
	} 
};
typedef point vector;
point s,t;
vector dir[maxn];
long long abs(long long p){
	return p>=0?p:-p;
}
bool check(long long mid){
	point p=s+dir[n]*(mid/n)+dir[mid%n];
	vector delta=t-p;
	if(abs(delta.x)+abs(delta.y)<=mid) return 1;
	else return 0;
}
//#undef int
int main(){
//#define int long long
	scanf("%I64d %I64d %I64d %I64d",&s.x,&s.y,&t.x,&t.y);
	scanf("%d",&n);
	scanf("%s",a);
	vector tmp=vector(0,0);
	dir[0]=tmp;
	for(int i=0;i<n;i++){
		if(a[i]=='U') tmp.y++; 
		else if(a[i]=='D') tmp.y--;
		else if(a[i]=='L') tmp.x--;
		else if(a[i]=='R') tmp.x++;
		dir[i+1]=tmp;
	} 
	long long l=0,r=1e18,mid,ans=-1;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid)){
			ans=mid;
			r=mid-1;
		}else l=mid+1;
	}
	printf("%I64d\n",ans);
}

