#include<bits/stdc++.h>
using namespace std;

struct block{
	int w,v;
}k[500001];

long long road[500001],f[500001];

int main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	int ans=0,n,d,p,maxl=0,i;
	cin>>n>>d>>p;
	for(i=1;i<=n;i++){
		scanf("%d %d",&k[i].w,&k[i].v);
		if(k[i].v>0) ans+=k[i].v;
		maxl=max(maxl,k[i].w);
	}
	if(ans<p){
		cout<<-1;
		return 0;
	}
	for(i=0;i<=maxl-d;i++){
		for(int j=0;j<=n;j++) f[j]=-214748364;
		memset(road,0,sizeof(road));
		road[0]=1;
		f[0]=0;
		for(int j=0;j<=n;j++)if(road[j]){
			int t=j+1;
			while(t<=n){
				if(k[t].w<=k[j].w+d+i){
					if(i<d) {
						if(k[t].w>=k[j].w+d-i){
						f[t]=max(f[t],f[j]+k[t].v);
						road[t]=1;
							if(p<=f[t]) {
								cout<<i;
								return 0;
							}
						}
					}
					else {
						f[t]=max(f[t],f[j]+k[t].v);
						road[t]=1;
						if(p<=f[t]) {
							cout<<i;
							return 0;
						}
					}
				}
					t++;
			}
		}
	}
	return 0;
}
