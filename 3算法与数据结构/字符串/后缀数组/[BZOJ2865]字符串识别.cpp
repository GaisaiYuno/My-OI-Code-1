#include<iostream>
#include<cstdio>
#include<cstring> 
#define INF 0x3f3f3f3f
#define maxn 500000
#define maxs 128 
using namespace std;
inline void qprint(int x){
	if(x<0){
		putchar('-');
		qprint(-x);
	}else if(x==0){
		putchar('0');
		return;
	}else{
		if(x>=10) qprint(x/10);
		putchar('0'+x%10);
	}
}
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

struct segment_tree{
	struct node{
		int l;
		int r;
		int mark;//永久化标记	
	}tree[maxn*4+5];
	void build(int l,int r,int pos){
		tree[pos].l=l;
		tree[pos].r=r;
		tree[pos].mark=INF;
		if(l==r) return;
		int mid=(l+r)>>1;
		build(l,mid,pos<<1);
		build(mid+1,r,pos<<1|1);
	}
	void update(int L,int R,int val,int pos){
		if(L<=tree[pos].l&&R>=tree[pos].r){
			tree[pos].mark=min(tree[pos].mark,val);
			return;
		}
		//标记永久化，不用push_down
		int mid=(tree[pos].l+tree[pos].r)>>1;
		if(L<=mid) update(L,R,val,pos<<1);
		if(R>mid) update(L,R,val,pos<<1|1); 
	}
	int query(int qpos,int pos){
		if(tree[pos].l==tree[pos].r){
			return tree[pos].mark;
		}
		int mid=(tree[pos].l+tree[pos].r)>>1;
		if(qpos<=mid) return min(tree[pos].mark,query(qpos,pos<<1));
		else return min(tree[pos].mark,query(qpos,pos<<1|1));
	} 
}T1,T2;

int n;
char s[maxn+5];
int main(){
#ifdef LOCAL
//	freopen("1.in","r",stdin);
//	freopen("1.ans","w",stdout);
#endif
	scanf("%s",s+1);
	n=strlen(s+1);
	get_height(s,n,maxs);
	T1.build(1,n,1);
	T2.build(1,n,1);
	for(int i=1;i<=n;i++){
		int len=max(height[rk[i]],height[rk[i]+1])+1;
		if(i+len-1<=n) T1.update(i,i+len-1,len,1);
		if(i+len-1<n) T2.update(i+len,n,-i+1,1);//第j位的答案是j-i+1,不存储j,只存储min(-i+1) 
	} 
	for(int i=1;i<=n;i++){
		qprint(min(T1.query(i,1),T2.query(i,1)+i));
		putchar('\n'); 
	}
} 


