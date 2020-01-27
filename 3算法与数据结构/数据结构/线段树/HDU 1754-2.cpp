#include<iostream>
#define maxn 200005 
using namespace std;
int a[maxn];
int tree[maxn*4]; 
inline int fread(){
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
	tree[pos]=max(tree[pos*2],tree[pos*2+1]);
}
void build(int l,int r,int pos){
	if(l==r){
		tree[pos]=a[l];
		return;
	}
	int mid=(l+r)/2;
	build(l,mid,pos*2);
	build(mid+1,r,pos*2+1);
	push_up(pos);
}
void update(int k,int v,int l,int r,int pos){
	if(l==r){
		tree[pos]=v;
		return;
	}
	int mid=(l+r)/2;
	if(k<=mid) update(k,v,l,mid,pos*2);
	else update(k,v,mid+1,r,pos*2+1);
	push_up(pos);
}
int query(int to_l,int to_r,int l,int r,int pos){
	if(to_l<=l&&to_r>=r){
		return tree[pos];
	}
	int mid=(l+r)/2;
	int ans=0;
	if(to_l<=mid) ans=max(query(to_l,to_r,l,mid,pos*2),ans);
	if(to_r>mid) ans=max(ans,query(to_l,to_r,mid+1,r,pos*2+1));
	return ans;
}
int n,m; 
char cmd;
int main(){
	int x,y;
	while(cin>>n>>m){
		for(int i=1;i<=n;i++) a[i]=fread();
		build(1,n,1);
		while(m--){
			scanf("%c",&cmd);
			if(cmd=='Q'){
				x=fread();
				y=fread();
				printf("%d\n",query(x,y,1,n,1));
			}else if(cmd=='U'){
				x=fread();
				y=fread();
				update(x,y,1,n,1);
			}
		}
	}
}
