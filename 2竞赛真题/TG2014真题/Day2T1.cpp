#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 205
using namespace std;
int n,d;
int a[maxn][maxn];
int x[maxn];
int y[maxn];
int k[maxn];
int main(){
	scanf("%d %d",&d,&n);
	for(int i=1;i<=n;i++){
		scanf("%d %d %d",&x[i],&y[i],&k[i]);
	}
	int ans=0,sum=0,cnt=0;
	for(int i=0;i<=128;i++){
		for(int j=0;j<=128;j++){
			sum=0;
			for(int u=1;u<=n;u++){
				if(abs(x[u]-i)<=d&&abs(y[u]-j)<=d) sum+=k[u];
			}
			if(ans<sum){
				ans=sum;
				cnt=1;
			}else if(ans==sum){
				cnt++;
			}
		}
	}
	printf("%d %d\n",cnt,ans);
}
