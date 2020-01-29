#include<iostream>
#include<cstdio>
#define maxn 300000
#define maxm 8
using namespace std;
int n,m;
int a[maxn+5][maxm+5];
bool check(int mid,bool print_ans){
	static int vis[(1<<maxm)+5];
	for(int i=0;i<(1<<m);i++) vis[i]=0;
	for(int i=1;i<=n;i++){
		int b=0;
		for(int j=1;j<=m;j++){
			if(a[i][j]>=mid) b=b<<1|1;
			else b=b<<1;
		}
		vis[b]=i;
	}
	for(int i=0;i<(1<<m);i++){
		if(!vis[i]) continue;
		for(int j=0;j<(1<<m);j++){
			if(!vis[j]) continue;
			if((i|j)==((1<<m)-1)){
				if(print_ans) printf("%d %d\n",vis[i],vis[j]);
				return 1;
			}
		}
	}
	return 0;
}

int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) scanf("%d",&a[i][j]);
	}
	int l=0,r=1e9,mid,ans=0;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid,0)){
			ans=mid;
			l=mid+1;
		}else r=mid-1;
	}
//	printf("db: %d\n",ans); 
	check(ans,1);
}

