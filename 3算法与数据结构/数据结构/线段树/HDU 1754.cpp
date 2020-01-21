//HDU 1754
#include<iostream>
#include<cstdio>
#include<cstring> 
#define maxn 200005 
using namespace std;
int n,m;
int a[maxn],tree[maxn*4];
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
void update(int a_pos,int value,int l,int r,int pos){
	if(l==r){
		tree[pos]=value;
		return;
	}
	int mid=(l+r)/2;
	if(a_pos<=mid)update(a_pos,value,l,mid,pos*2);
	else update(a_pos,value,mid+1,r,pos*2+1);
	push_up(pos); 
}
int query(int to_l,int to_r,int now_l,int now_r,int pos){
	if(to_l<=now_l&&now_r<=to_r){
		return tree[pos];
	}
	int mid=(now_l+now_r)/2;
	int ans=0;
	if(to_l<=mid) ans=max(ans,query(to_l,to_r,now_l,mid,pos*2));
	if(to_r>mid) ans=max(ans,query(to_l,to_r,mid+1,now_r,pos*2+1));
	return ans;
}
int main(){
	while(cin>>n>>m){
		for(int i=1;i<=n;i++) a[i]=fread();
		build(1,n,1) ;
		char op;
		int a,b; 
		while(m--){
			scanf("%c",&op);
			if(op=='Q'){
				a=fread();
				b=fread();
				printf("%d\n",query(a,b,1,n,1));
			}
			else if(op=='U'){
				a=fread();
				b=fread();
				update(a,b,1,n,1);
			}
		}
	}
	return 0; 
} 
