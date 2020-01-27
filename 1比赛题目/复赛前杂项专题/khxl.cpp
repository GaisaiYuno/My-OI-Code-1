#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm> 
#define maxn 500000
using namespace std;
typedef long long ll;
int n;
struct edge{
	int from;
	int to;
	int next;
}E[maxn*2+5];
int sz=1;
int head[maxn+5];
void add_edge(int u,int v){
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].next=head[u];
	head[u]=sz;
}

int deep[maxn+5];
char a[maxn+5];
int stk[maxn+5];
ll sum[maxn+5];
ll dp[maxn+5];
int top=0;
void dfs1(int x,int fa){
	bool flag=false;
	int l;
	deep[x]=deep[fa]+1;
	if(a[x]=='(') stk[++top]=deep[x];
	else{
		if(top>0){
			l=stk[top];
			top--;
			dp[deep[x]]=dp[l-1]+1;
			flag=true;
		}
	}
	sum[x]=dp[deep[x]];
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(y!=fa){
			dfs1(y,x);
		}
	}
	if(a[x]=='(') top--;
	else{
		if(flag){
			stk[++top]=l;
			dp[deep[x]]=0;
		}
	}
}

ll res=0;
void dfs2(int x,int fa){
	sum[x]+=sum[fa];
	res^=sum[x]*x;
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(y!=fa){
			dfs2(y,x);
		}
	}
}

int main(){
	int f;
	scanf("%d",&n);
	scanf("%s",a+1);
	for(int i=2;i<=n;i++){
		scanf("%d",&f);
		add_edge(i,f);
		add_edge(f,i);
	}
	dfs1(1,0);
	dfs2(1,0);
	printf("%lld\n",res);
}

