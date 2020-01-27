#include<iostream>
#include<cstdio>
#include<cmath>
#define maxn 50005
using namespace std;
struct node{
	int minv;
	int maxv;
	node(){}
	node(int x,int y){
		minv=x;
		maxv=y;
	}
}st[maxn][21];
int a[maxn];
int n,q;
void init(){
	//st[i][j]表示[i-2^j+1,i]最小值 
	for(int i=1;i<=n;i++) st[i][0].maxv=st[i][0].minv=a[i];
	for(int j=1;j<=20;j++){
		for(int i=(1<<j);i<=n;i++){
			st[i][j].maxv=max(st[i][j-1].maxv,st[i-(1<<(j-1))][j-1].maxv);
			st[i][j].minv=min(st[i][j-1].minv,st[i-(1<<(j-1))][j-1].minv);
			//二分成两段 [i-2^(j-1)+1,i]  [i-2^(j-1)-2^(j-1)+1,i-2^(j-1)]
		}
	}
}
node query(int l,int r){
	int x=log2(r-l+1);
	return node(min(st[l+(1<<x)-1][x].minv,st[r][x].minv),max(st[l+(1<<x)-1][x].maxv,st[r][x].maxv));
} 
int main(){
	int l,r;
	node tmp;
	while(scanf("%d %d",&n,&q)!=EOF){ 
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		init();
		while(q--){
			scanf("%d %d",&l,&r);
			tmp=query(l,r);
			printf("%d\n",tmp.maxv-tmp.minv);
		}
	} 
}
