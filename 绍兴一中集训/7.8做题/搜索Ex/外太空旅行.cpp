//https://www.luogu.org/problemnew/show/P4212
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#define maxn 50
#define maxtim 10000
using namespace std;
int n;
int a[maxn+5];
int top=0;
int s[maxn+5];
int g[maxn+5][maxn+5];
bool check(int x){
	for(int i=1;i<=top;i++){
		if(!g[x][s[i]]) return 0;
	}
	return 1;
}
int main(){
	srand(time(NULL));
	int u,v;
	scanf("%d",&n);
	while(scanf("%d %d",&u,&v)!=EOF&&u!=0&&v!=0){
		g[u][v]=g[v][u]=1;
	}
	for(int i=1;i<=n;i++) a[i]=i;
	int ans=0;
	for(int i=1;i<=maxtim;i++){
		random_shuffle(a+1,a+1+n);
		top=0;
		s[++top]=a[1];
		for(int j=2;j<=n;j++){
			if(check(a[j])){
				s[++top]=a[j];
			}
		}
		ans=max(ans,top);
	}
	printf("%d\n",ans);
}
