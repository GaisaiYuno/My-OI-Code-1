#include<iostream>
#define maxn 1005
#define maxm 100005
int a[maxn];
int c[maxn];
int f[maxm];
using namespace std;
void bag_01(int n,int v) { //01背包
	for(int i=0; i<n; i++) {
		for(int j=v; j>=a[i]; j--)
			f[j]=max(f[j],f[j-a[i]]+a[i]);
	}
}
void bag_all(int n,int v) { //完全背包
	for(int i=0; i<n; i++) {
		for(int j=a[i]; j<=v; j++)
			f[j]=max(f[j],f[j-a[i]]+a[i]);
	}
}
int main() {
	int n,m;
	while(1) {
		cin>>n>>m;
		if(n==0&&m==0) break;
		for(int i=0; i<n; i++) cin>>a[i];
		for(int i=0; i<n; i++) cin>>c[i];
		for(int i=0; i<n; i++) {
			if(a[i]*c[i]>m) {
				bag_all(a[i],c[i]);
				break;
			}
		    else {
			   for(int k=0; k<n; k++) {
				   bag_01(k*a[i],k*c[i]);
			   }
			   break;
		   }
		}
		cout<<f[m]<<endl;
	}
	return 0;
}
