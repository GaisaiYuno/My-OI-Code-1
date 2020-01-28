#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 10000005
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
int n,m;
struct node{
	int l;
	int r;
	int i;
	node(){
		
	}
	node(int L,int R,int id){
		l=L;
		r=R;
		i=id;
	}
}a[maxn],q[maxn];
int cmp1(node a,node b){
	if(a.l==b.l) return a.r<b.r;
	else return a.l<b.l;
}
int cmp2(node a,node b){
	return a.r>b.r;
}
struct BIT{
	int c[maxn];
	void clear(){
		memset(c,0,sizeof(c));
	}
	inline int lowbit(int x){
		return x&(-x);
	}
	void add(int x,int v){
		while(x<=n){
			c[x]+=v;
			x+=lowbit(x);
		}
	}
	int query(int x){
		int ans=0;
		while(x>0){
			ans+=c[x];
			x-=lowbit(x);
		}
		return ans;
	}
	int query(int l,int r){
		return query(r)-query(l-1);
	}
}T;
int cnt=0;
void build(int l,int r){
	if(l==r) return;
	a[++cnt]=node(l,r,0);
	int mid;
	mid=qread();
	build(l,mid);
	build(mid+1,r);
}
int ans[maxn];
int main(){
//	scanf("%d %d",&n,&m);
	n=qread();
	m=qread();
	build(1,n);
	int l,r;
	for(int i=1;i<=m;i++){
//		scanf("%d %d",&l,&r);
		l=qread();
		r=qread();
		q[i]=node(l,r,i);
	}
	sort(q+1,q+m+1,cmp1);
	sort(a+1,a+cnt+1,cmp1);
	int s,t;
	s=t=1;
	for(int i=1;i<=n;i++){
		for(;q[t].l<=i&&t<=m;t++) ans[q[t].i]+=T.query(q[t].l,n);
		for(;s<=cnt&&a[s].l<=i;s++) T.add(a[s].r,1);
//		printf("debug %d\n",q[t].i);
	}
	sort(a+1,a+cnt+1,cmp2);
	sort(q+1,q+m+1,cmp2);
	T.clear();
	s=t=1;
//	for(int i=1;i<=m;i++) printf("%d ",ans[i]);
//	printf("\n");
	for(int i=n;i>=1;i--){
		for(;t<=m&&q[t].r>=i;t++) ans[q[t].i]+=T.query(q[t].l,q[t].r);
		for(;s<=cnt&&a[s].r>=i;s++) T.add(a[s].l,1);
		
	}
	for(int i=1;i<=m;i++) printf("%d\n",ans[i]);
}
