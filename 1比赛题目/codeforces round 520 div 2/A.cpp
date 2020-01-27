#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 1005
using namespace std;
int n;
int a[maxn]; 
int mark[maxn];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(a[i]==i) ans=max(ans,i-1);
		if(a[i]==1000-(n-i)) ans=max(ans,n-i);
		for(int j=i+2;j<=n;j++){
			if(a[i]-a[j]+1==i-j+1){
				ans=max(ans,j-i-1);
			}
		}
	}
	printf("%d\n",ans);
}
