//http://119.29.55.79/contest/94/problem/3 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define maxn 100000 
using namespace std;
int n,m,T;
int ans[maxn+5];
struct disjoint_set{
	int fa[maxn+5];
	int deep[maxn+5];
	int sz[maxn+5];
	void ini(int n){
		for(int i=1;i<=n;i++){
			fa[i]=0;
			sz[i]=1;
		}
	}
	int find(int x){
		while(fa[x]!=0) x=fa[x];
		return x;
	}
	int get_deep(int x){
		int ans=0;
		while(fa[x]!=0){
			ans^=deep[x];
			x=fa[x];
		}
		ans^=deep[x];
		return ans;
	}
	int top=0;

	bool check(int x,int y){
		int fx=find(x),fy=find(y);
		int dx=get_deep(x),dy=get_deep(y);
		if(fx==fy){
			if((dx^dy^1)==1) return 1;
			else return 0;
		}else return 0;
	}
	void merge(int x,int y,vector< pair<int,int> > &stk){
		int fx=find(x),fy=find(y);
		int dx=get_deep(x),dy=get_deep(y);
		if(fx!=fy){
			if(sz[fx]>sz[fy]) swap(fx,fy);
			fa[fx]=fy;
			deep[fx]=dx^dy^1;
			sz[fy]+=sz[fx];
			stk.push_back(make_pair(fx,fy));
		}
	}
	void del(int fx,int fy){
		fa[fx]=0;
		deep[fx]=0;
		sz[fy]-=sz[fx];
	}
}S;


vector< pair<int,int> >E[maxn*4+5];
vector< pair<int,int> > stk[maxn*4+5];//回滚用的栈 
void update(int L,int R,pair<int,int> val,int l,int r,int pos){
	if(L<=l&&R>=r){
		E[pos].push_back(val);
		return;
	}
	int mid=(l+r)>>1;
	if(L<=mid) update(L,R,val,l,mid,pos<<1);
	if(R>mid) update(L,R,val,mid+1,r,pos<<1|1);
}
void divide(int l,int r,int pos){
	bool flag=0;
	for(int i=0;i<(int)E[pos].size();i++){
		int x=E[pos][i].first;
		int y=E[pos][i].second;
		if(S.check(x,y)){//存在奇环 
			flag=1;
			for(int i=l;i<=r;i++) ans[i]=0;
			break;
		}
		S.merge(x,y,stk[pos]);
	}
	int mid=(l+r)>>1;
	if(l!=r&&!flag){//没有奇环，继续递归 
		divide(l,mid,pos<<1);
		divide(mid+1,r,pos<<1|1);
	}
	for(int i=(int)stk[pos].size()-1;i>=0;i--){
		S.del(stk[pos][i].first,stk[pos][i].second);
	}
}

int main(){
	int u,v,l,r;
	scanf("%d %d %d",&n,&m,&T);
	S.ini(n);
	for(int i=1;i<=T;i++) ans[i]=1;
	for(int i=1;i<=m;i++){
		scanf("%d %d %d %d",&u,&v,&l,&r);
		l++;
		update(l,r,make_pair(u,v),1,T,1);
	}
	divide(1,T,1);
	for(int i=1;i<=T;i++){
		if(ans[i]) puts("Yes");
		else puts("No");
	}
}

