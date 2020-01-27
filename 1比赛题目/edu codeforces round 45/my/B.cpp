#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 200005
using namespace std;
int a[maxn],d[maxn];
int n,k;
int main(){
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	int ans=0;
	for(int i=1;i<n;i++){
		d[i]=a[i+1]-a[i];
	}
	int i=1;
	int is_x=0; 
	while(i<n){
		if(d[i]<=k){
			int cnt=0,pre=i; 
			while(d[i]<=k&&i<n){
				if(d[i]==0) cnt++;
				i++;
			} 
			if(cnt<i-pre)ans++;
			else ans+=cnt+1;
			if(d[i+1]<=k) i++;
		}else{
			i++;
			ans++;
			is_x++;
		}
	}
	if(is_x==n-1) ans++;
	printf("%d\n",ans);
}
