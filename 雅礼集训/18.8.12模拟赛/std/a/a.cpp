#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxm=5e4+10,maxn=30+5;
int m,n,sum[maxn][maxm],l,r;
char a[maxn][maxm];

inline ll solve(int x){
	if(x<0)
		return 0;
	ll res=0;
	for(int i=0;i<n;++i)
		for(int j=i+1;j<=n;++j)
			for(int k=1,p=0;k<=m;++k){
				while(sum[j][k]-sum[j][p]-sum[i][k]+sum[i][p]>x)
					++p;
				res+=k-p;
			}
	return res;
}

int main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%s",a[i]+1);
		for(int j=1;j<=m;++j)
			sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+(a[i][j]=='1');
	}
	scanf("%d%d",&l,&r);
	printf("%lld\n",solve(r)-solve(l-1));
	return 0;
}
