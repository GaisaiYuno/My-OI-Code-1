//http://codeforces.com/problemset/problem/407/E
//此题无单调性，不能二分！！！！！！！ 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 200000
#define INF 0x3f3f3f3f
using namespace std;
inline void qread(int &x){
	x=0;
	int sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	x=x*sign;
}
inline void qprint(int x){
	if(x<0){
		qprint(-x);
		putchar('\n');
	}else if(x==0){
		putchar('0');
		return;
	}else{
		if(x/10>0) qprint(x/10);
		putchar('0'+x%10);
	}
}

int n,k,d;
struct segment_tree{
	struct node{
		int l;
		int r;
		int maxv;
		int minv;
		int len(){
			return r-l+1;
		}
	}tree[maxn*4+5];
	void push_up(int pos){
		tree[pos].maxv=max(tree[pos<<1].maxv,tree[pos<<1|1].maxv);
		tree[pos].minv=min(tree[pos<<1].minv,tree[pos<<1|1].minv);
	}
	void build(int l,int r,int *a,int pos){
		tree[pos].l=l;
		tree[pos].r=r;
		tree[pos].maxv=0;
		tree[pos].minv=INF;
		if(l==r){
			tree[pos].maxv=tree[pos].minv=a[l];
			return;
		}
		int mid=(l+r)>>1;
		build(l,mid,a,pos<<1);
		build(mid+1,r,a,pos<<1|1);
		push_up(pos);
	}
	int query_max(int L,int R,int pos){
		if(L<=tree[pos].l&&R>=tree[pos].r){
			return tree[pos].maxv;
		}	
		int ans=0;
		int mid=(tree[pos].l+tree[pos].r)>>1;
		if(L<=mid) ans=max(ans,query_max(L,R,pos<<1));
		if(R>mid) ans=max(ans,query_max(L,R,pos<<1|1));
		return ans;
	}
	int query_min(int L,int R,int pos){
		if(L<=tree[pos].l&&R>=tree[pos].r){
			return tree[pos].minv;
		}
		int ans=INF;
		int mid=(tree[pos].l+tree[pos].r)>>1;
		if(L<=mid) ans=min(ans,query_min(L,R,pos<<1));
		if(R>mid) ans=min(ans,query_min(L,R,pos<<1|1));
		return ans;
	}
}T1,T2;

int a[maxn];
int b[maxn];
int disa[maxn];
void discrete(){
	for(int i=1;i<=n;i++) b[i]=a[i];
	sort(b+1,b+1+n);
	int tmp=unique(b+1,b+1+n)-b-1;
	for(int i=1;i<=n;i++){
		disa[i]=lower_bound(b+1,b+1+tmp,a[i])-b;
	}	
}

int amod[maxn];
int adiv[maxn];
int cnt[maxn];
int check(int mid){
	for(int i=1;i<=n;i++){
		cnt[disa[i]]=0;
	}
	int l=1,r=mid;
	bool flag=true;
	for(int i=l;i<=r;i++){
		cnt[disa[i]]++;
		if(cnt[disa[i]]>1) flag=false;
	}
	if(flag&&T1.query_max(l,r,1)==T1.query_min(l,r,1) && T2.query_max(l,r,1)-T2.query_min(l,r,1)+1<=(r-l+1)+k){
		return l;
	}
	
	for(int i=2;i+mid-1<=n;i++){
		l=i,r=i+mid-1;
		cnt[disa[l-1]]--;
		cnt[disa[r]]++;
		if(cnt[disa[l-1]]>1||cnt[disa[r]]>1) continue;
		if(T1.query_max(l,r,1)==T1.query_min(l,r,1) && T2.query_max(l,r,1)-T2.query_min(l,r,1)+1<=(r-l+1)+k){
			return i;
		}
	}
	
	return 0;
}


void special_work(){
	int len=0;
	int maxl=0;
	int begin=0;
	for(int i=1;i<=n;i++){
		if(a[i]==a[i-1]&&i!=1){
			len++;
			if(len>maxl){
				maxl=len;
				begin=i-len+1;
			} 
		}else{
			len=1;
			if(len>maxl){
				maxl=len;
				begin=i-len+1;
			}  
		}
	}
	qprint(begin);
	putchar(' ');
	qprint(begin+maxl-1); 
//	for(int i=begin;i<=begin+len-1;i++){
//		qprint(a[i]);
//		putchar(' ');
//	}
}

int main(){
	qread(n);
	qread(k);
	qread(d);
	
	
	for(int i=1;i<=n;i++){
		qread(a[i]);
		if(d!=0){
			amod[i]=abs(a[i]%d);
			adiv[i]=a[i]/d;
		}
	}
	
	if(d==0){
		special_work();//d=0时a[i]%d会炸，特判 
		return 0;
	}
	
	discrete();
	T1.build(1,n,amod,1);
	T2.build(1,n,adiv,1);
	
	int l=1,r=n;
	int ans=0;
	int mid;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	
	int pos=check(ans);
	qprint(pos);
	putchar(' ');
	qprint(pos+ans-1);
//	for(int i=pos;i<=pos+ans-1;i++){
//		qprint(a[i]);
//		putchar(' ');
//	}
}
