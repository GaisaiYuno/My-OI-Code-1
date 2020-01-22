#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define maxn 200005
#define INF 2147483647
#define ForMyLove return 0;
using namespace std;
int a[maxn];
int n,q;
inline int fastread(){
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

struct node{
	int l,r;
	int maxv;
	int minv;
}tree[maxn*4];
void push_up(int pos){
	if(tree[pos<<1].maxv>tree[pos<<1|1].maxv) tree[pos].maxv=tree[pos<<1].maxv;
	else tree[pos].maxv=tree[pos<<1|1].maxv;
	if(tree[pos<<1].minv<tree[pos<<1|1].minv) tree[pos].minv=tree[pos<<1].minv;
	else tree[pos].minv=tree[pos<<1|1].minv;
}
void build(int l,int r,int pos){
	tree[pos].l=l;
	tree[pos].r=r;
	if(l==r){
		tree[pos].maxv=a[l];
		tree[pos].minv=a[l];
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,pos<<1);
	build(mid+1,r,pos<<1|1);
	push_up(pos);
}
int query_max(int to_l,int to_r,int l,int r,int pos){
	if(to_l<=l&&to_r>=r){
		return tree[pos].maxv;
	}
	int mid=(l+r)>>1;
	int ans=0;
	if(to_l<=mid){
		int t=query_max(to_l,to_r,l,mid,pos<<1);
		if(t>ans) ans=t;
	}
	if(to_r>mid){
		int t=query_max(to_l,to_r,mid+1,r,pos<<1|1) ;
		if(t>ans) ans=t;
	}
	return ans;
}
int query_min(int to_l,int to_r,int l,int r,int pos){
	if(to_l<=l&&to_r>=r){
		return tree[pos].minv;
	}
	int mid=(l+r)>>1;
	int ans=INF;
	if(to_l<=mid){
		int t=query_min(to_l,to_r,l,mid,pos<<1);
		if(t<ans) ans=t;
	}
	if(to_r>mid){
		int t=query_min(to_l,to_r,mid+1,r,pos<<1|1) ;
		if(t<ans) ans=t;
	}
	return ans;
}
int l,r;
int t[maxn];
int main(){
	freopen("mex.in","r",stdin);
	freopen("mex.out","w",stdout);
	n=fastread();
	q=fastread();
	for(int i=1;i<=n;i++) a[i]=fastread();
	build(1,n,1);
	int t1,t2,ans;
	while(q--){
		l=fastread();
		r=fastread();
		t1=query_max(l,r,1,n,1);
		t2=query_min(l,r,1,n,1);
		if(t2>0) ans=0;
		else{
			bool flag=false;
			memset(t,0,sizeof(t));
			for(int i=l;i<=r;i++){
				t[a[i]]=1;
			}
			for(int i=t2;i<=t1;i++){
			    if(t[i]==0){
			    	ans=i;
			    	flag=true;
			    	break;
				}
			}
			if(!flag)ans=t1+1;
		}
//		cout<<t1<<"max/min"<<t2<<endl;
		printf("%d\n",ans);
	}
	ForMyLove
}
