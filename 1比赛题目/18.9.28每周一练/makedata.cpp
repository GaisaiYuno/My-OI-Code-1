#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<map>
#define maxn 10
#define maxm maxn+20
#define maxv 20
using namespace std;
inline int random(int l,int r){
	if(l!=r)return l+rand()%(r-l);
	else return l;
}
int n,m;
int fa[maxn+5];
struct edge{
	int u;
	int v;
	edge(){
		
	}
	edge(int a,int b){
		u=a;
		v=b;
	}
	friend bool operator <(edge x,edge y){
		if(x.u==y.u) return x.v<y.v;
		else return x.u<y.u;
	}
};
map<edge,int>used;
int main() {
	srand(time(NULL));
	n=random(1,maxn);
	m=random(n-1,min(n+20,n*(n-1)/2));
	int u,v;
	printf("%d %d\n",n,m);
	for(int i=1;i<=n;i++) used[edge(i,i)]=1;
	for(int i=2;i<=n;i++){
		v=i;
		u=random(1,i-1);
		printf("%d %d %d\n",u,v,random(1,maxv));
		used[edge(u,v)]=used[edge(v,u)]=1;
	}
	for(int i=n;i<=m;i++){
		do{
			u=random(1,n);
			v=random(1,n);
		}while(used.count(edge(u,v)));
		printf("%d %d %d\n",u,v,random(1,maxv));
		used[edge(u,v)]=used[edge(v,u)]=1;
	}
}
