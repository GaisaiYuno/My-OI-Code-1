//洛谷 平面上的最接近点对 1257
//分治优化 O(n*log2 n) 
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define maxn 100000
const int INF=2<<20;
using namespace std;
struct dot{
	int x;
	int y;
}a[maxn];
int n;
double ans=0;
int comp(dot p,dot q){
	if(p.x>q.x)  return 0;
	else if(p.x<q.x)  return 1;
	else if(p.y<q.y)  return 1;
    else return 0;
}
double dist(int x1,int y1,int x2,int y2){
//	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	double u=(x1-x2)*(x1-x2);
    double v=(y1-y2)*(y1-y2);     
    return sqrt(u+v);
	
} 


//double merge(int l,int r,int distl,int distr){
double merge(int l,int r,double distl,double distr){
    int mid=(l+r)/2;  
 //   int d=min(distl,distr);
      double d=min(distl,distr);
      
      
   // for(int i=l;i<mid-1;i++) {
    	for(int i=l;i<=mid;i++) {   //  原来 i<mid，改为 i<=mid
   	    if(abs(a[mid+1].x-a[i].x)>=d||abs(a[mid+1].y-a[i].y)>=d) continue;
   	    else{
   	   	     if(dist(a[mid+1].x,a[mid+1].y,a[i].x,a[i].y)<d) 
				   d=dist(a[mid+1].x,a[mid+1].y,a[i].x,a[i].y);
		}
	}
	for(int i=mid+1;i<=r;i++) {
   	    if(abs(a[mid].x-a[i].x)>=d||abs(a[mid].y-a[i].y)>=d) continue;
   	    else{
   	   	     if(dist(a[mid].x,a[mid].y,a[i].x,a[i].y)<d) //  原来 a[mid-1]，改为 a[mid]
				   d=dist(a[mid].x,a[mid].y,a[i].x,a[i].y);   //  原来 a[mid-1]，改为 a[mid]
		}
	}
	return d;	 	 
}
double divd(int l,int r){
	if(l==r) {
	//	return 1000000;
			return INF;
	} 	   
	if(abs(l-r)==1){
       return dist(a[l].x,a[l].y,a[r].x,a[r].y); 
	} 
	int mid=(l+r)/2;
	//divd(l,mid);
	//divd(mid,r);
	ans=merge(l,r,divd(l,mid),divd(mid+1,r));	
}
int main(){
	cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i].x>>a[i].y;
    }
    sort(a,a+n,comp);
    divd(0,n-1);
    printf("%.4f",ans);
    return 0;
} 
