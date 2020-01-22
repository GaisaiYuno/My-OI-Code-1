#include<iostream>
#include<cstdio>
#include<cstring>
#define mod 45989
#define maxn 45
#define maxm 65
#define maxs maxm*2
using namespace std;
int n,m,k,s,t;
struct edge{
	int from;
	int to;
	int next;
}E[maxm<<1];
int head[maxn];
int sz=1;
void add_edge(int u,int v){
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].next=head[u];
	head[u]=sz;
}

struct matrix{
	int n;
	int m;
	long long a[maxs][maxs];
	void print(){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				printf("%d ",a[i][j]);
			} 
			printf("\n");
		}
		printf("\n");
	}
	matrix(){
		memset(a,0,sizeof(a));
	}
	matrix(int x,int y){
		n=x;
		m=y;
		memset(a,0,sizeof(a));
	}
	friend matrix operator *(matrix u,matrix v){
		matrix ans=matrix(u.n,v.m);
		for(int i=1;i<=u.n;i++){
			for(int j=1;j<=v.m;j++){
				for(int k=1;k<=u.m;k++){
					ans.a[i][j]+=u.a[i][k]*v.a[k][j]%mod;
				}
				ans.a[i][j]%=mod;
			}
		}
		return ans;
	}
}; 
matrix fast_pow(matrix x,int k){
	matrix ans=matrix(x.n,x.m);
	for(int i=1;i<=x.n;i++){
		ans.a[i][i]=1;
	}
	while(k){
		if(k&1) ans=ans*x;
		x=x*x;
		k>>=1;
	}
	return ans;
}
int main(){
	scanf("%d %d %d %d %d",&n,&m,&k,&s,&t);
	int u,v;
	for(int i=1;i<=m;i++){
		scanf("%d %d",&u,&v);
		add_edge(u,v);
		add_edge(v,u);
	}
	matrix f=matrix(sz,sz),p=matrix(sz,sz);
	for(int i=head[s];i;i=E[i].next){
		f.a[1][i]=1;
	}
	for(int i=2;i<=sz;i++){
		for(int j=2;j<=sz;j++){
			if(E[i].to==E[j].from&&i!=(j^1)){
				p.a[i][j]=1;
			}
		}
	}
//	f.print();
//	p.print();
	f=f*fast_pow(p,k-1);
//	f.print();
	long long ans=0;
	for(int i=head[t];i;i=E[i].next){
		ans=ans+f.a[1][i^1];
		ans%=mod;
	}
	printf("%lld\n",ans%mod);
} 
