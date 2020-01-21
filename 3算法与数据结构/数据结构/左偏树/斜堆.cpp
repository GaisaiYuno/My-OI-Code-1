#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 205
using namespace std;
int n;
int l[maxn],r[maxn],fa[maxn],root;
int top=0;
int ans[maxn];
void solve(){
	int x=root;
	while(r[x]!=-1){
		x=l[x];
	}
	if(l[x]!=-1&&l[l[x]]==-1&&r[l[x]]==-1) x=l[x];
	ans[++top]=x;
	if(x==root) root=l[x];
	int f=fa[x];
	if(l[x]!=-1) fa[l[x]]=f;
	l[f]=l[x];
	x=f;
	while(x!=-1){
		swap(l[x],r[x]);
		x=fa[x];
	}
}

int main(){
	int x;
	scanf("%d",&n);
	memset(fa,-1,sizeof(fa));
	memset(l,-1,sizeof(l));
	memset(r,-1,sizeof(r));
	root=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		if(x<100){
			l[x]=i;
			fa[i]=x;
		}else{
			x-=100;
			r[x]=i;
			fa[i]=x;
		}
	}
	for(int i=1;i<=n;i++) solve();
	printf("%d ",root);
	for(int i=top;i>0;i--){
		printf("%d ",ans[i]);
	}
}
