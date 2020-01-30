#include<iostream>
#include<cstdio>
#define maxn 100000
using namespace std;
int t;
int n,x;
int s[maxn+5],cnt0[maxn+5],cnt1[maxn+5],d[maxn+5];
int main() {
	scanf("%d",&t);
	while(t--) {
		scanf("%d %d",&n,&x);
		for(int i=1; i<=n; i++) {
			scanf("%1d",&s[i]);
			cnt0[i]=cnt0[i-1]+(s[i]==0);
			cnt1[i]=cnt1[i-1]+(s[i]==1);
			d[i]=cnt0[i]-cnt1[i];
		}
		int ans=0;
		if(d[n]==0) {
			for(int i=1; i<=n; i++) if(d[i]==x) ans++;
			if(ans!=0) printf("-1\n");
			else printf("0\n");
		}else if(d[n]>0){
			for(int i=1;i<=n;i++){
				if(x>=d[i]&&(x-d[i])%d[n]==0) ans++;
			}
			ans+=(x==0);
			printf("%d\n",ans);
		}else{
			for(int i=1;i<=n;i++){
				if(x<=d[i]&&(x-d[i])%d[n]==0) ans++;
			}
			ans+=(x==0);
			printf("%d\n",ans);
		}
	}
}

