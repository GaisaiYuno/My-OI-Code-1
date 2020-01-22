#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#define maxn 100005
using namespace std;
int n,m;
int a[maxn],b[maxn];
int x[maxn],y[maxn];
map<int,int>p;
map<int,int>q;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d %d",&a[i],&x[i]);
		p[a[i]]=x[i];
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%d %d",&b[i],&y[i]);
		q[b[i]]=y[i];
	}
	long long ans=0;
	for(int i=1;i<=n;i++){
		if(p[a[i]]>=q[a[i]]) ans+=p[a[i]];
//		printf("%d %d\n",p[a[i]],q[a[i]]);
	}
	for(int i=1;i<=m;i++){
		if(q[b[i]]>p[b[i]]) ans+=q[b[i]];
	}
	printf("%I64d\n",ans);
} 
