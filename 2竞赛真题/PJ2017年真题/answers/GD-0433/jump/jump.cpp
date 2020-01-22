#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int n,d,k,sum,mx,x[505000],s[505000],dp[505000],i,j,g;
int main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d%d%d",&n,&d,&k);
	for(i=1;i<=n;i++){
		scanf("%d%d",&x[i],&s[i]);
		if(s[i]>0)sum+=s[i];
		if(x[i]>mx)mx=x[i];
	}
	if(sum<k){
		printf("-1");
		return 0;
	}
	int f=d,p=0,q=0,r=-505000;
	while(f<=mx){
		while(x[q]<f)q++;
		if(x[q]>f)break;
		else {
			p+=s[q];	r=max(r,p);
		}
		f+=d;
	}
	if(f==mx+d&&r>=k){
		printf("0");
		return 0;
	}
	long long l=1;r=mx;
	while(l<r){
		g=(l+r)/2;
		for(i=1;i<=n;i++)dp[i]=-1e9;
		int p=-505000,b=max(1,d-g),t=d+g;
		dp[0]=0;
		for(i=0;i<=n;i++){
			if(dp[i]==-1e9)continue;
			for(j=i+1;j<=n&&x[j]<=x[i]+t;j++){
				if(x[j]>=x[i]+b){
					dp[j]=max(dp[j],dp[i]+s[j]);
					p=max(p,dp[j]);
				}
			}
		}
		if(p>=k)r=g;
		else l=g+1;
	}
	printf("%d",l);
}
