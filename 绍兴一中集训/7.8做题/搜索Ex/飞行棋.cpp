#include<iostream>
//https://www.luogu.org/problemnew/show/P2165
#include<cstdio>
#include<cstring>
#define maxn 20 
using namespace std;
int n;
int a[maxn+5];
int sum[maxn+5];
int get_dist(int x,int y){
	if(x<y) swap(x,y);
	int d=sum[x]-sum[y];
	return min(d,sum[n]-d);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum[i]=sum[i-1]+a[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				for(int u=k+1;u<=n;u++){
					if(get_dist(i,j)==get_dist(k,u)&&get_dist(j,k)==get_dist(i,u)){
						ans++;
					}
				}
			}
		}
	}
	printf("%d\n",ans);
}
