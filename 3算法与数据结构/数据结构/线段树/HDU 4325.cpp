#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define maxn 100005
using namespace std;
struct node{
	int l;
	int r;
	int mark;
	int sum;
	int len(){
		return r-l+1;
	}
}tree[maxn<<3];
int cas,n,m;
int s[maxn],t[maxn],q[maxn],lsh[maxn*3];
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
int bin_search(int L,int R,int a[],int x){
	int l=L,r=R;
	int mid;
	while(l<=r){
		mid=(l+r)/2;
		if(a[mid]==x) return mid;
		else if(a[mid]>x) r=mid-1;
		else l=mid+1;
	}
	return -1;
}
void push_up(int pos){
	tree[pos].sum=tree[pos<<1].sum+tree[pos<<1|1].sum;
}
void push_down(int pos){
	if(tree[pos].mark){
		tree[pos<<1].mark+=tree[pos].mark;
		tree[pos<<1|1].mark+=tree[pos].mark;
		tree[pos<<1].sum+=tree[pos].mark*tree[pos<<1].len();
		tree[pos<<1|1].sum+=tree[pos].mark*tree[pos<<1|1].len();
		tree[pos].mark=0;
	}
}
void build(int l,int r,int pos){
	tree[pos].l=l;
	tree[pos].r=r;
	tree[pos].mark=0;
	tree[pos].sum=0;
	if(l==r) return;
	int mid=(l+r)>>1;
	build(l,mid,pos<<1);
	build(mid+1,r,pos<<1|1); 
}
void update(int L,int R,int l,int r,int pos,int v){
	if(L<=l&&R>=r){
		tree[pos].mark+=v;
		tree[pos].sum+=v*tree[pos].len();
		return;
	}
	push_down(pos);
	int mid=(l+r)>>1;
	if(L<=mid) update(L,R,l,mid,pos<<1,v);
	if(R>mid) update(L,R,mid+1,r,pos<<1|1,v);
	push_up(pos); 
}
int query(int L,int R,int l,int r,int pos){
	if(L<=l&&R>=r){
		return tree[pos].sum;
	}
	push_down(pos);
	int mid=(l+r)>>1;
	int ans=0;
	if(L<=mid) ans+=query(L,R,l,mid,pos<<1);
	if(R>mid) ans+=query(L,R,mid+1,r,pos<<1|1);
	return ans;
}
int main(){
	cas=qread();
	for(int u=1;u<=cas;u++){
		memset(lsh,0,sizeof(lsh));
		printf("Case #%d:\n",u);
		n=qread();
		m=qread();
		for(int i=1;i<=n;i++){
			s[i]=qread();
			t[i]=qread();
			lsh[i]=s[i];
			lsh[i+n]=t[i]; 
		}
		for(int i=1;i<=m;i++){
			q[i]=qread();
			lsh[2*n+i]=q[i];
		}
		sort(lsh+1,lsh+1+2*n+m);
		int size=unique(lsh+1,lsh+1+2*n+m)-lsh-1;
		//printf("debug:\n");
		for(int i=1;i<=n;i++){
			s[i]=bin_search(1,size,lsh,s[i]);
			t[i]=bin_search(1,size,lsh,t[i]);
			//printf("%d %d\n",s[i],t[i]);
		}
		for(int i=1;i<=m;i++){
			q[i]=bin_search(1,size,lsh,q[i]);
			//printf("%d\n",q[i]);
		}
		build(1,size,1);
		for(int i=1;i<=n;i++) update(s[i],t[i],1,size,1,1);
		for(int i=1;i<=m;i++){
			printf("%d\n",query(q[i],q[i],1,size,1));
		}
	}
}
