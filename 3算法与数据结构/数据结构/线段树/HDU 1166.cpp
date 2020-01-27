//HDU 1166
#include<iostream>
#include<cstdio>
#include<cstring> 
#define maxn 50005
using namespace std;
int n;
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
	tree[pos]=tree[pos*2]+tree[pos*2+1];
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
		tree[pos]+=value;
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
	if(to_l<=mid) ans=ans+query(to_l,to_r,now_l,mid,pos*2);
	if(to_r>mid) ans=ans+query(to_l,to_r,mid+1,now_r,pos*2+1);
	return ans;
}
int t;
char op[20];
int main(){
	cin>>t;
	for(int c=1;c<=t;c++){
		n=fread(); 
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		build(1,n,1);
		int a,b; 
		printf("Case %d:\n",c); 
		while(scanf("%s",op)!=EOF){
			if(op[0]=='Q'){
				a=fread();
				b=fread();
				printf("%d\n",query(a,b,1,n,1));
			}
			else if(op[0]=='A'){
				a=fread();
				b=fread();
				update(a,b,1,n,1);
			}
			else if(op[0]=='S'){
				a=fread();
				b=fread();
				update(a,-b,1,n,1);
			}
			else if(op[0]=='E') break;
		}
	}
	return 0; 
} 
