//culture
#include<iostream>
#include<cstring>
#define maxn 105
#define maxk 105
using namespace std;
int n,k,m,s,t;
int c[maxn];
int p[maxk][maxk];//�Ļ��Ƿ��ͻ 
int l[maxn][maxn];//·������ 
int f[maxn];//���·�� 
int used[maxn];//һ�����Ƿ��߹� 
void dijkstra(){
	int i,j,k,x;
	for(i=1;i<=n;i++){
		if(i==s) f[s]=0;
		else if(l[s][i]!=0)
		  if(p[c[i]][c[j]]==0) f[i]=l[s][i]; 
	} 
	used[s]=1;
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
			if(used[j]==0&&p[c[j]][c[k]]==0&&l[j][k]!=0){ //һ��Ҫ�ж�l[j][k]!=0 
			  if(f[j]==-1) f[j]=f[k]+l[k][j];
			  else f[j]=min(f[k]+l[k][j],f[j]);
		    } 
		}
    }
}
int main(){
	int i,j,u,v,d;
	//std::ios::sync_with_stdio(false);
	freopen("culture.in","r",stdin);
	freopen("culture.out","w",stdout);
	cin>>n>>k>>m>>s>>t;
	memset(c,0,sizeof(c));
	memset(p,0,sizeof(p));
	memset(l,0,sizeof(l));
	memset(f,-1,sizeof(f));
	memset(used,0,sizeof(used)); 
	for(i=1;i<=n;i++) cin>>c[i];
	for(i=1;i<=k;i++){
		for(j=1;j<=k;j++) cin>>p[i][j];
	}
	for(i=1;i<=m;i++){
		for(j=1;j<=m;j++){
			cin>>u>>v>>d;
			l[u][v]=l[v][u]=d;
		}
	}
	dijkstra();
	cout<<f[t]<<endl;
	return 0;
}
