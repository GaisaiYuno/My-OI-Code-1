#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>
#include<queue>
#include<bitset>
#define maxn 2000
using namespace std;
int n;
int d[maxn+5][maxn+5];

bitset<maxn>f[maxn+5];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%1d",&d[i][j]);
			if(d[i][j]==1) f[i][j]=1;
		}
		f[i][i]=1;
	}

	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(f[j][i]){
				f[j]|=f[i];
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++) ans+=f[i].count();
	printf("%d\n",ans);
}
