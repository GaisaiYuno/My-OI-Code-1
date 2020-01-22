#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define N 1010
int map[N][N];
int f[N],n;
using namespace std;
bool vis[N];
void dfs(int u){
  if(f[u])return;
  for(int i=1;i<=n;i++){
    if(!map[u][i])continue;
    dfs(i);
    f[u]=max(f[u],f[i]);
  }
  f[u]++;
}
int main(){
  freopen("hh.in","r",stdin);
  freopen("hh.out","w",stdout);
  int m,x;
  int a[N];
  cin>>n>>m;
  while(m--){
    scanf("%d",&x);
    for(int i=1;i<=x;i++)scanf("%d",&a[i]);
    int now=2;
    for(int j=a[1]+1;j<a[x];j++){
      if(j==a[now])now++;
      else {
    for(int i=1;i<=x;i++)map[j][a[i]]=1;
      }
    }
  }
  int ans=0;
  for(int i=1;i<=n;i++){
    if(!f[i])dfs(i);
    ans=max(ans,f[i]);
  }
  cout<<ans;
}
