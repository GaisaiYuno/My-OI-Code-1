#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define maxn 10005
#define pi 3.141592653589
#define eps 0.000001
using namespace std;
int t,n,f;
int ra[maxn];
double s[maxn];
int is_ok(double x){
	int cnt=0;
	for(int i=1;i<=n;i++){
		cnt+=(int)(s[i]/x);
	}
	if(cnt>f) return 1;
	else return 0;
} 
int main(){
//	freopen("pie.in","r",stdin); 
	scanf("%d",&t);
	for(int cas=1;cas<=t;cas++){
		scanf("%d %d",&n,&f);
		for(int i=1;i<=n;i++){
			scanf("%d",&ra[i]);
			s[i]=(double)ra[i]*ra[i];
		}
		double l=0.0000001,r=maxn*maxn;
		double ans=0;
		while(fabs(l-r)>eps){
			double mid=(l+r)/2;
			if(is_ok(mid)){
				l=mid+eps;
				ans=max(ans,mid);  
			}else r=mid-eps;
		} 
//		printf("%lf\n",ans);
		printf("%lf\n",ans*pi);
	}
}
/*
1
1 1
9767

*/
