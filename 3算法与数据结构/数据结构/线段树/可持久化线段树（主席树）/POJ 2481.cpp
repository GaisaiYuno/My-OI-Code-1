#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100005
using namespace std;
inline int qread(){
	int x=0,sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*sign; 
}
struct value{
	int x;
	int id;
}val[maxn];
int cmp(value A,value B){
	return A.x<B.x;
}
int root[maxn],dis[maxn]; 
int n,m;
int size;
struct node{
	int l;
	int r;
	int v;
}tree[maxn*20];
void update(int &pos,int l,int r,int v){
	tree[++size]=tree[pos];
	pos=size;
	tree[size].v++;
	if(l==r) return;
	int mid=(l+r)>>1;
	if(v<=mid) update(tree[pos].l,l,mid,v);
	else update(tree[pos].r,mid+1,r,v); 
} 
int query(int L,int R,int l,int r,int v){
	if(l==r) return l;
	int t=tree[tree[R].l].v-tree[tree[L].l].v;
	int mid=(l+r)>>1;
	if(t>=v) return query(tree[L].l,tree[R].l,l,mid,v);
	else return query(tree[L].r,tree[R].r,mid+1,r,v-t);
}
int main(){
	while(scanf("%d %d",&n,&m)!=EOF){
		for(int i=1;i<=n;i++){
			 val[i].x=qread();
			 val[i].id=i; 
		} 
		sort(val+1,val+1+n,cmp);
		for(int i=1;i<=n;i++) dis[val[i].id]=i;
		memset(root,0,sizeof(root));
		memset(tree,0,sizeof(tree));
		size=0;
		for(int i=1;i<=n;i++){
			root[i]=root[i-1];
			update(root[i],1,n,dis[i]);
		}
		int l,r,k;
		for(int i=1;i<=m;i++){
			l=qread();
			r=qread();
			k=qread();
			int tmp=query(root[l-1],root[r],1,n,k);
			printf("%d\n",val[tmp].x);
		}
	}
} 
