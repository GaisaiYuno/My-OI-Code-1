#include<iostream>
#include<cstdio>
using namespace std;
inline int Abs(int x){return x>=0?x:-x;}
int dis[500001],sco[500001],n,k,gl,ming=500001;
void dfs(int cur,int pt,int g){
	if(cur==n){if(pt>=gl)ming=min(ming,g);return;}
	for(int i=cur+1;i<=n;i++){
		if(Abs(k-dis[i]+dis[cur])<ming){
			dfs(i,pt+sco[i],max(g,Abs(k-dis[i]+dis[cur])));
			if(g>=ming)return;
		}
	}
}
int main(){
	freopen("jump.in","rb",stdin);
	freopen("jump.out","wb",stdout);
	scanf("%d%d%d",&n,&k,&gl);
	for(int i=1;i<=n;i++)scanf("%d%d",&dis[i],&sco[i]);
	dfs(0,0,0);
	printf("%d\n",ming==500001?-1:ming);
}
