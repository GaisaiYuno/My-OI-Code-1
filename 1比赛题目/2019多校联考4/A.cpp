#include<iostream>
#include<cstdio>
#define maxb 31
#define maxn 200000
#define maxs 6400000
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

int n,q;
int a[maxn+5];

struct persist_trie{
	int sz[maxs+5];
	int root[maxn+5];
	int son[maxs+5][2];
	int ptr=0;
	void insert(int pos,int val){
		int now=root[pos]=++ptr;
		int last=root[pos-1];
		for(int i=maxb;i>=0;i--){
			sz[now]=sz[last]+1;
			int k=(val>>i)&1;
			son[now][k]=++ptr;
			son[now][k^1]=son[last][k^1];
			now=son[now][k];
			last=son[last][k];
		} 
		sz[now]=sz[last]+1;
	} 
	int query(int l,int r,int val){
		int now=root[r];
		int last=root[l-1];
		int ans=0;
		for(int i=maxb;i>=0;i--){
			int k=(val>>i)&1;
			int lsz=sz[son[now][k^1]]-sz[son[last][k^1]];
			if(lsz){
				now=son[now][k^1];
				last=son[last][k^1];
				ans=ans*2+1;
			}else{
				now=son[now][k];
				last=son[last][k];
				ans=ans*2;
			}
		}
		return ans;
	}
}T;

int main(){
// 	freopen("1.in","r",stdin);
// 	freopen("1.ans","w",stdout);
	int l,r,x;
	qread(n);
	qread(q);
	for(int i=1;i<=n;i++){
		qread(a[i]);
		T.insert(i,a[i]);
	}
	for(int i=1;i<=q;i++){
		qread(x);
		qread(l);
		qread(r);
		l++;
		r++;
		qprint(T.query(l,r,x));
		putchar('\n');
	}
}

