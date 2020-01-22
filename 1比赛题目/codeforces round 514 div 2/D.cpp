#include<iostream>
#include<cstdio>
#include<cmath>
#define eps 1e-7
#define maxn 100005
using namespace std;
struct point{
	int x;
	int y;
}a[maxn];
struct seg{
	long double l;
	long double r;
	seg(){
		
	}
	seg(long double L,long double R){
		l=L;
		r=R;
	}
	friend bool operator == (seg a,seg b){
		return a.l==b.l&&a.r==b.r;
	}
	friend seg operator + (seg a,seg b){
		if(a.l>b.l) swap(a,b);
		if(a.r>=b.l) return seg(b.l,a.r);
		else return seg(1,0);
	}
};
int n;
int check(long double r){
	long double t,d;
	seg tmp=seg(1e16,1e16);
	for(int i=1;i<=n;i++){
		t=fabs(r-a[i].y);
		if(t>r) return 0;
		d=sqrt(r*r-t*t);
		if(tmp==seg(1e16,1e16)) tmp=seg(a[i].x-d,a[i].x+d);
		else tmp=tmp+seg(a[i].x-d,a[i].x+d);
	}
	if(tmp==seg(1,0)) return 0;
	else return 1;
}
long double bin_search(){
	long double l=0,r=1e2;
	long double mid;
	long double ans=-1;
	while(fabs(r-l)>eps){
		mid=(l+r)/2;
		if(check(mid)) {
			ans=mid;
			r=mid-eps;	
		}
		else l=mid+eps;
	} 
	return ans;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d %d",&a[i].x,&a[i].y);
	}
	long double t=bin_search();
	if(t!=-1) printf("%.6Lf",t);
	else printf("-1");
}
