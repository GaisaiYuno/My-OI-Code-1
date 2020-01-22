#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define maxn 200005
using namespace std;
int a[maxn],d[maxn];
int n,k;
int main(){
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	int same=0; 
	int ans=n; 
	for(int i=1;i<=n-1;i++){
		while(a[i]==a[i+1]){
			same++;
			i++;
			if(i==n){
				printf("%d\n",ans);
				return 0;
			}
			if(a[i]!=a[i+1]) break;
		}
		same++;
		if(a[i+1]-a[i]<=k) ans-=same;
		same=0;
	}
	printf("%d\n",ans);
}
