#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm> 
#define maxn 50000 
#define maxm 50000
using namespace std;
inline void qread(int &x){
	x=0;
	int sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	x=x*sign;
}


struct edge{
	int from;
	int to;
	int len;
	friend bool operator < (edge p,edge q){
		return p.len<q.len;//按边权排序，避免dp转移有后效性 
	}
}E[maxm+5];
int n,m; 
int dp[maxn+5];//dp[x]表示到x的最长路 
int tmp[maxn+5]; 
int main(){
	qread(n);
	qread(m);
	for(int i=1;i<=m;i++){
		qread(E[i].from);
		qread(E[i].to);
		qread(E[i].len);
		E[i].from++;
		E[i].to++;
	}
	sort(E+1,E+1+m);
	int last=0;
	E[m+1].len=-1;//防止i=m时last不更新
	for(int i=1;i<=m;i++){
		if(E[i].len==E[i+1].len) continue;
		else{		
			for(int j=last+1;j<=i;j++){
				//避免相等的自己更新，把相等的边存起来一次性更新 
				//防止后效性 
				int x=E[j].from,y=E[j].to;
				tmp[x]=dp[x];
				tmp[y]=dp[y];		
			}
			for(int j=last+1;j<=i;j++){
				int x=E[j].from,y=E[j].to;
				dp[x]=max(dp[x],tmp[y]+1);
				dp[y]=max(dp[y],tmp[x]+1);
			}
			last=i;
		}
	} 
	int ans=0;
	for(int i=1;i<=n;i++) ans=max(ans,dp[i]);
	printf("%d\n",ans);
}
