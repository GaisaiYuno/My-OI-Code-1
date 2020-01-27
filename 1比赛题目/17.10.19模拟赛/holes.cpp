#include<iostream>
#include<cmath>
#include<cstdio>
#define maxn 1000
using namespace std;
int n,m;
struct hole{
	int type;
	int mass;
	int s;
}a[maxn];
int l[maxn][maxn];
int used[maxn];
int f[maxn*maxn];
int ans;
void dijkstra(int start){
	int i,j,k,x;
	for(i=1;i<=n;i++){
		if(i==start) f[i]=0;
		else if(l[start][i]!=0) f[i]=l[start][i]; 
	} 
	used[start]=1;
	for(i=1;i<n-1;i++){
		x=10000000;
		k=0;
		for(j=1;j<=n;j++){
			if(used[j]==0&&f[j]<x&&f[j]!=-1){
				x=f[j];
				k=j;
			}
		}
		if(k==0) continue;
		used[k]=1;
		for(j=1;j<=n;j++){
			if(used[j]==0&&l[j][k]!=0){ //Ò»¶¨ÒªÅÐ¶Ïl[j][k]!=0 
			  if(f[j]==-1) f[j]=f[k]+l[k][j];
			  else f[j]=min(f[k]+l[k][j],f[j]);
		    } 
		}
    }
}
int main(){
	int u,v,k;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i].type;
	for(int i=1;i<=n;i++) cin>>a[i].mass;
	for(int i=1;i<=n;i++) cin>>a[i].s;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>k;
		if(a[u].type=a[k].type) l[u][v]=k;
		else if(a[u].type=1&&a[v].type==0) l[u][v]=k+abs(a[u].mass-a[v].mass);
		else l[u][v]=k-abs(a[u].mass-a[v].mass);
	}
    dijkstra(1);
    cout<<ans;
    return 0;
}
