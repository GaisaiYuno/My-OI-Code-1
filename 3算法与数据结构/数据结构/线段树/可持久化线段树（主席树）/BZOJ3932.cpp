//https://www.luogu.org/problemnew/show/P3168
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define maxn 300005
#define maxlogn 21 
using namespace std;
int m,n;
vector<int>d[maxn]; 
int b[maxn];
int sz;

struct node{
#ifdef DEBUG
	int l;
	int r;
#endif
	int ls;
	int rs;
	int cnt;
	long long sum;
}tree[2*maxn*maxlogn];
int root[maxn*2];
int ptr;
void push_up(int pos){
	tree[pos].cnt=tree[tree[pos].ls].cnt+tree[tree[pos].rs].cnt;
	tree[pos].sum=tree[tree[pos].ls].sum+tree[tree[pos].rs].sum;
}
void update(int &pos,int last,int upos,int uval,int flag,int l,int r){
	pos=++ptr;
	tree[pos]=tree[last];
#ifdef DEBUG
	tree[pos].l=l;
	tree[pos].r=r;
#endif
	if(l==r){
		tree[pos].cnt+=flag;
		tree[pos].sum+=uval*flag;
		return;
	}
	int mid=(l+r)>>1;
	if(upos<=mid) update(tree[pos].ls,tree[last].ls,upos,uval,flag,l,mid);
	else update(tree[pos].rs,tree[last].rs,upos,uval,flag,mid+1,r);
	push_up(pos);
}


long long query(int ql,int qr,int qk,int l,int r){
	if(l==r){
		//注意多组数据相同的情况，必须要用k*值，不能用sum
		//见最下方hack数据 
		return b[l]*qk;
	}
	int mid=(l+r)>>1;
	int lcnt=tree[tree[qr].ls].cnt-tree[tree[ql].ls].cnt;
	if(qk<=lcnt) return query(tree[ql].ls,tree[qr].ls,qk,l,mid);
	else return tree[tree[qr].ls].sum-tree[tree[ql].ls].sum+query(tree[ql].rs,tree[qr].rs,qk-lcnt,mid+1,r);
}


int main(){
	int s,e,v;
	long long xx,aa,bb,cc;
	scanf("%d %d",&m,&n);
	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&s,&e,&v);
		d[s].push_back(v);
		d[e+1].push_back(-v);
		b[++sz]=v;
	}
	sort(b+1,b+1+sz);
	sz=unique(b+1,b+1+sz)-b-1;
	for(int i=1;i<=n;i++){
		root[i]=root[i-1];
		for(int j=0;j<d[i].size();j++){
			int val=d[i][j];
			int disval=lower_bound(b+1,b+1+sz,abs(val))-b;
			if(val<0) update(root[i],root[i],disval,abs(val),-1,1,sz);
			else update(root[i],root[i],disval,abs(val),1,1,sz);
		}
	} 
	long long ans=1;
	for(int i=1;i<=n;i++){
		scanf("%lld %lld %lld %lld",&xx,&aa,&bb,&cc);
		long long k=1+(aa*ans+bb)%cc;
		if(k>tree[root[xx]].cnt) ans=tree[root[xx]].sum;
		else ans=query(root[0],root[xx],k,1,sz);
		printf("%lld\n",ans);
	}
}

/*
in:
3 3
1 1 1
1 2 1
1 3 1
1 0 1 100
2 0 1 100
3 0 1 100

rightout:
2
2
1
*/ 

