#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 500005
using namespace std;
int n,k,mod;
int a[maxn];
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
inline int gcd(int a,int b){
	if(b==0) return a;
	else return gcd(b,a%b);
}
struct node{
	int l;
	int r;
	int v;
}tree[maxn<<2];
void push_up(int pos){
	tree[pos].v=gcd(tree[pos<<1].v,tree[pos<<1|1].v);
}
void build(int l,int r,int pos){
	tree[pos].l=l;
	tree[pos].r=r;
	tree[pos].v=0;
	if(l==r){
		tree[pos].v=a[l];
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,pos<<1);
	build(mid+1,r,pos<<1|1);
	push_up(pos);
}
void update(int tpos,int value,int l,int r,int pos){
	if(l==r){
		tree[pos].v=value;
		return;
	}
	int mid=(l+r)>>1;
	if(tpos<=mid) update(tpos,value,l,mid,pos<<1);
	else update(tpos,value,mid+1,r,pos<<1|1);
	push_up(pos);
}
bool flag=false; //记录是否有一个数需要修改 
int query(int L,int R,int l,int r,int pos){
	if(L<=l&&R>=r){
		 if(tree[pos].v%mod==0) return 1;
		 else{
		 	if(flag) return 0;
		 	else{
		 	 	if(!(tree[pos].r-tree[pos].l)){//如果是叶子节点才返回真！ 
					//不是叶子节点就继续递归查找 
		 	 		flag=true;
					return 1;	
				}
			}
		 }
	} 
	int mid=(l+r)>>1;
	int ans=1;
	if(L<=mid) ans&=query(L,R,l,mid,pos<<1);
	if(R>mid) ans&=query(L,R,mid+1,r,pos<<1|1);
	return ans;
}
int main(){
	//freopen("baiyun.in","r",stdin);
	//freopen("baiyun.out","w",stdout);
	//printf("%.2f MB\n",(double)(sizeof(tree)+sizeof(a))/1024/1024);
	int cmd,q,z,y,i;
	n=qread();
	for(int i=1;i<=n;i++) a[i]=qread();
	k=qread();
	build(1,n,1);
	while(k--){
		flag=false;
		cmd=qread();
		if(cmd==1){
			q=qread();
			z=qread();
			y=qread();
			mod=y;
			if(query(q,z,1,n,1)) printf("YES\n");
			else printf("NO\n");
		}
		else{
			i=qread();
			y=qread();
			update(i,y,1,n,1);
		}
	}
}
