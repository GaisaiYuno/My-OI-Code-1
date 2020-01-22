#include<bits/stdc++.h>
using namespace std;

int m,d,p,a[500010],x,y,mx;
long long dp[500010];

int main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d%d%d",&m,&d,&p);
	scanf("%d%d",&x,&y),a[x]=y;
	int wxp1=abs(x-d);
	for(int i=2;i<=m;i++) scanf("%d%d",&x,&y),a[x]=y,mx=max(mx,x);
	for(int i=wxp1;i<=mx-d;i++) for(int j=1;j<=mx;j++)if(a[j]) {
		int tmp=max(1,d-i),wxp=min(j,i+d);
		for(int k=tmp;k<=wxp;k++) if((dp[j-k])||(j==k)){
			dp[j]=max(dp[j],a[j]+dp[j-k]);
			if(dp[j]>=p) {
				printf("%d",i);
				return 0;
			}
		}
	}
	printf("-1");
}
