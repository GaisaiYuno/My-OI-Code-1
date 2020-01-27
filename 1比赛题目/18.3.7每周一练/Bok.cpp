#include<iostream>
#include<cstring>
#include<cstdio>
#define maxn 32005
#define lson pos<<1
#define rson pos<<1|1 
using namespace std;
int x[maxn],y[maxn],level[maxn];
int tree[maxn*4];
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
void push_up(int pos){
	tree[pos]=tree[lson]+tree[rson]; 
}
void build(int l,int r,int pos){
	tree[pos]=0;
	if(l==r){
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,lson);
	build(mid+1,r,rson) ;
}
void update(int to_pos,int value,int l,int r,int pos){
	if(l==r){
		tree[pos]+=value;
		return;
	}
	int mid=(l+r)>>1;
	if(to_pos<=mid) update(to_pos,value,l,mid,lson);
	else update(to_pos,value,mid+1,r,rson);
	push_up(pos);
}
int query(int L,int R,int l,int r,int pos){
	if(L<=l&&r<=R){
		return tree[pos];
	}
	int mid=(l+r)/2,ans=0;
	if(L<=mid) ans+=query(L,R,l,mid,lson);
	if(R>mid) ans+=query(L,R,mid+1,r,rson);
	return ans; 
}
int n;
int main(){
	while(cin>>n){
    	build(0,maxn,1);
    	memset(level,0,sizeof(level));
    	for(int i=1;i<=n;i++){
    		x[i]=qread();
    		y[i]=qread();
    		int lev=query(0,x[i],0,maxn,1);
    		update(x[i],1,0,maxn,1);
			level[lev]++;
		}
		for(int i=0;i<n;i++) printf("%d\n",level[i]);
	}	
}
