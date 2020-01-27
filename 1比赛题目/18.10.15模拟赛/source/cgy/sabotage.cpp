#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<cmath>
#include<cstring>
#include<map>
using namespace std;
#define maxn 100005
int n;
long double a[maxn];
long double sum;
long double eps=1e-6;
bool check(long double val){
	long double temp;
	long double ans=0;
	long double mx=0;
	int num=0;
	int mxnum=0;
/*	for(int i=1;i<=n;i++){
		printf("%Lf ",a[i]);
	}
	puts("");*/
	for(int i=2;i<n;i++){
		temp=a[i]-val;
		ans+=temp;
		num++;
	    if(mx<ans){
	    	mx=ans;
	    	mxnum=max(mxnum,num);
		}
		if(ans<0){
			ans=0;
			num=0;
		}
	}
//	cout<<"check"<<" "<<mx+mxnum*val<<endl;
	return ((sum-mx-mxnum*val)/(n-mxnum))<=val;
}
int main(){
	freopen("sabotage.in","r",stdin);
	freopen("sabotage.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%Lf",&a[i]);
		sum+=a[i];
	}
//	cout<<sum<<endl;
	long double lx,rx,mid;
	lx=0,rx=10000;
	while(lx+eps<rx){
		mid=(lx+rx)/2;
//		cout<<mid<<endl;
		if(check(mid)){
			rx=mid;
		}
		else{
			lx=mid;
		}
	}
	printf("%.3Lf",mid);
}
