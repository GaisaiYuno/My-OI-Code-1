#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#define maxn 300005
#define mod 998244353
using namespace std;
inline long long fast_pow(long long x,long long k){
	long long ans=1;
	while(k){
		if(k&1) ans=ans*x%mod;
		x=x*x%mod;
		k>>=1;
	}
	return ans;
}

int t,n,m;
vector<int>E[maxn];
int color[maxn];
int cnt0,cnt1;
bool flag=true;
void dfs(int x,int c){
	if(c==1) cnt0++;
	if(c==2) cnt1++; 
	color[x]=c;
	for(auto y : E[x]){
		if(color[y]==0) dfs(y,3-c);
		else if(color[y]==c){
			flag=false;
			return;
		}
	}
} 

void ini(){
	for(int i=1;i<=n;i++) E[i].clear();
//	memset(color,0,sizeof(color));
	for(int i=1;i<=n;i++) color[i]=0; 
}
int main(){
	int u,v;
	scanf("%d",&t);
	for(int k=1;k<=t;k++){
		scanf("%d %d",&n,&m);
		ini();
		for(int i=1;i<=m;i++){
			scanf("%d %d",&u,&v);
			E[u].push_back(v);
			E[v].push_back(u);
		}
		flag=true;
		long long ans=1; 
		for(int i=1;i<=n;i++){
			if(!color[i]){
				cnt0=cnt1=0;
				dfs(i,1);
				ans=ans*(fast_pow(2,cnt0)%mod+fast_pow(2,cnt1)%mod)%mod;
				if(flag==false) break;
			}
		}
		if(flag==false){
			printf("0\n"); 
		}else{
			printf("%I64d\n",ans);
		}
	}
}
