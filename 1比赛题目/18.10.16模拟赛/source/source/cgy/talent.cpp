#include<iostream>
#include<cstdio>
#include<queue>
#include<cmath>
#include<algorithm>
#include<map>
#include<cstring>
using namespace std;
#define maxn 255
#define maxx 10005
#define inf 10000000
int n,k;
const long double eps=1e-6;
struct node{
	long double w;
	long double t;
}cow[maxn];
long double dp[maxx];
bool check(long double val){
    for(int i=1;i<=k;i++)dp[i]=-inf;
    dp[0]=0;
    for(int i=1;i<=n;i++){
    	for(int j=k;j>=0;j--){
    		int temp=j+cow[i].w;
    		if(temp>k)temp=k;
//    		if(dp[j])
   //         cout<<dp[j]+cow[i].t-val*cow[i].w<<endl;
//            cout<<dp[j]<<endl;
    		dp[temp]=max(dp[temp],dp[j]+cow[i].t-val*cow[i].w);
//    		cout<<dp[k]<<endl;
		}
	}
//	cout<<dp[k]<<endl;
	return dp[k]>0;
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%Lf%Lf",&cow[i].w,&cow[i].t);
//		printf("%f %f\n",cow[i].w,cow[i].t);
	}
//	sort(cow+1,cow+n+1,cmp);
	long double lx,rx,mid;
	lx=0,rx=1000005;
//	cout<<"check"<<endl;
	while(lx+eps<rx){
		mid=(lx+rx)/2;
//		cout<<lx<<" "<<rx<<endl;
//		cout<<"check"<<endl;                                        
//		cout<<mid<<endl;
		if(check(mid)){
			lx=mid;
		}
		else{
			rx=mid;
		}
	}
	cout<<(int)floor(lx*1000.0); 
//	cout<<(int)(lx*1000);
}
