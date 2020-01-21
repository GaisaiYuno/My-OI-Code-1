#include<iostream>
#include<cstdio>
#define maxn 50005
using namespace std;
int a[maxn],tree[maxn*4];
int n,m; 
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
void update(int k,int v,int l,int r,int pos){
	if(l==r){
		tree[pos]+=v;
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
	if(to_l<=mid) ans+=query(to_l,to_r,l,mid,pos*2);
	if(to_r>mid) ans+=query(to_l,to_r,mid+1,r,pos*2+1);
	return ans;
}
int t;
int main(){
	int k,d,l,r;
	string cmd;
	cin>>t;
	for(int c=1;c<=t;c++){
		cin>>n;
		for(int i=1;i<=n;i++) a[i]=fread();
		build(1,n,1);
		printf("Case %d:\n",c);
		while(cin>>cmd){
			if(cmd=="Add"){
				k=fread();
				d=fread();
				update(k,d,1,n,1);
			}
			else if(cmd=="Sub"){
				k=fread();
				d=fread();
				update(k,-d,1,n,1);
			}
			else if(cmd=="Query"){
				l=fread();
				r=fread();
				cout<<query(l,r,1,n,1)<<endl;
			}else if(cmd=="End"){
				break;
			}
		}
	}
}
