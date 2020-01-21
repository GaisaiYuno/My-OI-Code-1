//洛谷 导弹拦截 
#include<iostream>
#include<algorithm>
//#include<cmath> 
#define maxn 100000
using namespace std;
struct missle{
	int x;
	int y;
	int dis;//表示导弹与系统1距离的平方 
}a[maxn];
int x1,yl,x2,y2,n,ans=100000,d1,d2; 
//用yl 而不是y1是因为y1是某个库函数中的变量名 
int dist(int xa,int ya,int xb,int yb){
	return (xa-xb)*(xa-xb)+(ya-yb)*(ya-yb);
}
int comp(missle p,missle q){
	return p.dis>q.dis;
}
int main(){
	cin>>x1>>yl>>x2>>y2;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i].x>>a[i].y; 
		a[i].dis=dist(a[i].x,a[i].y,x1,yl);
	}
	sort(a,a+n,comp);
	d1=a[0].dis;
	d2=0;
	ans=d1;
	for(int j=1;j<=n;j++){
		d1=a[j].dis;
		d2=max(dist(a[j-1].x,a[j-1].y,x2,y2),d2);
		ans=min(ans,d1+d2);
	}
	cout<<ans;
	return 0;
} 
