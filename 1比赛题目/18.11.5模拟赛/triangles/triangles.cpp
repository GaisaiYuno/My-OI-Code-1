#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 1005
#define maxm 250005
using namespace std;
inline int qread(){
	int x=0,sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*sign;
}

int n,m;
int c[maxn][maxn];
int deg[maxn];
int main(){
//	freopen("triangles.in","r",stdin);
//	freopen("triangles.out","w",stdout);
	int u,v;
	n=qread();
	m=qread();
	for(int i=1;i<=m;i++){
		u=qread();
		v=qread();
		deg[u]++;
		deg[v]++;
		c[u][v]=1;	
		c[v][u]=1;
	}
	long long all=(long long)n*(n-1)*(n-2)/6;
	long long no=(long long)m*(n-2);
	for(int i=1;i<=n;i++){
		no-=(long long)deg[i]*(deg[i]-1)/2;
	}
	printf("%lld\n",all-no);
}
