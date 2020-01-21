//洛谷 排座椅  
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int m,n,l,k,d;
struct in{
	int x;
	int y;
	int p;
	int q;
}a[2000];
struct out{
	int t;//同时分开的讲话学生数 
	int num;
}b[2000],c[2000];
bool comp1(out a,out b){
	return a.t>b.t;
}
bool comp2(out a,out b){
	return a.num<b.num;
}

int main(){
	cin>>m>>n>>k>>l>>d;
	for(int i=0;i<d;i++) cin>>a[i].x>>a[i].y>>a[i].p>>a[i].q;
	for(int j=0;j<d;j++){
		if(a[j].x==a[j].p){//同一列 
		b[min(a[j].y,a[j].q)].t++;
		b[min(a[j].y,a[j].q)].num=min(a[j].y,a[j].q);
		} 
		if(a[j].y==a[j].q){//同一行 
		c[min(a[j].x,a[j].p)].t++;       
		c[min(a[j].x,a[j].p)].num=min(a[j].x,a[j].p);
		} 
	}
	sort(b+1,b+n+1,comp1);
	sort(c+1,c+m+1,comp1);
	sort(b+1,b+l+1,comp2);
	sort(c+1,c+k+1,comp2);
	int u;
	for(u=1;u<k;u++){
		if(c[u].num!=0)cout<<c[u].num<<' ';
	} 
	cout<<c[u].num<<endl;
	for(u=1;u<l;u++) {
		if(b[u].num!=0)cout<<b[u].num<<' ';
	}
	cout<<b[u].num<<endl;
	return 0;
} 
