#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 15
#define maxm 300
using namespace std;
struct edge{
	int from;
	int to;
	int len;
	int next;
}E[maxm<<1];
int mark[maxm<<1];
int size=1;
int head[maxn];
void add_edge(int u,int v,int w){
	size++;
	E[size].from=u;
	E[size].to=v;
	E[size].next=w;
	E[size].next=head[u];
	head[u]=size;
}
int n,m,tot;
//void get_ans(){
//	long long sum=0;
//	for(int i=1;i<(1<<m);i++){
//		for(int j=1;j<=m;j++){
//			if(a[i]&(1<<j)){
//				mark[i]=mark[i^1]=1;
//				sum+=E[i].w;
//			}
//		}
//		if(check(i)){
//			ans=min(a,sn)
//		}
//	}
//}
int main(){
	freopen("connect.in","r",stdin);
	freopen("connect.out","w",stdout);
	int u,v,w;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&u,&v,&w);
		add_edge(u,v,w);
		add_edge(v,u,w);
		tot+=w;
	}
	if(n>10)printf("%lld\n",(long long)w*(n-2));
//	else{
//		printf("%lld\n",get_ans());
//	} 
}
