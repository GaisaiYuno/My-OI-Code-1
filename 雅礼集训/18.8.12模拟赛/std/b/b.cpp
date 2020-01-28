#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
const int maxn=20+2,maxm=1e5+10,mod=1e9+7;
int n,m,a[maxn][maxm],res[maxm],ans;
 
int main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1,x;i<=n;++i)
		for(int j=1;j<=m;++j){
			scanf("%d",&x);
			++a[i][x];
		}
	for(int i=1;i<=n;++i)
		for(int j=1;j<maxm;++j)
			for(int k=j+j;k<maxm;k+=j)
				(a[i][j]+=a[i][k])%=mod;
	for(int i=1;i<maxm;++i){
		res[i]=1;
		for(int j=1;j<=n;++j)
			res[i]=(ll)res[i]*(a[j][i]+1)%mod;
		res[i]=(res[i]+mod-1)%mod;
	}
	for(int i=maxm-1;i;--i)
		for(int j=i+i;j<maxm;j+=i)
			res[i]=(res[i]+mod-res[j])%mod;
	for(int i=1;i<maxm;++i)
		ans=(ans+(ll)res[i]*i)%mod;
	printf("%d\n",ans);
	return 0;
} 
