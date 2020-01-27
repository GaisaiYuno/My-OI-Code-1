#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int t,n,m;
int a[1000005],b[1000005],c[100005];
double f(int x,int y){
	return (double)x/y+(double)y/x;
}
const double eps=1e-12;
int main() {
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		m=0;
		for(int i=1; i<=n; i++) {
			scanf("%d",&a[i]);
			c[a[i]]++;
			if(c[a[i]]>=2) {
				c[a[i]]-=2;
				b[++m]=a[i];
			}
		}
		sort(b+1,b+1+m);
		double ans=f(b[1],b[2]);
		int u=b[1],v=b[2];
		double tmp;
		for(int i=2;i<m;i++){
			tmp=f(b[i],b[i+1]);
			if(tmp<=ans-eps){
				ans=tmp;
				u=b[i];
				v=b[i+1];
			}
		}
		printf("%d %d %d %d\n",u,v,u,v);
		for(int i=1;i<=n;i++){
			c[a[i]]=0;
		}
	}
}
