#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 100000
#define maxs 128
#define maxlogn 20
#define INF 0x3f3f3f3f
using namespace std;
int n,m;
char in[maxn+5];

void rsort(int *ans,int *fi,int *se,int n,int m){
	static int buck[maxn+5];
	for(int i=0;i<=m;i++) buck[i]=0;
	for(int i=1;i<=n;i++) buck[fi[i]]++;
	for(int i=1;i<=m;i++) buck[i]+=buck[i-1];
	for(int i=n;i>=1;i--) ans[buck[fi[se[i]]]--]=se[i];
}
int sa[maxn+5],rk[maxn+5],height[maxn+5];
void suffix_sort(char *s,int n,int m){
	static int se[maxn+5];
	for(int i=1;i<=n;i++){
		rk[i]=s[i];
		se[i]=i;
	}
	rsort(sa,rk,se,n,m);
	for(int k=1;k<=n;k*=2){
		int p=0;
		for(int i=n-k+1;i<=n;i++) se[++p]=i;
		for(int i=1;i<=n;i++) if(sa[i]>k) se[++p]=sa[i]-k;
		rsort(sa,rk,se,n,m);
		swap(rk,se);
		rk[sa[1]]=1;
		p=1;
		for(int i=2;i<=n;i++){
			if(se[sa[i-1]]==se[sa[i]]&&se[sa[i-1]+k]==se[sa[i]+k]) rk[sa[i]]=p;
			else rk[sa[i]]=++p;
		}
		if(p==n) break;
		m=p;
	}
}
void get_height(char *s,int n,int m){
	suffix_sort(s,n,m);
	for(int i=1;i<=n;i++) rk[sa[i]]=i;
	int k=0;
	for(int i=1;i<=n;i++){
		if(k) k--;
		int j=sa[rk[i]-1];
		while(s[i+k]==s[j+k]) k++;
		height[rk[i]]=k;
	}
}

struct sparse_table{
	int log2[maxn+5];
	int st[maxn+5][maxlogn+5];
	void ini(int *a,int n){
		log2[0]=-1;
		for(int i=1;i<=n;i++) log2[i]=log2[i>>1]+1;
		memset(st,0x3f,sizeof(st));
		for(int i=1;i<=n;i++) st[i][0]=a[i];
		for(int j=1;(1<<j)<=n;j++){
			for(int i=1;i+(1<<(j-1))-1<=n;i++){
				st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
			}
		}
	}
	int query(int l,int r){
		if(l>r) return INF;
		int k=log2[r-l+1];
		return min(st[l][k],st[r-(1<<k)+1][k]);
	}
}St;
int lcp(int x,int y){
	//从x位置开始的后缀,与从y位置开始的后缀的lcp 
	if(rk[x]>rk[y]) swap(x,y);
	return St.query(rk[x]+1,rk[y]); 
}
int find_lbound(int c,int val){
	//找到height数组上从rk[c]往左值>=val的区间
	int l=1,r=rk[c];
	int mid,ans=r;
	while(l<=r){
		mid=(l+r)>>1;
		if(St.query(mid+1,rk[c])>=val){//注意这里+1,因为求lcp求的是[rk[x]+1,rk[y]] 
			ans=mid;
			r=mid-1;
		}else l=mid+1;
	} 
	return ans;
}
int find_rbound(int c,int val){
	//找到height数组上从rk[c]往右值>=val的区间
	int l=rk[c],r=n;
	int mid,ans=l;
	while(l<=r){
		mid=(l+r)>>1;
		if(St.query(rk[c],mid)>=val){
			ans=mid;
			l=mid+1;
		}else r=mid-1;
	} 
	return ans;
}

struct persist_segment_tree{
#define lson(x) (tree[x].ls)
#define rson(x) (tree[x].rs)
	struct node{
		int ls;
		int rs;
		int cnt;
	}tree[maxn*maxlogn+5];
	int root[maxn+5];
	int ptr;
	inline void push_up(int x){
		tree[x].cnt=tree[lson(x)].cnt+tree[rson(x)].cnt;
	} 
	void insert(int &x,int last,int val,int l,int r){
		x=++ptr;
		tree[x]=tree[last];
		if(l==r){
			tree[x].cnt++;
			return;
		}
		int mid=(l+r)>>1;
		if(val<=mid) insert(lson(x),lson(last),val,l,mid);
		else insert(rson(x),rson(last),val,mid+1,r);
		push_up(x);
	}
	int query(int x,int L,int R,int l,int r){
		if(L<=l&&R>=r) return tree[x].cnt;
		int mid=(l+r)>>1;
		int ans=0;
		if(L<=mid) ans+=query(lson(x),L,R,l,mid);
		if(R>mid) ans+=query(rson(x),L,R,mid+1,r);
		return ans;
	}
	void ini(int *a,int n){
		for(int i=1;i<=n;i++){
			insert(root[i],root[i-1],a[i],0,n);
		}
	}
	int Query(int pl,int pr,int vl,int vr){
		//查询数组从[pl,pr]处于[vl,vr]中的值的数量 
//		printf("d:%d\n",query(root[pr],vl,vr,0,n));
//		printf("d:%d\n",query(root[pl-1],vl,vr,0,n));
		return query(root[pr],vl,vr,0,n)-query(root[pl-1],vl,vr,0,n);
	}
#undef lson
#undef rson
}Tr;

bool check(int mid,int a,int b,int c,int d){
	if(mid==0) return 1; 
	int lb=find_lbound(c,mid);
	int rb=find_rbound(c,mid);
	if(Tr.Query(a,b-mid+1,lb,rb)>0) return 1;
	else return 0; 
}
int get_ans(int a,int b,int c,int d){
	int l=0,r=min(b-a+1,d-c+1);
	int mid,ans=l;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid,a,b,c,d)){
			ans=mid;
			l=mid+1;
		}else r=mid-1;
	}
	return ans;
}

int main(){
	int a,b,c,d;
	scanf("%d %d",&n,&m);
	scanf("%s",in+1);
	get_height(in,n,maxs);
	St.ini(height,n);
	Tr.ini(rk,n);
	for(int i=1;i<=m;i++){
		scanf("%d %d %d %d",&a,&b,&c,&d);
		printf("%d\n",get_ans(a,b,c,d)); 
	} 
}
/*
5 5
aaaaa
1 5 1 1
*/ 

