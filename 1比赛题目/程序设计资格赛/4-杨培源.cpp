//度度熊的午饭时光
#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 1000
using namespace std;
int s[maxn],c[maxn];
int f[maxn];
bool ans[maxn]= {false};
int main() {
	int t,b,n;
	cin>>t;
	for(int a=1; a<=t; a++) {
		int cost;
		cin>>b>>n;
		for(int k=1; k<=n; k++) {
			cin>>s[k]>>c[k];
		}
		cost=0;
		memset(ans,false,sizeof(ans));
		for(int i=1; i<=n; i++) {
			for(int v=b; v>=c[i]; v--) {
				if(f[v-c[i]]+s[i]>f[v]) {
					f[v]=f[v-c[i]]+s[i];
					ans[i]=true;
					cost+=c[i];
					/*if(cost>b) {
						cost-=c[i];
						ans[i]=false;
						break;
					}*/
				}
			}
		}
		printf("Case #%d:\n",a);
		cout<<f[b]<<' '<<cost<<endl;
		if(f[b]!=0&&cost!=0) {
			for(int i=1; i<=n; i++) if(ans[i]) cout<<i<<' ';
		}
	}
	return 0;
}

