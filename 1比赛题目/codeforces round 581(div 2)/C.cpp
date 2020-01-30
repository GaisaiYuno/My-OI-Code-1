#include<iostream>
#include<cstdio>
#include<cstring> 
#include<vector>
#define maxn 100
#define maxm 1000000
#define INF 0x3f3f3f3f
using namespace std;
int n,m;
int a[maxm+5];
int g[maxn+5][maxn+5];
int dist[maxn+5][maxn+5];
void floyd(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(dist[i][k]!=INF&&dist[k][j]!=INF){
					dist[i][j]=min(dist[i][k]+dist[k][j],dist[i][j]);
				}
			}
		}
	}
}
vector<int>ans;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%1d",&g[i][j]);
			if(g[i][j]==0) g[i][j]=INF; 
		}
	}
	memcpy(dist,g,sizeof(g));
	floyd();
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=m;i++){
		if(i-1>0&&i+1<=m){
			int x=a[i-1];
			int y=a[i];
			int z=a[i+1];
			if(x!=z&&dist[x][z]==dist[x][y]+dist[y][z]) continue;
			else ans.push_back(y); 
		}else ans.push_back(a[i]);
	}
	printf("%d\n",ans.size());
	for(int x : ans) printf("%d ",x);
}

