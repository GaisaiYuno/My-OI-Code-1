#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map> 
#define maxn 10000
using namespace std;
int t;
int n,s,k;
map<int,int>vis;
int a[maxn+5];
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d %d %d",&n,&s,&k);
		vis.clear();
		for(int i=1;i<=k;i++){
			scanf("%d",&a[i]);
			vis[a[i]]=1;
		} 
		int ans=n;
		for(int i=s;i<=n;i++){
			if(!vis.count(i)){
				ans=min(ans,i-s);
				break;
			}
		}
		for(int i=s;i>=1;i--){
			if(!vis.count(i)){
				ans=min(ans,s-i);
				break;
			}
		}
		printf("%d\n",ans);
	}
}

