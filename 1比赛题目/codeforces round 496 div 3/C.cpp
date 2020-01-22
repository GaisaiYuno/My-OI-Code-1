#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<algorithm>
#define maxn 120005
using namespace std;
int n;
int a[maxn];
map<int,int>cnt;
map<int,int>used;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		cnt[a[i]]++;
	}
	sort(a+1,a+1+n);
	int ans=0;
	for(int i=1;i<=n;i++){
		if(used[a[i]]) continue;
		bool flag=true;
		for(int k=30;k>=0;k--){
			int j=(1<<k);
			if(j<a[i]) break;
			if(cnt.count(j-a[i])){
				if(j-a[i]==a[i]&&cnt[j-a[i]]==1) continue;
				used[a[i]]=used[j-a[i]]=1;
				flag=false;
				break;
			}
		}
		if(flag) ans++;
	}
	printf("%d\n",ans);
}
