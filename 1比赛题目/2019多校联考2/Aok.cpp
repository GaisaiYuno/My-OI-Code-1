#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector> 
#include<algorithm>
#define maxn 50000 
using namespace std;
int n,k,tot;
vector<int>E[maxn+5];
int fa[maxn+5];
int leaf[maxn+5];
int cnt[maxn+5];
void dfs(int x,int f,int rt){
	fa[x]=f;
	if(E[x].size()==1&&x!=rt) leaf[++tot]=x;
	for(int i=0;i<E[x].size();i++){
		int y=E[x][i];
		if(y!=f){
			cnt[y]=cnt[x]+1;
			dfs(y,x,rt);
		}
	}
}
bool vis[maxn+5];
bool cmp(int x,int y){
	if(cnt[x]==cnt[y]) return x<y;
	else return cnt[x]>cnt[y];
}
int main(){
	int f;
	scanf("%d %d",&n,&k);
	k++;
	for(int i=2;i<=n;i++){
		scanf("%d",&f);
		f++;
		E[f].push_back(i);
		E[i].push_back(f);
	}
	dfs(k,0,k);
	sort(leaf+1,leaf+1+tot,cmp);
	for(int i=1;i<=tot;i++){
		int x=leaf[i],y=x;
		cnt[x]=0;
		while(!vis[y]){
			vis[y]=1;
			cnt[x]++;
			y=fa[y];
			if(y==k) break;
		}
	}
	sort(leaf+1,leaf+1+tot,cmp);
	printf("%d\n",k-1);
	for(int i=1;i<=tot;i++) printf("%d\n",leaf[i]-1);
}

