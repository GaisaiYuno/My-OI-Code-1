#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define maxn 1005
using namespace std;
int n;
const double pi=acos(-1.0);
struct point{
	long long x;
	long long y;
	point(){
		
	}
	point(long long xx,long long yy){
		x=xx;
		y=yy;
	}
};
double dist(point a,point b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
struct circle{
	point O;
	long long r;
	friend bool operator < (circle x,circle y){
		return x.r>y.r;
	}
}a[maxn];
 
int is_in(circle x,circle y){
	if(dist(x.O,y.O)<=y.r-x.r) return 1;
	else return 0;
} 
int cover[maxn];
int main(){
//	freopen("dance.in","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld %lld %lld",&a[i].O.x,&a[i].O.y,&a[i].r);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[j].r>a[i].r&&is_in(a[i],a[j])) cover[i]++;
		}
	}
	long long ans=0;
	for(int i=1;i<=n;i++){
		if(cover[i]==0) ans+=(long long)a[i].r*a[i].r;
		else if(cover[i]%2==1) ans+=(long long)a[i].r*a[i].r;
		else ans-=(long long)a[i].r*a[i].r;
	}
	double sum=ans*pi;
	printf("%.8f",sum);
}
