#include<iostream>
#include<cstdio>
#include<cstring>
#define mod 3
#define maxn 50000
using namespace std;
int n,k;
int fa[maxn+5];
int d[maxn+5];
int sz[maxn+5];//存储边权和 
int find(int x){
	if(fa[x]==x) return x;
	else{
		int root=find(fa[x]);
		d[x]+=d[fa[x]];
		d[x]%=mod;
		fa[x]=root;
		return root;
	}
}
void merge(int x,int y,int val){//将x合并到y，且连边(x,y,val) 
	int	dx=d[x],dy=d[y];
	int fx=find(x);
	int fy=find(y);
	fa[fx]=fy; 
	d[fx]=dy-dx+val;
	d[fx]=(d[fx]+mod)%mod;
//	d[fx]=sz[fy]+val;
//	sz[fy]+=sz[fx]+val; 
}
void ini(int n){
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
}


inline int dist(int x,int y){
	int ans=d[x]-d[y];
	ans=(ans+mod)%mod;
	return ans;
}
int is_self(int x,int y){
	if(x>n||y>n) return 0;
	int fx=find(x);
	int fy=find(y);
	if(fx==fy&&dist(x,y)!=0) return 0;
	merge(x,y,0);
	return 1;
}

int is_eat(int x,int y){
	if(x>n||y>n) return 0;
	int fx=find(x);
	int fy=find(y);
	if(fx==fy&&dist(x,y)!=1) return 0;
	merge(x,y,1);
	return 1;
	
}
int main(){
	int tp,x,y;
	scanf("%d %d",&n,&k);
	ini(n);
	int ans=0;
	for(int i=1;i<=k;i++){
		scanf("%d %d %d",&tp,&x,&y);
		if(tp==1){
			if(is_self(x,y)==0){
				ans++;
//				printf("fake\n");
			}
		}else{
			if(x==y||is_eat(x,y)==0){
				ans++;
//				printf("fake\n");
			}
		}
	}
	printf("%d\n",ans);
}

