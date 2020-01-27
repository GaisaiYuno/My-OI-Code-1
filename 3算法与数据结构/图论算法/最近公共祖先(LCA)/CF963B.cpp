#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#define maxn 200005
using namespace std;
int n;
vector<int>E[maxn];
void add_edge(int u,int v){
	E[u].push_back(v);
}
int is_del[maxn];
int num[maxn];
void get_num(int x,int fa){
	num[x]=1;
	for(int i=0;i<E[x].size();i++){
		if(E[x][i]==fa) continue;
		get_num(E[x][i],x);
		num[x]+=num[E[x][i]];
	}
}
void del(int x,int fa){
	for(int i=0;i<E[x].size();i++){
		int y=E[x][i];
		if(y==fa) continue;
		if(num[y]%2==0) del(y,x);
	} 
	printf("%d\n",x);
	for(int i=0;i<E[x].size();i++){
		int y=E[x][i];
		if(y==fa) continue;
		if(num[y]%2==1) del(y,x);
	} 
}
int main(){
	int p,root;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&p);
		if(p==0){
			root=i;
		}else{
			add_edge(i,p);
			add_edge(p,i);
		}
		
	}
	if(n%2==0) printf("NO\n");
	else{
		printf("YES\n");
		get_num(root,-1);
		del(root,-1);		
	}
}
