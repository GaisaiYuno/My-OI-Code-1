/*
二分找出最近的确定年份 
先判false：
　　　　　　1、当右端点年份确定，且中间年份最大降雨量大于等于右端点降雨量
　　　　　　2、当左端点年份确定，且中间年份最大降雨量大于等于左端点降雨量
　　　　　　3、当左右端点年份都确定，且左端点降雨量小于右端点降雨量 (X年的降雨量不超过Y年)

再判maybe:
　　　　　　1、当左右端点之差不等于左右端点年份之差（等价于年份不连续，也就是我前面所说的更好的判断区间连续的方法）
　　　　　　2、左端点年份不确定
　　　　　　3、右端点年份不确定

最后判断true: 若上面情况都不满足，那么肯定是truetrue

*/ 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 50000 
using namespace std;
int n,m;
int tim[maxn+5],val[maxn+5];

struct node{
	int l;
	int r;
	int v;
}tree[maxn*4+5];
void push_up(int pos){
	tree[pos].v=max(tree[pos<<1].v,tree[pos<<1|1].v);
}
void build(int l,int r,int pos){
	tree[pos].l=l;
	tree[pos].r=r;
	if(l==r){
		tree[pos].v=val[l];
		return; 
	}
	int mid=(l+r)>>1;
	build(l,mid,pos<<1);
	build(mid+1,r,pos<<1|1);
	push_up(pos);
}
int query(int L,int R,int pos){
	if(L<=tree[pos].l&&R>=tree[pos].r){
		return tree[pos].v;
	}
	int mid=(tree[pos].l+tree[pos].r)>>1;
	int ans=0;
	if(L<=mid) ans=max(ans,query(L,R,pos<<1));
	if(R>mid) ans=max(ans,query(L,R,pos<<1|1));
	return ans;
}

int main(){
	int l,r,s,e; 
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d %d",&tim[i],&val[i]);
	}
	build(1,n,1);
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%d %d",&l,&r);
		if(l>=r) printf("false\n");
		s=lower_bound(tim+1,tim+1+n,l)-tim;
		e=lower_bound(tim+1,tim+1+n,r)-tim;
		bool certain_l=(tim[s]==l);
		bool certain_r=(tim[e]==r);
		if(!certain_l) s--;//本来默认查询中间年份(s+1,e-1),但是l不确定的时候tim[s]>=l,tim[s]被包含在中间年份中，所以s++ 
		if(certain_r&&query(s+1,e-1,1)>=val[e]){
			printf("false\n");
			continue;
		}
		else if(certain_l&&query(s+1,e-1,1)>=val[s]){
			printf("false\n");
			continue;
		}
		else if(certain_l&&certain_r&&val[s]<val[e]){
			printf("false\n");
			continue;
		}
		else if(e-s!=r-l){
			printf("maybe\n");
			continue;
		}else if(!certain_l){
			printf("maybe\n");
			continue;
		}else if(!certain_r){
			printf("maybe\n");
			continue;
		}else{
			printf("true\n");
		}
	}
}
