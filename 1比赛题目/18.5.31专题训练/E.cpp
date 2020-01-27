#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 21
#define maxt 1005
using namespace std;
int t,n;
int sum;
int edge_sum;
int a[maxn];
int used[maxn];
int ans[maxt];
int dfs(int edge_cnt,int all_sum,int this_sum,int stick_num) {
	if(edge_cnt==3&&all_sum==edge_sum*3) return 1;
	else if(edge_cnt==3) return 0;
	for(int i=stick_num; i<=n; i++) {
		if(used[i]) continue;
		if(a[i]>edge_sum) continue;
		int x=a[i]+this_sum;
		if(x>edge_sum) continue;
		used[i]=1;
		if(x==edge_sum) {
			if(dfs(edge_cnt+1,all_sum+a[i],0,1)) return 1;
		} else {
			if(dfs(edge_cnt,all_sum+a[i],this_sum+a[i],i+1)) return 1;
		}
		used[i]=0;
	}
	return 0;
}
int long_stick(int x){
//	printf("long %d\n",x);
	for(int i=1;i<=n;i++){
		if(a[i]>x) return 1; 
	}
	return 0;
} 
int main() {
	scanf("%d",&t);
	for(int cas=1;cas<=t;cas++) {
		scanf("%d",&n);
		sum=0;
		for(int i=1; i<=n; i++) {
			scanf("%d",&a[i]);
			sum+=a[i];
		}
		if(sum%4!=0) ans[cas]=0;//printf("no\n");
		else {
			edge_sum=sum/4;
			if(!long_stick(edge_sum)) {
				memset(used,0,sizeof(used));
				if(dfs(0,0,0,1)) ans[cas]=1;//printf("yes\n");
				else ans[cas]=0;//printf("no\n");
			}else{
				ans[cas]=0;//printf("no\n");
			}  
		}
	}
	for(int cas=1;cas<=t;cas++){
		if(ans[cas]==1) printf("yes\n");
		else printf("no\n");
	}
}
